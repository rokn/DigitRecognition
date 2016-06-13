#include "main.h"
#include "drawing_program.hpp"
#include "NN/neural_net.hpp"
#include "NN/sigmoid_activation.hpp"
#include <iostream>
#include <vector>

using namespace recognize;

int main()
{
	int exitCode = 0;
	//Program *program = new DrawingProgram(800,600,"DigitRecognizer",20,20);
	//exitCode = program->Run();
	std::vector<int> layers;
	layers.push_back(400);
	layers.push_back(25);
	layers.push_back(10);
	arma::vec input(400);
	NeuralNet net(layers, new SigmoidActivation());
	arma::vec out = net.Predict(input);
	out.for_each([](double& value){std::cout<<value<<std::endl;});
	return exitCode;
}
