#ifndef CLEAR_COMMAND_H
#define CLEAR_COMMAND_H

#include "command.hpp"
#include "canvas.hpp"
#include <SFML/Graphics.hpp>

namespace recognize
{
	class ClearCommand : public Command
	{
		public:
			ClearCommand(Canvas& canvas, sf::Color _clearColor);
			void Execute();

		private:
			Canvas& _canvas;
			sf::Color _clearColor;
	};
}

#endif //CLEAR_COMMAND_H
