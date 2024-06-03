#include "neuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(std::vector<Layer>& layers): _layers(layers) {
    for (long unsigned int i = 0; i < this->_layers.size()-1; ++i) {
        Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> layerWeights;
        unsigned int columns = this->_layers.at(i).getSize();

        unsigned int rows = this->_layers.at(i+1).getSize();
        // maybe column should be size of next layer?
        layerWeights.resize(rows, columns);
        // Initialize the matrix with random values between -0.25 and 0.25
        layerWeights = Eigen::MatrixXf::Random(rows, columns) * 0.25;
        this->_weights.push_back(layerWeights);

        Eigen::Vector<float, Eigen::Dynamic> bias;
        bias.resize(rows);
        bias.setZero();
        this->_biases.push_back(bias);
    }
}

Eigen::Vector<float, Eigen::Dynamic> NeuralNetwork::forwardPropagation(Eigen::Vector<float, Eigen::Dynamic>& input) {
    Eigen::Vector<float, Eigen::Dynamic> result = input;
    for (long unsigned int i = 0; i < this->_layers.size()-1; ++i) {
        // calculate matrix
        result = this->_layers.at(i).activationFunction->calculate(this->_weights.at(i) * result + this->_biases.at(i)); 
    }
    // for last layer just apply the activation function
    return this->_layers.at(this->_layers.size()-1).activationFunction->calculate(result);
}
