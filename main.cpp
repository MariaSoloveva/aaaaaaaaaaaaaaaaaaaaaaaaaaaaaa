#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <SFML-2.3.2/include/SFML/Graphics.hpp>
#include <SFML-2.3.2/include/SFML/Window.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/BlendMode.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/CircleShape.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Color.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/ConvexShape.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Drawable.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Font.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Glyph.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Image.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/PrimitiveType.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Rect.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/RectangleShape.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/RenderStates.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/RenderTarget.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/RenderTexture.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/RenderWindow.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Shader.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Shape.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Sprite.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Text.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Texture.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Transform.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Transformable.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/Vertex.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/VertexArray.hpp>
#include <SFML-2.3.2/include/SFML/Graphics/View.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::Text text;
    sf::Font font;
    text.setFont(font);
    font.loadFromFile("Arial.ttf");
    if (!font.loadFromFile("Arial.ttf")){
        throw std::logic_error("");
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
