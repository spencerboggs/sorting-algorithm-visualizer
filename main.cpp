#include <SFML/Graphics.hpp>
#include "SortingAlgorithms.h"
#include "Visualizer.h"
using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Algorithm Visualizer");

    Visualizer visualizer(window);
    visualizer.run();
    return 0;
}
