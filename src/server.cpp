// File: src/server.cpp
#include <SFML/Network.hpp>
#include <iostream>

int main()
{
    const unsigned short PORT = 53000;
    sf::TcpListener listener;
    if (listener.listen(PORT) != sf::Socket::Done) {
        std::cerr << "Erreur : impossible d'écouter le port " << PORT << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Serveur démarré sur le port " << PORT << std::endl;

    while (true) {
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done) {
            std::cout << "Client connecté : "
                      << client.getRemoteAddress() << ":" << client.getRemotePort()
                      << std::endl;
            client.disconnect();
        }
    }

    return 0;
}
