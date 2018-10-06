#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <SFML/include/SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::Text text;
    sf::Font font;
    text.setFont(font);
    font.loadFromFile("/home/mariasolovyova/CLionProjects/untitled1/Arial.ttf");
    if (!font.loadFromFile("/home/mariasolovyova/CLionProjects/untitled1/Arial.ttf")){
        throw std::logic_error("");
    }
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
// inside the main loop, between window.clear() and window.display()
    window.draw(text);
    //  sf::CircleShape shape(100.f);
    //  shape.setFillColor(sf::Color::Green);

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
