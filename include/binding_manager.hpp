#ifndef BINDING_MANAGER_HPP
#define BINDING_MANAGER_HPP

#include <vector>
#include "binding.hpp"

namespace recognize
{
	class BindingManager
	{
		public:
			BindingManager();
			
			void AddBindng(std::vector<sf::Keyboard::Key> keys, Command* command);
			void HandleEvent(sf::Event& event, bool& consumed);

		private:
			std::vector<Binding*> _bindings;
	};
}

#endif /* BINDING_MANAGER_HPP */
