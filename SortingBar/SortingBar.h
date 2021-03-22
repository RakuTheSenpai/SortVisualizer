#ifndef SORTING_BAR_H
#define SORTING_BAR_H
#include <SFML/Graphics.hpp>

struct SortingBar{
        sf::RectangleShape bar;
        unsigned value;
        sf::Vector2f size;
        SortingBar(unsigned v):value{v}{
            bar.setOutlineColor(sf::Color::Black);
            bar.setOutlineThickness(1);
        }
        SortingBar(){}
};
#endif