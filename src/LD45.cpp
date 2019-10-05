#include <SFML/Graphics.hpp>

#include "Application.h"

#define WIDTH 512
#define HEIGHT 512
#define NAME "LD45"
#define FPS 60

Application game;

int main()
{
    game.create(sf::VideoMode(WIDTH, HEIGHT), NAME, sf::Style::Close);
    game.setFramerateLimit(FPS);

    while (game.isOpen())
    {
        sf::Event event;
        while (game.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                game.close();
            }
        }

        game.update();

        game.clear(sf::Color(0, 0, 0));
        game.drawf();
        game.display();
    }
}