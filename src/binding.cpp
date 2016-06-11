#include "binding.hpp"

namespace recognize
{
	Binding::Binding(Command& command)
	: _command(command)
	{

	}

	void Binding::AddKey(sf::Keyboard::Key key)
	{
		_keys.push_back(key);
	}

	void Binding::HandleEvent(sf::Event& event, bool& consumed)
	{
		if(!consumed)
		{
			if(event.type == sf::Event::KeyPressed)
			{
				if(CheckAllKeysPressed())
				{
					consumed = true;
					_command.Execute();
				}
			}
		}
	}

	bool Binding::CheckAllKeysPressed() const
	{
		bool allPressed = true;

		for(auto& key : _keys)
		{
			allPressed &= sf::Keyboard::isKeyPressed(key);
		}

		return allPressed;
	}
}

