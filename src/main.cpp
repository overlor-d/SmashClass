// File: src/main.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    const unsigned int WIDTH = 800;
    const unsigned int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SmashClass – Client");

    // Boutons du menu
    sf::RectangleShape playButton(sf::Vector2f(200.f, 60.f));
    playButton.setFillColor(sf::Color(100, 100, 200));
    playButton.setPosition(WIDTH / 2.f - 100.f, HEIGHT / 2.f - 80.f);

    sf::RectangleShape quitButton(sf::Vector2f(200.f, 60.f));
    quitButton.setFillColor(sf::Color(200, 100, 100));
    quitButton.setPosition(WIDTH / 2.f - 100.f, HEIGHT / 2.f + 20.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                auto mousePos = sf::Mouse::getPosition(window);
                if (playButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    std::cout << "Play button pressed (TODO: lancer le jeu)" << std::endl;
                }
                if (quitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(playButton);
        window.draw(quitButton);
        window.display();
    }

    return 0;
}
