#include <SFML/Graphics.hpp>
#include <iostream>
#include "SortWindow/SortWindow.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"Sort Visualizer");
    std::vector<unsigned>numbers{4,3,2,5,1,6};
    SortWindow sortwindow(numbers, window);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear(sf::Color::White);
        sortwindow.draw();
        window.display();
    }
}