#ifndef BINDING_HPP
#define BINDING_HPP

#include <SFML/Graphics.hpp>
#include "command.hpp"

namespace recognize
{
	class BindingManager; // ForwDecl

	class Binding
	{
		public:
			void AddKey(sf::Keyboard::Key key);
			void HandleEvent(sf::Event& event, bool& consumed);
		private:
			std::vector<sf::Keyboard::Key> _keys;
			Command& _command;
			friend class BindingManager;

			Binding(Command& command);
			bool CheckAllKeysPressed() const;
	};
}

#endif //BINDING_HPP
