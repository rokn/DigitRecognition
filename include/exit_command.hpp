#ifndef EXIT_COMMAND_HPP
#define EXIT_COMMAND_HPP

#include "command.hpp"
#include "program.hpp"

namespace recognize
{
	class ExitCommand : public Command
	{
		public:
			ExitCommand(Program* program);
			
			void Execute();

		private:
			Program* _program;
	};
}			

#endif /* EXIT_COMMAND_HPP */
