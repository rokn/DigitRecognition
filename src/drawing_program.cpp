#include "drawing_program.hpp"
#include "commands.hpp"
#include <iostream>

#define ZOOM_AMOUNT 0.01

namespace recognize
{
	DrawingProgram::DrawingProgram(int windowWidth, int windowHeight, const std::string& name,
			int canvasWidth, int canvasHeight)
	:	Program(windowWidth,windowHeight,name)
	{
		_isDraging = false;

		_canvas = new Canvas(canvasWidth, canvasHeight, GetWindow());

		sf::Shape* _drawShape = new sf::RectangleShape(sf::Vector2f(1,1));
		_drawShape->setFillColor(sf::Color::Black);

		_canvas->SetShape(_drawShape);

		sf::Vector2f pos(GetWindow().getSize().x/2 - canvasWidth/2,
						GetWindow().getSize().y/2 - canvasHeight/2);
		_canvas->setPosition(pos);

		GetView().zoom(0.05f);

		InitCommands();
	}

	DrawingProgram::~DrawingProgram()
	{
		delete _canvas;
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
					_commands.at("Draw")->Execute();
				}
				break;
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Escape)
				{
					Exit(0);
				}
				else if(event.key.code == sf::Keyboard::Add)
				{
					_commands.at("Zoom")->Execute();
				}
				else if(event.key.code == sf::Keyboard::Subtract)
				{
					_commands.at("ZoomOut")->Execute();
				}
				else if(event.key.code == sf::Keyboard::C)
				{
					_commands.at("Clear")->Execute();
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
		window.draw(*_canvas);
	}

	void DrawingProgram::InitCommands()
	{
		AddCommand("Draw", new DrawCommand(*_canvas));
		AddCommand("Zoom", new ZoomCommand(GetView(), 1.0 - ZOOM_AMOUNT));
		AddCommand("ZoomOut", new ZoomCommand(GetView(), 1.0 + ZOOM_AMOUNT));
		AddCommand("Clear", new ClearCommand(*_canvas, sf::Color::White));
	}

	void DrawingProgram::AddCommand(const std::string& name, Command* command)
	{
		_commands.insert(std::pair<std::string, Command*>(name, command));
	}
}

