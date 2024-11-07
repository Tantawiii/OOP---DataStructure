#include "Extras.h"
#include <iostream>

bool Extras::loadFont(sf::Font& font) {
    if (!font.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/OOP---DataStructure/SnakeGameProject/SfmlTests/Precious.ttf")) {
        std::cerr << "Error: Could not load font." << std::endl;
        return false;
    }
    return true;
}

void Extras::loadBackground(sf::Texture& backgroundTexture, sf::Sprite& background, const sf::RenderWindow& window) {
    if (backgroundTexture.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/OOP---DataStructure/SnakeGameProject/SfmlTests/images.jpg")) {
        background.setTexture(backgroundTexture);
        float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
        float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
        background.setScale(scaleX, scaleY);
    }
    else {
        std::cerr << "Error: Could not load background image." << std::endl;
    }
}

void Extras::setupText(sf::Text& text, const sf::Font& font, const std::string& content, float x, float y) {
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(x, y);
}

void Extras::playBackgroundMusic(sf::SoundBuffer& buffer, sf::Sound& sound) {
    if (buffer.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/OOP---DataStructure/SnakeGameProject/SfmlTests/music.mp3")) {
        sound.setBuffer(buffer);
        sound.setLoop(true);
        sound.setVolume(10);
        sound.play();
    }
    else {
        std::cerr << "Error: Could not load background music." << std::endl;
    }
}
