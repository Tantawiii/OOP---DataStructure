#include "Extras.h"
// Function to load a font
void Extras::loadFont(Font& font) {
    if (!font.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/Precious.ttf")) {
        cerr << "Error: Could not load font." << endl;
    }
}

// Function to load the background image and scale it to fit the window
void Extras::loadBackground(Texture& backgroundTexture, Sprite& background, const RenderWindow& window) {
    if (backgroundTexture.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/images.jpg")) {
        background.setTexture(backgroundTexture);

        // Scale the background initially to fit the window size
        float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
        float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
        background.setScale(scaleX, scaleY);
    }
    else {
        cerr << "Error: Could not load background image." << endl;
    }
}

// Function to set up and center text properties
void Extras::setupText(Text& text, const Font& font, const string& content, float x, float y) {
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(30);
    text.setFillColor(Color::White);

    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(x, y);
}

// Function to load and play background music
void Extras::playBackgroundMusic(SoundBuffer& buffer, Sound& sound) {
    if (buffer.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/SnakeGame/SfmlTests/music.mp3")) {
        sound.setBuffer(buffer);
        sound.setLoop(true); // Optional: loops the sound continuously
        sound.setVolume(10); // Set volume (adjust as needed)
        sound.play();
    }
    else {
        cerr << "Error: Could not load background music." << endl;
    }
}