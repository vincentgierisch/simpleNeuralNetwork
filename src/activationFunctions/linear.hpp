#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "../activationFunction.hpp"
#include <eigen3/Eigen/Dense>

class Linear : public ActivationFunction {
    public: 
        Linear() {};
        virtual Eigen::Vector<float, Eigen::Dynamic> calculate(const Eigen::Vector<float, Eigen::Dynamic>& neurons) override {
            return neurons;
        };
        virtual ~Linear() = default;
};
#endif
