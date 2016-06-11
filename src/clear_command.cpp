#include "clear_command.hpp"

namespace recognize
{
	ClearCommand::ClearCommand(Canvas& canvas, sf::Color clearColor)
	: _canvas(canvas)
	{
		_clearColor = clearColor;
	}

	void ClearCommand::Execute()
	{
		_canvas.Clear(_clearColor);
	}
}

