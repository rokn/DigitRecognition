#include "drawing_program.hpp"
#include <iostream>

namespace recognize
{
	
	DrawingProgram::DrawingProgram(int windowWidth, int windowHeight, const std::string& name,
			int canvasWidth, int canvasHeight):
		Program(windowWidth,windowHeight,name)
	{
		_isDraging = false;	
		_canvasWidth = canvasWidth;
		_canvasHeight = canvasHeight;
		_drawShape = new sf::CircleShape(2);
		_drawShape->setFillColor(sf::Color::Black);
		_canvas = new sf::RenderTexture();
		_canvas->create(canvasWidth, canvasHeight);
		_canvas->clear(sf::Color::White);
		_canvasSprite = new sf::Sprite();
		_canvasSprite->setTexture(_canvas->getTexture());
		_canvasSprite->setScale(1.0f, -1.0f);
		sf::Vector2f pos(GetWindow().getSize().x/2 - canvasWidth/2,
						GetWindow().getSize().y/2 + canvasHeight/2);
		_canvasSprite->setPosition(pos);
	}

	DrawingProgram::~DrawingProgram()
	{
		delete _drawShape;
		delete _canvas;
		delete _canvasSprite;
	}

	void DrawingProgram::HandleEvent(sf::Event& event)
	{
		switch(event.type)
		{
			case sf::Event::MouseButtonPressed:
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					_isDraging = true;
				}
				break;
			case sf::Event::MouseButtonReleased:
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					_isDraging = false;
				}
				break;
			case sf::Event::MouseMoved:
				if(_isDraging)
				{
					sf::Vector2i pos = sf::Vector2i(event.mouseMove.x - _canvasSprite->getPosition().x, (event.mouseMove.y - _canvasSprite->getPosition().y) + _canvasHeight);
					sf::Vector2f mapped = GetWindow().mapPixelToCoords(pos);
					_drawShape->setPosition(mapped.x, mapped.y);
					_canvas->draw(*_drawShape);
					std::cerr << "posX:" << _drawShape->getPosition().x
						<< "posY:" << _drawShape->getPosition().y << std::endl;
				}
				break;
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Escape)
				{
					Exit(0);
				}
				else if(event.key.code == sf::Keyboard::Add)
				{
					GetView().zoom(0.9f);
				}
				else if(event.key.code == sf::Keyboard::Subtract)
				{
					GetView().zoom(1.1f);
				}
				break;
			case sf::Event::Closed:
				Exit(0);
				break;
			default:break;
		}
	}

	void DrawingProgram::Update(float deltaTime)
	{

	}

	void DrawingProgram::Draw(sf::RenderWindow& window)
	{
		window.draw(*_canvasSprite);
	}
}

