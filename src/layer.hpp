#ifndef NETWORK_LAYER_HPP
#define NETWORK_LAYER_HPP

#include <eigen3/Eigen/Dense>

#include "activationFunction.hpp"
#include <iostream>

class Layer {
    private:
        unsigned int _size;
    public:
        Eigen::Vector<float, Eigen::Dynamic> bias;
        ActivationFunction* activationFunction;
        unsigned const int getSize() {return this->_size;};

        Layer() {};
        Layer(unsigned int size, ActivationFunction*);
        ~Layer();

        // copy constructor
        Layer(const Layer& obj);
};
#endif
