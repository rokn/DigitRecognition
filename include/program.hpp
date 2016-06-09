#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <SFML/Graphics.hpp>

namespace recognize
{
	class Program
	{
		public:
			Program(int windowWidth, int windowHeight, const std::string& name);
			~Program();

			int Run();
			void Exit(int exitCode);
			sf::RenderWindow& GetWindow();
			sf::View& GetView();

		protected:
		virtual	void HandleEvent(sf::Event& event) = 0;
		virtual	void Update(float deltaTime) = 0;
		virtual	void Draw(sf::RenderWindow& window) = 0;

		private:
			sf::RenderWindow *_window;
			bool _exit;
			int _exitCode;
			sf::View *_mainView;
	};
}

#endif //PROGRAM_HPP
