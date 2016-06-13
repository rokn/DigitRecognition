#ifndef NEURAL_NET_HPP
#define NEURAL_NET_HPP

#include "activation_function.hpp"
#include <armadillo>
#include <vector>

namespace recognize
{
	class NeuralNet
	{
		public:
			NeuralNet(std::vector<int> layers);
			NeuralNet(std::vector<int> layers, ActivationFunction* aFunc);

			arma::vec Predict(arma::vec inputLayer);
		private:
			ActivationFunction* _activationFunction;
			std::vector<arma::mat> _weights;
			unsigned int _numLayers;
	};
}

#endif /* NEURAL_NET_HPP */