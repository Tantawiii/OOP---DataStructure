#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class Extras {
public:
    bool loadFont(sf::Font& font);
    void loadBackground(sf::Texture& backgroundTexture, sf::Sprite& background, const sf::RenderWindow& window);
    void setupText(sf::Text& text, const sf::Font& font, const std::string& content, float x, float y);
    void playBackgroundMusic(sf::SoundBuffer& buffer, sf::Sound& sound);
};
