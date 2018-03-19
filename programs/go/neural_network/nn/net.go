package nn

import (

)

const (
    STARTING_BIAS float64 = -1.0
)

type Net struct {
    layers []Layer
    error float64
    recent_average_error float64
    recent_average_smoothing_factor float64
}

func (n Net) New(topology []int) {
    n.recent_average_smoothing_factor = 100

    num_layers := len(topology)
    for layer_num := 0; layer_num < num_layers; layer_num++ {
        // Make a new layer
        var layer Layer

        // If this is the last layer, there aren't any outputs.
        if layer_num == len(topology) {
            num_outputs := 0
        } else {
            num_outputs := topology[layer_num + 1]
        }

        // Fill this new layer with neurons, including bias.
        for neuron_num := 0; neuron_num < topology[layer_num]; neuron_num++ {
            layer = append(layer, Neuron.New(num_outputs, neuron_num))
            fmt.Printf("Made a neuron at layer %d, index %d\n", layer_num, neuron_num)
        }

        // Create a bias neuron and add it to the end of the layer
        bias_neuron := NewNeuron(num_outputs, topology[layer_num])
        bias_neuron.output = -1.0
        layer = append(layer, bias_neuron)

        // Add this layer to the network!
        n.layers = append(n.layers, layer)
    }
}
