#include "binding_manager.hpp"

namespace recognize
{
	BindingManager::BindingManager()
	{
	}

	void BindingManager::AddBindng(std::vector<sf::Keyboard::Key> keys, Command* command)
	{
		Binding* binding = new Binding(*command);

		for(auto& key : keys)
		{
			binding->AddKey(key);
		}

		_bindings.push_back(binding);
	}

	void BindingManager::HandleEvent(sf::Event& event, bool& consumed)
	{
		for(auto& binding : _bindings)
		{
			binding->HandleEvent(event, consumed);
		}
	}
}

