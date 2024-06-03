#include "layer.hpp"

Layer::Layer(unsigned int size, ActivationFunction* activationFunction) {
    this->_size = size;
    this->activationFunction = activationFunction;
}


Layer::~Layer() {
    if (this->activationFunction != nullptr) {
        /* delete this->activationFunction; */
    }
}

Layer::Layer(const Layer& obj) {
    this->_size = obj._size;
    this->activationFunction = obj.activationFunction; 
}
