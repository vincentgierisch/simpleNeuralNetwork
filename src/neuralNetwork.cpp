#include "neuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(std::vector<NetworkLayer> layers): _layers(layers) {
    for (auto& layer : this->_layers) {
        Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> layerWeights;
        // maybe column should be size of next layer?
        layerWeights.resize(layer.getSize(), layer.getSize());
        layerWeights.setZero();
        this->_weights.push_back(layerWeights);
    }
}

Eigen::Vector<float, Eigen::Dynamic> NeuralNetwork::forwardPropagation(Eigen::Vector<float, Eigen::Dynamic>& input) {
    Eigen::Vector<float, Eigen::Dynamic> result = input;
    for (long unsigned int i = 0; i < this->_layers.size(); ++i) {
        // calculate matrix
        result = this->_layers.at(i).activationFunction->calculate(this->_weights.at(i) * result + this->_layers.at(i).bias); 
    }
    return result;
}
