#include "Game.h"
int main() {
	srand(static_cast<unsigned>(time(0)));
	RenderWindow window(VideoMode(800, 800), "Snake Game", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	Game game;
	
	Extras extra;
	Font font;
	Texture backgroundTexture;
	Sprite background;
	SoundBuffer buffer;
	Sound sound;
	Text startText, exitText, gameOverText, healthText, speedText, scoreText;
	extra.loadFont(font);
	extra.loadBackground(backgroundTexture, background, window);
	extra.playBackgroundMusic(buffer, sound);
	extra.setupText(startText, font, "Press Enter to Start", window.getSize().x / 2.0f, window.getSize().y / 2.0f - 30);
	extra.setupText(exitText, font, "Press Escape to Exit", window.getSize().x / 2.0f, window.getSize().y / 2.0f + 30);
	extra.setupText(gameOverText, font, "Game Over! Press Enter to Restart", window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	game.setExtras(extra);

	GameState gameState = MENU;
	int cellSizeX = window.getSize().x / 10;
	int cellSizeY = window.getSize().y / 10;

	Clock clock;
	Time timeSinceLastMove = Time::Zero;

	char grids[10][10];
	vector<Position> emptyPositions;
	Grid grid;
	grid.getGrid("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/gridfile.txt", grids, emptyPositions);

	Clock collectibleTimer;
	Clock downsizeTimer;       // Clock for downsize collectible delay
	Clock invincibilityTimer;  // Clock for invincibility collectible delay
	bool immediateRespawn = false;

}