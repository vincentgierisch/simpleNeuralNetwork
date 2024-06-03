#include <iostream>
#include <ctime>

#include "activationFunction.hpp"
#include "activationFunctions/reLu.hpp"
#include "activationFunctions/linear.hpp"
#include "activationFunctions/logSoftmax.hpp"

// testing purposes
#include <vector>
#include <eigen3/Eigen/Dense>
#include "neuralNetwork.hpp"
#include "layer.hpp"

int main() {
    std::cout << "Hello World" << std::endl;
    // neural network class should contain a sequence of layers (and activation functions)
    // so basically a wrapper for a list 


    std::srand(static_cast<unsigned int>(std::time(0)));

    ActivationFunction* reLu = new ReLu();
    ActivationFunction* linear = new Linear();
    ActivationFunction* logSoftmax = new LogSoftmax();

    std::vector<Layer> layers = {Layer(784, reLu),  Layer(128, reLu), Layer(64, reLu), Layer(10, logSoftmax)};
    NeuralNetwork* nn = new NeuralNetwork(layers);
    Eigen::Vector<float, Eigen::Dynamic> input;
    input.resize(784);
    input.setRandom(784, 1);
    std::cout << nn->forwardPropagation(input) << std::endl; 
}
