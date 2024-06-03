#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include <vector>
#include <string>
#include <eigen3/Eigen/Dense>
#include "layer.hpp"

#include <iostream>

class NeuralNetwork {
    private:
        std::vector<Layer> _layers;
        std::vector<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>> _weights;
        std::vector<Eigen::Vector<float, Eigen::Dynamic>> _biases;
    public:
        NeuralNetwork(std::vector<Layer>& layers);

        /* void load(std::string path); */
        /* void save(std::string path); */
        

        Eigen::Vector<float, Eigen::Dynamic> forwardPropagation(Eigen::Vector<float, Eigen::Dynamic>&);

        ~NeuralNetwork(){};
};
#endif
