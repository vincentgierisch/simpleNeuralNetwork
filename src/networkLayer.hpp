#ifndef NETWORK_LAYER_HPP
#define NETWORK_LAYER_HPP

#include <eigen3/Eigen/Dense>

#include "activationFunction.hpp"

class NetworkLayer {
    private:
        unsigned int _size;
    public:
        Eigen::Vector<float, Eigen::Dynamic> bias;
        ActivationFunction* activationFunction;
        unsigned int getSize() {return this->_size;};

        NetworkLayer() {};
        NetworkLayer(unsigned int size);
};
#endif
