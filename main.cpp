#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include "SFML-2.3.2/include/SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::Text text;
    sf::Font font;
    text.setFont(font);
    font.loadFromFile("Arial.ttf");
    if (!font.loadFromFile("Arial.ttf")){
        throw std::logic_error("Error");
    }
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
