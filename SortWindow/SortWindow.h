#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <numeric>
#include <algorithm>
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
        void merge_recursive(int, int);
        void merge(int, int, int);
    public:
        SortWindow(std::vector<unsigned>&values, sf::RenderWindow &win){
            //Populate vector from 1 to N
            std::iota(values.begin(), values.end(), 1);
            //Shuffle
            std::random_shuffle(values.begin(), values.end());
            window = &win;
            width = window->getSize().x;
            height = window->getSize().y;
            y_spacing = *std::max_element(values.begin(), values.end());
            x_spacing = width/values.size();
            for(auto i:values){
                SortingBar bar{i};
                bars.push_back(bar);
            }
        }
        void draw();
        void bubble_sort();
        void merge_sort();
        void shuffle();
};
#endif