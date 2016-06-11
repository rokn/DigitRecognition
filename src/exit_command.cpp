#include "exit_command.hpp"

namespace recognize
{
	ExitCommand::ExitCommand(Program* program)
	{
		_program = program;
	}

	void ExitCommand::Execute()
	{
		_program->Exit(0);
	}
}

