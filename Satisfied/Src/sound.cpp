#include "Sound.h"

void sound::loadSound(const std::string& filePath)
{
    if (!buffer.loadFromFile(filePath)) {
        std::cout << "Error loading sound file: " << filePath << std::endl;
    }
    else {
        sound.setBuffer(buffer);
    }
}

void sound::playSound()
{
    sound.play();
}

void sound::stopSound()
{
    sound.stop();
}