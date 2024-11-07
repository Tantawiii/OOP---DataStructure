#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "Position.h"
#include "GameState.h"
using namespace std;
using namespace sf;
class Extras
{
public:
	void loadFont(Font& font);
	void loadBackground(Texture& backgroundTexture, Sprite& background, const RenderWindow& window);
	void setupText(Text& text, const Font& font, const string& content, float x, float y);
	void playBackgroundMusic(SoundBuffer& buffer, Sound& sound);
};

