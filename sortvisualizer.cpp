#include <SFML/Graphics.hpp>
#include <iostream>
#include "SortWindow/SortWindow.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(1200,800),"Sort Visualizer");
    std::vector<unsigned>numbers(1200);
    SortWindow sortwindow(numbers, window);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Q:
                            sortwindow.bubble_sort();
                            break;
                        case sf::Keyboard::W:
                            sortwindow.merge_sort();
                            break;
                        case sf::Keyboard::E:
                            sortwindow.quick_sort();
                            break;
                        case sf::Keyboard::R:
                            sortwindow.shuffle();
                            break;
                    }
            }
        }
        window.clear(sf::Color(1, 96, 146,1));
        sortwindow.draw();
        window.display();
    }
}