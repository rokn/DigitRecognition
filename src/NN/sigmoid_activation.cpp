#include "NN/sigmoid_activation.hpp"
#include <cmath>

namespace recognize
{
	double SigmoidActivation::Activate(double input)
	{
		return 1 / (1 + exp(-input));
	}
}

