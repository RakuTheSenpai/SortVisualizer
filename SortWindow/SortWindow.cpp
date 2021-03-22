#include "SortWindow.h"

void SortWindow::draw(){
    unsigned x = 0;
    for(auto &sortingbar:bars){
        unsigned y_size = sortingbar.value * y_spacing;
        sortingbar.bar.setSize(sf::Vector2f{x_spacing, y_size});
        sortingbar.bar.setPosition(x, window->getSize().y - y_size);
        window->draw(sortingbar.bar);
        x+=x_spacing;
    }
}