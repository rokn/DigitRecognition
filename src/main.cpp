#include "main.h"
#include "drawing_program.hpp"

using namespace recognize;

int main()
{
	Program *program = new DrawingProgram(800,600,"DigitRecognizer",20,20);
	int exitCode = program->Run();
	return exitCode;
}
