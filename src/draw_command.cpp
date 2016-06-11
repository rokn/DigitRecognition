#include "draw_command.hpp"

namespace recognize
{
	DrawCommand::DrawCommand(Canvas& canvas)
	: _canvas(canvas)
	{
	}

	void DrawCommand::Execute()
	{
		_canvas.DrawShape();
	}
}

