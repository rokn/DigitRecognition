#ifndef DRAWING_PROGRAM_HPP
#define DRAWING_PROGRAM_HPP

#include "program.hpp"

namespace recognize
{
	class DrawingProgram : public Program
	{
		public:
			DrawingProgram(int windowWidth, int windowHeight, const std::string& name,
					int canvasWidth, int canvasHeight);
			~DrawingProgram();

			void HandleEvent(sf::Event& event);
			void Update(float deltaTime);
			void Draw(sf::RenderWindow& window);

		private:
			bool _isDraging;
			int _canvasWidth;
			int _canvasHeight;
			sf::Shape *_drawShape;
			sf::RenderTexture *_canvas;
			sf::Sprite *_canvasSprite;

	};
}
#endif //DRAWING_PROGRAM_HPP
