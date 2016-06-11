#ifndef DRAWING_PROGRAM_HPP
#define DRAWING_PROGRAM_HPP

#include "program.hpp"
#include "canvas.hpp"
#include "command.hpp"
#include <map>
#include "binding_manager.hpp"

namespace recognize
{
	class DrawingProgram : public Program
	{
		public:
			DrawingProgram(int windowWidth, int windowHeight, const std::string& name,
					int canvasWidth, int canvasHeight);
			~DrawingProgram();

			void HandleEvent(sf::Event& event, bool& consumed);
			void Update(float deltaTime);
			void Draw(sf::RenderWindow& window);

		private:
			bool _isDraging;
			Canvas* _canvas;
			std::map<std::string, Command*> _commands;
			BindingManager* _bindingManager;

			void InitCommands();
			void InitBindings();
			void AddCommand(const std::string& name, Command* command);
	};
}
#endif //DRAWING_PROGRAM_HPP
