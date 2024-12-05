#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Visualizer {
private:
    sf::RenderWindow& window;
    std::vector<int> array;
    bool running;

    void render();
    void handleInput();
    void initializeArray();
public:
    Visualizer(sf::RenderWindow& win);
    void run();
};

#endif
