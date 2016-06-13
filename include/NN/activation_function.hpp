#ifndef ACTIVATION_FUNCTION_HPP
#define ACTIVATION_FUNCTION_HPP

namespace recognize
{
	class ActivationFunction
	{
		public:
			virtual double Activate(double input) = 0;
	};
}

#endif /* ACTIVATION_FUNCTION_HPP */
