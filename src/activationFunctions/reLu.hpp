#ifndef RELU_HPP
#define RELU_HPP

#include "../activationFunction.hpp"
#include <eigen3/Eigen/Dense>

#include <iostream>

class ReLu : public ActivationFunction {
    public: 
        ReLu() {};
        virtual Eigen::Vector<float, Eigen::Dynamic> calculate(const Eigen::Vector<float, Eigen::Dynamic>& neurons) override {
            return neurons.cwiseMax(0.0f); 
        };
        virtual ~ReLu() = default;
};
#endif
