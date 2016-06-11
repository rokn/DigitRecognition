#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <SFML/Graphics.hpp>

namespace recognize
{
	class Canvas : public sf::Sprite
	{
		public:
			Canvas(int canvasWidth, int canvasHeight, sf::RenderWindow& window);
			~Canvas();

			void SetShape(sf::Shape* shape);
			sf::Shape& GetShape();

			void DrawShape(); // At Mouse Position
			void DrawShape(sf::Vector2f position);

			void Clear(sf::Color clearColor = sf::Color::White);
			void GetPixels(int& pixelsCount, sf::Image* pixels) const;
		private:
			int _canvasWidth;
			int _canvasHeight;
			sf::Shape *_drawShape;
			sf::RenderTexture *_canvas;
			sf::RenderWindow& _window;
	};
}
#endif //CANVAS_HPP
