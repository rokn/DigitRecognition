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

	arma::mat NeuralNet::Predict(arma::mat inputLayer)
	{
		if(_activationFunction == nullptr)
		{
			std::cerr << "No activation function set" << std::endl;
			return inputLayer;
		}

		arma::mat res = inputLayer;

		for(unsigned int i = 0; i < _numLayers - 1; i++)
		{
			res.insert_cols(0, arma::ones<arma::vec>(res.n_rows));
			res = res * _weights[i].t();
			res.for_each([&](double& val) { val = _activationFunction->Activate(val); });
		}

		return res;
	}

	double NeuralNet::CostFunction(arma::mat input, arma::mat expected)
	{
		double cost = 0.0;

		arma::mat predictions = Predict(input);

		for(unsigned int i = 0; i < expected.n_cols; i++)
		{
			cost += (1.0 / input.n_rows) * arma::sum(-expected.col(i).t() * arma::log(predictions.col(i)) -
					(1 - expected.col(i)).t() * arma::log(1 - predictions.col(i)));
		}

		

		return cost;
	}
}

