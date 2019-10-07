#include "Button.h"

bool Button::isMouseTouching(sf::Window *app)
{
    /*
        get the global mouse position on this window
        cast it to a Vector2 Float
        check if the Button's global bounds contain it

        else : return false
    */
    if (getGlobalBounds().contains((sf::Vector2f)(sf::Mouse::getPosition(*app))))
    {
        return true;
    }
    else
        return false;
}

bool Button::isPressed(sf::Window *app)
{
    /*
        if the mouse is touching, the button is pressed
        and the timer has been going for longer than .5 seconds,
        restart the timer and return true

        else : return false
    */
    if (isMouseTouching(app) & sf::Mouse::isButtonPressed(sf::Mouse::Left) & clickTimer.getElapsedTime().asSeconds() > .5)
    {
        clickTimer.restart();
        return true;
    }
    else
        return false;
}