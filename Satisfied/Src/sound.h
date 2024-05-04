#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include "SFML/Audio.hpp"
#include<iostream>


class sound
{
public:
    void loadSound(const std::string& filePath);
    void playSound();
    void stopSound();

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

