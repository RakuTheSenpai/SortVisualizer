#include "SortWindow.h"

void SortWindow::draw(){
    unsigned x = 0;
    window->clear(sf::Color(1, 96, 146,1));
    for(auto &sorting_bar:bars){
        unsigned y_size = sorting_bar.value *  height / y_spacing;
        sorting_bar.bar.setSize(sf::Vector2f{x_spacing, y_size});
        sorting_bar.bar.setPosition(x, window->getSize().y - y_size);
        window->draw(sorting_bar.bar);
        x+=x_spacing;
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

void SortWindow::merge_sort(){
    merge_recursive(0, bars.size()-1);
}

void SortWindow::merge_recursive(int left, int right){
    if(left >= right) return;
    int mid = left + (right - left)/2;
    merge_recursive(left, mid);
    merge_recursive(mid + 1, right);
    merge(left, mid, right);
}

void SortWindow::merge(int left, int mid, int right){
    int sizel = mid - left + 1;
    int sizer = right - mid;
    std::vector<SortingBar>L;
    std::vector<SortingBar>R;
    for(int i = 0; i < sizel; ++i){
        L.push_back(bars[left + i]);
    }
    for(int i = 0; i < sizer; ++i){
        R.push_back(bars[mid + 1 + i]);
    }
    //indexes of both subarrays
    int i = 0, j = 0;
    //index of the merge subarray starts at lower bound(left)
    int k = left;
    while(i < sizel && j < sizer){
        if(L[i].value <= R[j].value){
            bars[k] = L[i];
            ++i;
        }else{
            bars[k] = R[j];
            ++j;
        }
        ++k;
        draw();
    }
    //Copy remaining elements
    while(i < sizel){
        bars[k] = L[i];
        ++i, ++k;
        draw();
    }
    while(j < sizer){
        bars[k] = R[j];
        ++j, ++k;
        draw();
    }

}