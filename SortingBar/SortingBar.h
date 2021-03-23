#ifndef SORTING_BAR_H
#define SORTING_BAR_H
#include <SFML/Graphics.hpp>

struct SortingBar{
        sf::RectangleShape bar;
        unsigned value;
        sf::Vector2f size;
        SortingBar(unsigned v):value{v}{
            bar.setOutlineColor(sf::Color::Black);
            bar.setFillColor(sf::Color::Cyan);
            bar.setOutlineThickness(1);
        }
        SortingBar(){}
        friend void swap(SortingBar &a, SortingBar &b){
            SortingBar temp = a;
            a.value = b.value;
            a.bar = b.bar;
            b.value = temp.value;
            b.bar = temp.bar;
        }
};
#endif