#pragma once

#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include "gameObject.h"

class Application : public sf::RenderWindow
{
private:

    // game clock is mostly used for random seeds
    sf::Clock gameClock;

    sf::Texture backgroundtexture;
    sf::Sprite background;

    sf::Texture playertexture;
    gameObject Player;

    sf::Texture objtextures;

    sf::Sprite Tree1;
    sf::Sprite Tree2;

    sf::Sprite coin;

    int score;

    sf::Font scoreFont;
    sf::Text scoretext;

    sf::Music music;

    sf::SoundBuffer coinBuffer;
    sf::Sound coinSound;

    sf::Clock playerClock;
    sf::Clock coinClock;

public:
    Application();

    void drawf();

    void update();

    void moveCoin();

    void addPointAndMoveCoin();
    
protected:
};

#endif // _APPLICATION_H