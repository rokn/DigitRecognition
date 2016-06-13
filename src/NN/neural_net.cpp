#include "NN/neural_net.hpp"
#include <iostream>

namespace recognize
{
	NeuralNet::NeuralNet(std::vector<int> layers)
	{
		_activationFunction = nullptr;
		_numLayers = layers.size();

		for(unsigned int i = 0; i < _numLayers - 1; i++)
		{
			_weights.push_back(arma::randn<arma::mat>(layers[i+1], layers[i] + 1));
		}
	}

	NeuralNet::NeuralNet(std::vector<int> layers, ActivationFunction* aFunc)
	: NeuralNet(layers)
	{
		_activationFunction = aFunc;
	}

	arma::vec NeuralNet::Predict(arma::vec inputLayer)
	{
		if(_activationFunction == nullptr)
		{
			std::cerr << "No activation function set" << std::endl;
			return inputLayer;
		}

		arma::vec res = inputLayer;

		for(unsigned int i = 0; i < _numLayers - 1; i++)
		{
			res.insert_rows(0, arma::ones<arma::vec>(1));
			res = (res.t() * _weights[i].t()).t();
			res.for_each([&](double& val) { val = _activationFunction->Activate(val); });
		}

		return res;
	}
}

