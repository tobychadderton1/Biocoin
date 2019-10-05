#pragma once

#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class gameObject : public sf::Sprite
{
public:
    void setSpeed(float);

    float getSpeed();

    sf::IntRect RectSource;

protected:
    float speed;
};

#endif // _GAMEOBJECT_H