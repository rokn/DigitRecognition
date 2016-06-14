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

	double NeuralNet::CostFunction(arma::mat input, arma::mat expected, double lambda)
	{
		double cost = 0.0;
		int m = input.n_rows;

		arma::mat predictions = Predict(input);

		for(unsigned int i = 0; i < expected.n_cols; i++)
		{
			cost += (1.0 / m) * arma::sum(-expected.col(i).t() * arma::log(predictions.col(i)) -
					(1 - expected.col(i)).t() * arma::log(1 - predictions.col(i)));
		}

		double regularization = 0.0;

		for(unsigned int i = 0; i < _numLayers - 1; i++)
		{
			regularization += arma::sum(arma::sum(
						arma::pow(_weights[i].cols(2,_weights[i].n_cols - 1), 2)));
		}

		regularization *= lambda/(2*m);

		cost += regularization;

		return cost;
	}

	arma::vec NeuralNet::CalcGradient(arma::mat input, arma::mat expected, double lambda)
	{
		//int m = input.n_rows;
	}
}

