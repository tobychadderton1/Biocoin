#include "Application.h"

// application constructor
Application::Application()
{
    // load texture and set the background sprite to use it
    backgroundtexture.loadFromFile("assets/Background.png");
    background.setTexture(backgroundtexture);
    background.setScale(sf::Vector2f(4.5, 4.5));

    // set player texture rect defaults
    Player.RectSource.top = 0;
    Player.RectSource.left = 0;
    Player.RectSource.width = 16;
    Player.RectSource.height = 16;

    // Load Player spritesheet
    playertexture.loadFromFile("assets/Player.png");

    //Default player attributes
    Player.setTexture(playertexture);
    Player.setScale(sf::Vector2f(3, 3));
    Player.setTextureRect(Player.RectSource);
    Player.setPosition(250, 250);
    Player.setSpeed(2.f);

    // load objects sprites
    objtextures.loadFromFile("assets/objects.png");

    // set textures for trees
    Tree1.setTexture(objtextures);
    Tree1.setTextureRect(sf::IntRect(0, 0, 16, 16));
    Tree2.setTexture(objtextures);
    Tree2.setTextureRect(sf::IntRect(0, 0, 16, 16));

    // set tree scales
    Tree1.setScale(sf::Vector2f(3, 3));
    Tree2.setScale(sf::Vector2f(3, 3));

    // set tree positions
    Tree1.setPosition(135, 145);
    Tree2.setPosition(345, 390);

    // set coin texture and scale
    coin.setTexture(objtextures);
    coin.setTextureRect(sf::IntRect(16, 16, 16, 16));
    coin.setScale(sf::Vector2f(3, 3));

    score = -1;

    // load the font and set score text attributes
    scoreFont.loadFromFile("assets/font/RobotoMono-Bold.ttf");
    scoretext.setCharacterSize(50);
    scoretext.setFont(scoreFont);
    scoretext.setFillColor(sf::Color(0, 0, 0));
    scoretext.setPosition(sf::Vector2f(15, 5));
    moveCoin();
}

// called every frame after screen clear
void Application::drawf()
{
    // draw Sprites
    draw(background);
    draw(Player);

    draw(Tree1);
    draw(Tree2);

    draw(coin);

    draw(scoretext);
}

// called every frame before screen clear
void Application::update()
{
    // shorthand booleans for wasd keys
    bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool aPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool sPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool dPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    float oldx = Player.getPosition().x;
    float oldy = Player.getPosition().y;

    // index 0 is X
    // index 1 is Y
    float playerSizeInPixels[] = {
        Player.getScale().x*16,
        Player.getScale().y*16
    };

    /*
    Move the player
    0,0 is top left of screen

    y - velocity = up
    x - velocity = left
    y + velocity = down
    x + velocity = right
    */
    if (wPressed & Player.getPosition().y > 0)
    {
        Player.move(sf::Vector2f(0, -Player.getSpeed()));
        Player.RectSource.left = 16;
    }
    if (aPressed & Player.getPosition().x > 0)
    {
        Player.move(sf::Vector2f(-Player.getSpeed(), 0));
        Player.RectSource.left = 48;
    }
    if (sPressed & Player.getPosition().y+playerSizeInPixels[1] < getSize().y)
    {
        Player.move(sf::Vector2f(0, Player.getSpeed()));
        Player.RectSource.left = 0;
    }
    if (dPressed & Player.getPosition().x+playerSizeInPixels[0] < getSize().x)
    {
        Player.move(sf::Vector2f(Player.getSpeed(), 0));
        Player.RectSource.left = 32;
    }

    // check if the player interesects with either tree
    if (Player.getGlobalBounds().intersects(Tree1.getGlobalBounds()) || Player.getGlobalBounds().intersects(Tree2.getGlobalBounds()))
    {
        Player.setPosition(sf::Vector2f(oldx, oldy));
    }

    // check if the player intersects with the coin
    if (Player.getGlobalBounds().intersects(coin.getGlobalBounds()))
    {
        moveCoin();
    }
    
    // if any movement key is pressed, change sprite every 0.1 seconds
    if (wPressed || aPressed || sPressed || dPressed)
        // checks time since last reset
        if (playerClock.getElapsedTime().asSeconds() > 0.1)
        {
            // moves the texture rect for the player down by 16px
            if (Player.RectSource.top < 32)
                Player.RectSource.top += 16;
            else
                Player.RectSource.top = 16; // sets back to default after cycle
            
            Player.setTextureRect(Player.RectSource);
            playerClock.restart(); // restart clock
        }
}

/*
    add 1 to score
    convert score to a string
    set scoretext's string value
    randomise the coin's position
*/
void Application::moveCoin()
{
    score += 1;

    std::string ting;
    std::stringstream strstr;
    strstr << score;
    strstr >> ting;
    strstr.str("");
    strstr.clear();

    scoretext.setString(ting);
    srand(time(NULL) * 90 ^ (time(NULL) / 2));
    coin.setPosition(rand() % (512-16*3), rand() % (512-16*3) );
}