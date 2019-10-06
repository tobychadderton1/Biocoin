#pragma once

#ifndef _BUTTON_H
#define _BUTTON_H

#include <SFML/Graphics.hpp>

class Button : public sf::Sprite
{
private:

public:
    bool isPressed(sf::Window*);
    bool isMouseTouching(sf::Window*);

protected:
    sf::Clock clickTimer;
};

#endif // _BUTTON_H