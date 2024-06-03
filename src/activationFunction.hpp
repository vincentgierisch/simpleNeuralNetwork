#ifndef ACTIVATION_FUNCTION_HPP
#define ACTIVATION_FUNCTION_HPP

#include <eigen3/Eigen/Dense>

class ActivationFunction {
    private:

    public:
        /* ActivationFunction() {}; */
        virtual Eigen::Vector<float, Eigen::Dynamic> calculate(const Eigen::Vector<float, Eigen::Dynamic>&) = 0;
        virtual ~ActivationFunction() = default;
};
#endif
