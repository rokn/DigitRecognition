#ifndef COMMAND_H
#define COMMAND_H

namespace recognize
{
	class Command
	{
		public:
			virtual void Execute() = 0;
	};
}

#endif //COMMAND_H
