#ifndef DRAW_COMMAND_H
#define DRAW_COMMAND_H

#include "command.hpp"
#include "canvas.hpp"

namespace recognize
{
	class DrawCommand : public Command
	{
		public:
			DrawCommand(Canvas& canvas);
			void Execute();

		private:
			Canvas& _canvas;
	};
}

#endif //DRAW_COMMAND_H
