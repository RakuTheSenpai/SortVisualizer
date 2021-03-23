#include "SortWindow.h"

void SortWindow::draw(){
    unsigned x = 0;
    window->clear(sf::Color(1, 96, 146,1));
    for(auto &sorting_bar:bars){
        unsigned y_size = sorting_bar.value *  height / y_spacing;
        sorting_bar.bar.setSize(sf::Vector2f{x_spacing - 2, y_size});
        sorting_bar.bar.setPosition(x, window->getSize().y - y_size);
        window->draw(sorting_bar.bar);
        x+=x_spacing + 1;
    }
    window->display();
}

void SortWindow::shuffle(){
    std::random_shuffle(bars.begin(), bars.end());
    draw();
}

void SortWindow::bubble_sort(){
    bool swapped;
    for(int i = 0; i < bars.size() - 1; ++i){
        swapped = false;
        draw();
        for(int j = 0; j < bars.size() - i - 1; ++j){
            if(bars[j].value > bars[j + 1].value){
                std::swap(bars[j], bars[j + 1]);
                swapped = true;
                draw();
            }
        }
        if(swapped = false) break;
    }
}