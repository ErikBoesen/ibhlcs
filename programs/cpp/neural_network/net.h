#pragma once
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

struct Connection {
	double weight;
	double deltaWeight;
};

class Neuron;

typedef vector<Neuron> Layer;

class Neuron {
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void setOutputVal(double val) { this->outputVal = val; }
	double getOutputVal(void) const { return this->outputVal; }
	void feedForward(const Layer &prevLayer);
	void calcOutputGradients(double targetVals);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer);
private:
	static double eta; // [0.0...1.0] overall net training rate
	static double alpha; // [0.0...n] multiplier of last weight change [momentum]
	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
	// randomWeight: 0 - 1
	static double randomWeight(void) { return rand() / double(RAND_MAX); }
	double sumDOW(const Layer &nextLayer) const;
	double outputVal;
	vector<Connection> outputWeights;
	unsigned myIndex;
	double gradient;
};

double Neuron::eta = 0.15; // overall net learning rate
double Neuron::alpha = 0.5; // momentum, multiplier of last deltaWeight, [0.0..n]


void Neuron::updateInputWeights(Layer &prevLayer) {
	// The weights to be updated are in the Connection container
	// in the nuerons in the preceding layer

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.outputWeights[this->myIndex].deltaWeight;

		double newDeltaWeight =
				// Individual input, magnified by the gradient and train rate:
				eta
				* neuron.getOutputVal()
				* this->gradient
				// Also add momentum = a fraction of the previous delta weight
				+ alpha
				* oldDeltaWeight;
		neuron.outputWeights[this->myIndex].deltaWeight = newDeltaWeight;
		neuron.outputWeights[this->myIndex].weight += newDeltaWeight;
	}
}
double Neuron::sumDOW(const Layer &nextLayer) const {
	double sum = 0.0;

	// Sum our contributions of the errors at the nodes we feed

	for (unsigned n = 0; n < nextLayer.size() - 1; ++n) {
		sum += this->outputWeights[n].weight * nextLayer[n].gradient;
	}

	return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer) {
	double dow = sumDOW(nextLayer);
	this->gradient = dow * Neuron::transferFunctionDerivative(this->outputVal);
}
void Neuron::calcOutputGradients(double targetVals) {
	double delta = targetVals - this->outputVal;
	this->gradient = delta * Neuron::transferFunctionDerivative(this->outputVal);
}

double Neuron::transferFunction(double x) {
	// tanh - output range [-1.0..1.0]
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x) {
	// tanh derivative
	return 1.0 - x * x;
}

void Neuron::feedForward(const Layer &prevLayer) {
	double sum = 0.0;

	// Sum the previous layer's outputs (which are our inputs)
    // Include the bias node from the previous layer.

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		sum += prevLayer[n].getOutputVal() *
				 prevLayer[n].outputWeights[this->myIndex].weight;
	}

	this->outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex) {
	for (unsigned c = 0; c < numOutputs; ++c){
		this->outputWeights.push_back(Connection());
		this->outputWeights.back().weight = randomWeight();
	}

	this->myIndex = myIndex;
}

class Net {
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVals);
	void backProp(const vector<double> &targetVals);
	void getResults(vector<double> &resultVals) const;
	double getRecentAverageError(void) const { return this->recentAverageError; }

private:
	vector<Layer> layers;
	double error;
	double recentAverageError;
	static double recentAverageSmoothingFactor;
};

double Net::recentAverageSmoothingFactor = 100.0; // Number of training samples to average over

void Net::getResults(vector<double> &resultVals) const {
	resultVals.clear();

	for (unsigned n = 0; n < this->layers.back().size() - 1; ++n) {
		resultVals.push_back(this->layers.back()[n].getOutputVal());
	}
}

void Net::backProp(const std::vector<double> &targetVals) {
	// Calculate overal net error (RMS of output neuron errors)

	Layer &outputLayer = this->layers.back();
	this->error = 0.0;

	for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		this->error += delta *delta;
	}
	this->error /= outputLayer.size() - 1; // get average error squared
	this->error = sqrt(this->error); // RMS

	// Implement a recent average measurement:

	this->recentAverageError =
			(this->recentAverageError * this->recentAverageSmoothingFactor + this->error)
			/ (this->recentAverageSmoothingFactor + 1.0);
	// Calculate output layer gradients

	for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
		outputLayer[n].calcOutputGradients(targetVals[n]);
	}
	// Calculate gradients on hidden layers

	for (unsigned layerNum = this->layers.size() - 2; layerNum > 0; --layerNum) {
		Layer hiddenLayer = this->layers[layerNum];
		Layer nextLayer = this->layers[layerNum + 1];

		for (unsigned n = 0; n < hiddenLayer.size(); ++n) {
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}

	// For all layers from outputs to first hidden layer,
	// update connection weights

	for (unsigned layerNum = this->layers.size() - 1; layerNum > 0; --layerNum) {
		Layer &layer = this->layers[layerNum];
		Layer &prevLayer = this->layers[layerNum - 1];

		for (unsigned n = 0; n < layer.size() - 1; ++n) {
			layer[n].updateInputWeights(prevLayer);
		}
	}
}

void Net::feedForward(const vector<double> &inputVals) {
	// Check the num of inputVals euqal to neuronnum expect bias
	assert(inputVals.size() == this->layers[0].size() - 1);

	// Assign {latch} the input values into the input neurons
	for (unsigned i = 0; i < inputVals.size(); ++i){
		this->layers[0][i].setOutputVal(inputVals[i]);
	}

	// Forward propagate
	for (unsigned layerNum = 1; layerNum < this->layers.size(); ++layerNum){
		Layer &prevLayer = this->layers[layerNum - 1];
		for (unsigned n = 0; n < this->layers[layerNum].size() - 1; ++n){
			this->layers[layerNum][n].feedForward(prevLayer);
		}
	}
}
Net::Net(const vector<unsigned> &topology) {
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
		this->layers.push_back(Layer());
		// numOutputs of layer[i] is the numInputs of layer[i+1]
		// numOutputs of last layer is 0
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 :topology[layerNum + 1];

		// We have made a new Layer, now fill it with neurons, and
		// add a bias neuron to the layer:
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
			this->layers.back().push_back(Neuron(numOutputs, neuronNum));
			cout << "Mad a Neuron!" << endl;
		}

		// Force the bias node's output value to 1.0. It's the last neuron created above
		this->layers.back().back().setOutputVal(-1.0);
	}
}
