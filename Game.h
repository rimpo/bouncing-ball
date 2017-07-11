#include <SFML/Graphics.hpp>

class Game{
	public:
		Game();
		void run();
	private:
		void processEvents();
		void update();
		void render();
	private:
		sf::RenderWindow mWindow;
		sf::CircleShape mCircle;
		sf::Vector2f mMovingVec;
};
