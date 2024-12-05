#include "Visualizer.h"
#include "SortingAlgorithms.h"
#include <random>

Visualizer::Visualizer(sf::RenderWindow& win) : window(win), running(true) {
    initializeArray();
}

void Visualizer::initializeArray() {
    array.clear();
    for (int i = 1; i <= 100; ++i)
        array.push_back(i);
    std::shuffle(array.begin(), array.end(), std::mt19937{std::random_device{}()});
}

void Visualizer::render() {
    window.clear();
    float barWidth = window.getSize().x / static_cast<float>(array.size());

    for (size_t i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(barWidth, array[i] * 5));
        bar.setPosition(i * barWidth, window.getSize().y - array[i] * 5);
        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }

    window.display();
}

void Visualizer::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            running = false;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                SortingAlgorithms::bubbleSort(array, [&]() { render(); });
            } else if (event.key.code == sf::Keyboard::S) {
                SortingAlgorithms::selectionSort(array, [&]() { render(); });
            } else if (event.key.code == sf::Keyboard::Q) {
                SortingAlgorithms::quickSort(array, [&]() { render(); });
            }
        }
    }
}

void Visualizer::run() {
    while (running) {
        handleInput();
        render();
    }
}
