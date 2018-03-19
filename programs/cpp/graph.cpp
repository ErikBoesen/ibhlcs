#include <iostream>
#include <vector>

class Node {
public:
    std::vector<int> paths;
};

class Graph {
public:
    std::vector<Node> nodes;
    Graph(std::vector<Node> nodes) {
        this->nodes = nodes;
    }
    int shortest_path(int start, int end) {
        return 0;
    }
};

void print_graph(Graph graph) {
    for (int node = 0; node < graph.nodes.size(); node++) {
        std::cout << "Node " << node << std::endl;
        for (int path = 0; path < graph.nodes[node].paths.size(); path++)
            std::cout << "  -> " << path << ": " << graph.nodes[node].paths[path] << std::endl;
    }
}

int main() {
    std::cout << "How many nodes? ";
    int num_nodes;
    std::cin >> num_nodes;

    std::vector<Node> nodes;

    for (int start = 0; start < num_nodes; ++start) {
        Node node;
        for (int end = 0; end < num_nodes; ++end) {
            if (start == end) {
                // If the start and end are the same, distance is 0.
                node.paths.push_back(0);
            } else if (end <= nodes.size() && start <= nodes[end].paths.size() && nodes[end].paths[start]) {
                // This path has already been input from the other direction, so just use what we had there.
                node.paths.push_back(nodes[end].paths[start]);
            } else {
                // Take input to get this distance.
                std::cout << "Distance from " << start << " to " << end << ": ";
                int distance;
                std::cin >> distance;
                node.paths.push_back(distance);
            }
        }
        nodes.push_back(node);
    }

    Graph g(nodes);
    print_graph(g);
    int start, end;
    std::cout << std::endl << "Start node: ";
    std::cin >> start;
    std::cout << "End node: ";
    std::cin >> end;

    std::cout << "Shortest path is " << g.shortest_path(start, end) << " units long." << std::endl;
}
