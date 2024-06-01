#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include <vector>
#include <string>
#include <eigen3/Eigen/Dense>
#include "networkLayer.hpp"

class NeuralNetwork {
    private:
        std::vector<NetworkLayer> _layers;
        std::vector<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>> _weights;
    public:
        NeuralNetwork(std::vector<NetworkLayer> layers);

        void load(std::string path);
        void save(std::string path);
        

        Eigen::Vector<float, Eigen::Dynamic> forwardPropagation(Eigen::Vector<float, Eigen::Dynamic>&);

        ~NeuralNetwork();
};
#endif
