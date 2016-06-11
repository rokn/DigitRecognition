#include "canvas.hpp"
#include <cmath>

namespace recognize
{
	Canvas::Canvas(int canvasWidth, int canvasHeight, sf::RenderWindow& window)
	:	_window(window)
	{
		_canvasWidth = canvasWidth;
		_canvasHeight = canvasHeight;

		_canvas = new sf::RenderTexture();
		_canvas->create(_canvasWidth, _canvasHeight);
		Clear(sf::Color::White);

		setTexture(_canvas->getTexture());
	}

	Canvas::~Canvas()
	{
		delete _canvas;

		if(_drawShape == NULL)
		{
			delete _drawShape;
		}
		_drawShape;
	}

	void Canvas::SetShape(sf::Shape* shape)
	{
		if(_drawShape == NULL)
		{
			delete _drawShape;
		}

		_drawShape = shape;
	}

	sf::Shape& Canvas::GetShape()
	{
		return *_drawShape;
	}

	void Canvas::DrawShape()
	{
		sf::Vector2i mPos = sf::Mouse::getPosition(_window);
		mPos.y = abs(mPos.y - (int)_window.getSize().y);
		sf::Vector2f mMapped = _window.mapPixelToCoords(mPos);

		mMapped.x -= getPosition().x;
		mMapped.y -= getPosition().y;
		DrawShape(mMapped);
	}

	void Canvas::DrawShape(sf::Vector2f position)
	{
		_drawShape->setPosition(position);
		_canvas->draw(*_drawShape);
	}

	void Canvas::Clear(sf::Color clearColor)
	{
		_canvas->clear(clearColor);
	}

	void Canvas::GetPixels(int& pixelsCount, sf::Image* pixels) const
	{
		pixelsCount = _canvas->getSize().x * _canvas->getSize().y;
		*pixels = _canvas->getTexture().copyToImage();
	}
}

