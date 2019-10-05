#pragma once

#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

#include "gameObject.h"

class Application : public sf::RenderWindow
{
private:
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

public:
    Application();

    void drawf();

    void update();

    void moveCoin();
    
protected:
    sf::Clock playerClock;
};

#endif // _APPLICATION_H