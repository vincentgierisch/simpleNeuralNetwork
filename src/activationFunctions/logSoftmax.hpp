#ifndef LOG_SOFTMAX_HPP
#define LOG_SOFTMAX_HPP

#include "../activationFunction.hpp"
#include <eigen3/Eigen/Dense>

#include <cmath>

class LogSoftmax : public ActivationFunction {
    public: 
        LogSoftmax() {};
        virtual Eigen::Vector<float, Eigen::Dynamic> calculate(const Eigen::Vector<float, Eigen::Dynamic>& neurons) override {
            float maxVal = neurons.maxCoeff();

            Eigen::Vector<float, Eigen::Dynamic> stabilizedNeurons = neurons.array() - maxVal;
            Eigen::Vector<float, Eigen::Dynamic> expNeurons = stabilizedNeurons.array().exp();
            
            float logSumExp = std::log(expNeurons.sum());

            return stabilizedNeurons.array() - logSumExp;
        };
        virtual ~LogSoftmax() = default;
};
#endif
