#include "program.hpp"

namespace recognize
{
	Program::Program(int windowWidth, int windowHeight, const std::string& name)
	{
		_window = new sf::RenderWindow(sf::VideoMode(windowWidth,windowHeight),name);
		_mainView = new sf::View(sf::FloatRect(0,0,windowWidth,windowHeight));
		_window->setView(*_mainView);
	}

	Program::~Program()
	{
		delete _window;
		delete _mainView;
	}

	int Program::Run()
	{
		int deltaTime = 0.0f;
		bool eventConsumed;
		sf::Event currEvent;
		_exit = false;

		while(!_exit)
		{
			while(_window->pollEvent(currEvent))
			{
				eventConsumed = false;
				HandleEvent(currEvent, eventConsumed);
			}

			Update(deltaTime);
			_window->setView(*_mainView);
			_window->clear(sf::Color::Black);
			Draw(*_window);
			_window->display();
		}

		return _exitCode;
	}

	void Program::Exit(int exitCode)
	{
		_exit = true;
		_exitCode = exitCode;
	}


	sf::RenderWindow& Program::GetWindow()
	{
		return *_window;
	}

	sf::View& Program::GetView()
	{
		return *_mainView;
	}
}

