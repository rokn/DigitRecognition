#ifndef SIGMOID_ACTIVATION_HPP
#define SIGMOID_ACTIVATION_HPP

#include "activation_function.hpp"

namespace recognize
{
	class SigmoidActivation : public ActivationFunction
	{
		public:
			double Activate(double input);
			double Gradient(double input);
	};
}

#endif /* SIGMOID_ACTIVATION_HPP */
