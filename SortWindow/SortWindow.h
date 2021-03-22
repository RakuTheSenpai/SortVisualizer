#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../SortingBar/SortingBar.h"
class SortWindow{
    private:
        int width;
        int height;
        unsigned x_spacing;
        unsigned y_spacing;
        std::vector<SortingBar>bars;
        sf::RenderWindow *window;
    public:
        SortWindow(std::vector<unsigned>&values, sf::RenderWindow &win){
            //Be 80% the size of the current window
            window = &win;
            width = window->getSize().x * .8;
            height = window->getSize().y * .8;
            int mx_ele = *std::max_element(values.begin(), values.end());
            y_spacing = height/mx_ele;
            x_spacing = width/values.size();
            for(auto i:values){
                SortingBar bar{i};
                bars.push_back(bar);
            }
        }
        void draw();
};
#endif