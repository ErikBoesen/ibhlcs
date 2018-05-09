#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>
#include "net.h"
#include "reader.h"

using namespace std;

void print_vector(vector<double> &v) {
	cout << '[';
	for (unsigned i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1) cout << " ";
	}
	cout << ']';
}
int main() {
	TrainingData reader("training_data.txt");
	vector<unsigned> topology;

	reader.getTopology(topology);

	Net network(topology);

	vector<double> inputs, targets, results;

	cout << fixed << setprecision(0);

	for (int epoch = 0; !reader.isEof(); ++epoch) {
		// Get new input data and feed it forward:
		if (reader.getNextInputs(inputs) != topology[0]) break;

		network.feedForward(inputs);

		// Collect the net's actual results:
		network.getResults(results);

		// Show correct outputs
		reader.getTargetOutputs(targets);
		assert(targets.size() == topology.back());

		// Backpropogate!
		network.backProp(targets);

		cout << "E" << epoch << " / ";
		print_vector(inputs);
		cout << " > ";
		cout << setprecision(4);
		print_vector(results);
		cout << setprecision(0);
		cout << " (targets ";
		print_vector(targets);
		cout << "), (error ";
		cout << ")" << endl;
	}
}
