#include "zoom_command.hpp"

namespace recognize
{
	ZoomCommand::ZoomCommand(sf::View& view, float zoomAmount)
	: _view(view)
	{
		_zoomAmount = zoomAmount;
	}

	void ZoomCommand::Execute()
	{
		_view.zoom(_zoomAmount);
	}
}

