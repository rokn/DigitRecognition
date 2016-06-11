#ifndef ZOOM_COMMAND_H
#define ZOOM_COMMAND_H

#include "command.hpp"
#include <SFML/Graphics.hpp>

namespace recognize
{
	class ZoomCommand : public Command
	{
		public:
			ZoomCommand(sf::View& view, float zoomAmount);
			void Execute();

		private:
			sf::View& _view;
			float _zoomAmount;
	};
}

#endif //ZOOM_COMMAND_H
