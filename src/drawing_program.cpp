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
		InitBindings();
	}

	DrawingProgram::~DrawingProgram()
	{
		delete _canvas;

		for(auto& kvp : _commands)
		{
			delete kvp.second;
		}
	}

	void DrawingProgram::HandleEvent(sf::Event& event, bool& consumed)
	{
		switch(event.type)
		{
			case sf::Event::MouseButtonPressed:
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					_isDraging = true;
					consumed = true;
				}
				break;
			case sf::Event::MouseButtonReleased:
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					_isDraging = false;
					consumed = true;
				}
				break;
			case sf::Event::MouseMoved:
				if(_isDraging)
				{
					_commands.at("Draw")->Execute();
					consumed = true;
				}
				break;
			case sf::Event::Closed:
				_commands.at("Exit")->Execute();
				consumed = true;
				break;
			default:break;
		}

		_bindingManager->HandleEvent(event, consumed);
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
		AddCommand("Exit", new ExitCommand(this));
	}

	void DrawingProgram::AddCommand(const std::string& name, Command* command)
	{
		_commands.insert(std::pair<std::string, Command*>(name, command));
	}

	void DrawingProgram::InitBindings()
	{
		_bindingManager = new BindingManager();

		std::vector<sf::Keyboard::Key> currBindingKeys;

		currBindingKeys.clear();
		currBindingKeys.push_back(sf::Keyboard::Add);
		_bindingManager->AddBindng(currBindingKeys, _commands.at("Zoom"));

		currBindingKeys.clear();
		currBindingKeys.push_back(sf::Keyboard::Subtract);
		_bindingManager->AddBindng(currBindingKeys, _commands.at("ZoomOut"));

		currBindingKeys.clear();
		currBindingKeys.push_back(sf::Keyboard::C);
		_bindingManager->AddBindng(currBindingKeys, _commands.at("Clear"));

		currBindingKeys.clear();
		currBindingKeys.push_back(sf::Keyboard::Escape);
		_bindingManager->AddBindng(currBindingKeys, _commands.at("Exit"));

	}
}

