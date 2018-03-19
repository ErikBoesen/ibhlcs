package net

import (
    "math/rand"
    "fmt"
    "errors"
)

const (
    ETA float32 = 0.15 // overall net learning rate
    ALPHA float32 = 0.5 // momentum, multiplier of last deltaWeight, [0.0..n]
)

type Connection struct {
	weight float32
    deltaWeight float32
}

type Neuron struct {
	outputVal float32
	outputWeights []Connection
	myIndex uint
	gradient float32
}

type Layer []Neuron // Maybe needs to come first?

func (n Neuron) SetOutputValue(val float32) {
    n.outputVal = val
}
func (n Neuron) OutputValue() float32 {
    return n.outputVal
}

func (n Neuron) UpdateInputWeights(previous_layer *Layer) {
	// The weights to be updated are in the Connection container
	// in the nuerons in the preceding layer

	for i := 0; i < len(previous_layer); i++ {
		neuron := &previous_layer[i]
		oldDeltaWeight := neuron.outputWeights[n.myIndex].deltaWeight

		newDeltaWeight :=
				// Individual input, magnified by the gradient and train rate:
				ETA
				* neuron.OutputValue()
				* n.gradient
				// Also add momentum = a fraction of the previous delta weight
				+ ALPHA
				* oldDeltaWeight
		neuron.outputWeights[n.myIndex].deltaWeight = newDeltaWeight
		neuron.outputWeights[n.myIndex].weight += newDeltaWeight
	}
}
func (n Neuron) SumDOW(next_layer *Layer) float32 {
	sum = 0.0

	// Sum our contributions of the errors at the nodes we feed
	for i := 0; i < len(next_layer) - 1; i++ {
		sum += n.outputWeights[i].weight * next_layer[i].gradient
	}

	return sum
}

func (n Neuron) RandomWeight() float32 {
    return rand.Float32()
}

func (n Neuron) CalculateHiddenGradients(next_layer *Layer) {
	dow := SumDOW(next_layer)
	n.gradient = dow * n.TransferFunctionDerivative(n.outputVal)
}
func (n Neuron) CalculateOutputGradients(targets float32) {
	delta := targets - n.outputVal
	n.gradient = delta * n.TransferFunctionDerivative(n.outputVal)
}

func (n Neuron) TransferFunction(x float32) float32 {
	// tanh - output range [-1.0..1.0]
	return tanh(x)
}

func (n Neuron) TransferFunctionDerivative(x float32) float32 {
	// tanh derivative
	return 1.0 - x * x
}

func (n Neuron) FeedForward(previous_layer *Layer) {
	sum = 0.0

	// Sum the previous layer's outputs (which are our inputs)
    // Include the bias node from the previous layer.

	for i := 0; n < len(previous_layer); n++ {
		sum += previous_layer[n].OutputValue() *
				 previous_layer[n].outputWeights[n.myIndex].weight
	}

	n.outputVal = n.TransferFunction(sum)
}

func (n Neuron) New(numOutputs uint, myIndex uint) {
	for c := 0; c < numOutputs; c++ {
		append(n.outputWeights, Connection())
		n.outputWeights[len(n.outputWeights) - 1].weight = RandomWeight()
	}

	n.myIndex = myIndex
}

type Net struct {
	layers []Layer
	error float32
	recentAverageError float32
	recentAverageSmoothingFactor float32
}

func (n Net) getRecentAverageError() float32 {
    return n.recentAverageError
}

func (n Net) getResults(results *[]float32) {
	results = results[:0] // Maybe try a nicer way of doing this like nil?

	for i := 0; i < len(n.layers[len(n.layers) - 1]) - 1; i++ {
		append(results, n.layers.back()[i].OutputValue())
	}
}

func (n Net) Backpropogate(targets *[]float32) {
	// Calculate overal net error (RMS of output neuron errors)

	Layer &outputLayer = n.layers[len(n.layers) - 1]
	n.error = 0.0

	for i := 0; n < len(outputLayer) - 1; n++ {
		delta := targets[n] - outputLayer[n].OutputValue()
		n.error += delta *delta
	}
	n.error /= len(outputLayer) - 1 // get average error squared
	n.error = sqrt(n.error) // RMS

	// Implement a recent average measurement:

	n.recentAverageError = (n.recentAverageError * n.recentAverageSmoothingFactor + n.error) / (n.recentAverageSmoothingFactor + 1.0)
	// Calculate output layer gradients

	for i := 0; n < len(outputLayer) - 1; n++ {
		outputLayer[n].CalculateOutputGradients(targets[n])
	}
	// Calculate gradients on hidden layers

	for layer_num := len(n.layers) - 2; layer_num > 0; layer_num-- {
		Layer &hidden_layer = n.layers[layer_num]
		Layer &next_layer = n.layers[layer_num + 1]

		for i := 0; n < len(hidden_layer); n++ {
			hidden_layer[n].CalculateHiddenGradients(next_layer)
		}
	}

	// For all layers from outputs to first hidden layer,
	// update connection weights

	for layer_num := len(n.layers) - 1; layer_num > 0; layer_num-- {
		Layer &layer = n.layers[layer_num]
		Layer &previous_layer = n.layers[layer_num - 1]

		for i := 0; i < len(layer) - 1; i++ {
			layer[i].UpdateInputWeights(previous_layer)
		}
	}
}

func (n Net) FeedForward(inputs *[]float32) {
	// Check the num of inputs equal to neuron_num, expect bias
	if len(inputs) != len(n.layers[0]) - 1 {
        errors.New("number of inputs not equal to neuron_num")
    }

	// Assign (latch) the input values into the input neurons
	for i := 0; i < len(inputs); i++ {
		n.layers[0][i].SetOutputValue(inputs[i])
	}

	// Forward propagate
	for layer_num := 1; layer_num < len(n.layers); layer_num++ {
		previous_layer := n.layers[layer_num - 1]
		for i := 0; i < len(n.layers[layer_num]) - 1; i++ {
			n.layers[layer_num][n].FeedForward(previous_layer)
		}
	}
}
func (n Net) New(topology *[]uint) {
    n.recentAverageSmoothingFactor = 100.0 // Number of training samples to average over
	num_layers := len(topology)
	for layer_num := 0; layer_num < num_layers; layer_num++ {
		append(n.layers, Layer())
		// numOutputs of layer[i] is the numInputs of layer[i+1]
		// numOutputs of last layer is 0
        if layer_num == len(topology) - 1 {
            numOutputs := 0
        } else {
            numOutputs := topology[layer_num + 1]
        }

		// We have made a new Layer, now fill it with neurons, and
		// add a bias neuron to the layer:
		for neuron_num := 0; neuron_num <= topology[layer_num]; neuron_num++ {
			append(n.layers[len(n.layers) - 1], Neuron.New(numOutputs, neuron_num))
			fmt.Println("Made a Neuron!")
		}

		// Force the bias node's output value to -1.0. It's the last neuron created above
        // TODO: dear god please no
		n.layers[len(n.layers) - 1][n.layers[len(n.layers[len(n.layers) - 1]) - 1]].SetOutputValue(-1.0)
	}
}
