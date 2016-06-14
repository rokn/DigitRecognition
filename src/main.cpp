#include "main.h"
#include "drawing_program.hpp"
#include "NN/neural_net.hpp"
#include "NN/sigmoid_activation.hpp"
#include <iostream>
#include <vector>

using namespace recognize;

int main()
{
	arma::arma_rng::set_seed_random();
	int exitCode = 0;
	//Program *program = new DrawingProgram(800,600,"DigitRecognizer",20,20);
	//exitCode = program->Run();
	std::vector<int> layers;
	layers.push_back(4);
	layers.push_back(25);
	layers.push_back(10);
	arma::mat input(5, 4, arma::fill::randu);
	arma::mat expected(5, 10, arma::fill::randu);
	NeuralNet net(layers, new SigmoidActivation());
	double cost = net.CostFunction(input, expected);
	input.print("Input: ");
	expected.print("Expected: ");
	std::cout << cost << std::endl;
	//out.for_each([](double& value){std::cout<<value<<std::endl;});
	return exitCode;
}
