#include <iostream>
#include <figure.hpp>

/*
    Sorts an array of figures, according to their area using the insertion sort algorithm.
    The sorting is done in-place.
*/
void insertion_sort(const int size, figure * figures[]);

/*
    Sorts an array of figures, according to their area using the selection sort algorithm.
    The sorting is done in-place.
*/
void selection_sort(const int size, figure * figures[]);

/*
    Copies an array of figures into another array.
    The destination array must be of at least the same size as the original
*/
void copy(const int size, figure * src[], figure * dest[]);

/*
    Prints an array of figures by calling the figures::draw function.
*/
void print_array(const int size, figure * figures[]);

int main() {
    int size = 5;
    figure * figures_copy[size];
    //Initialize array
    circle c1(0, 0, 2);
    circle c2(0, 1, 2);
    point p1(0, 1);
    rectangle r1(0, 0, 1.5f, 2);
    triangle t1(0, 0, 1.3f, 0.7f, 1.9f);
    figure * figures[size];
    figures[0] = &t1;
    figures[1] = &c1;
    figures[2] = &r1;
    figures[3] = &c2;
    figures[4] = &p1;
    copy(size, figures, figures_copy);
    std::cout << "Original array:" << std::endl;
    print_array(size, figures);
    insertion_sort(size, figures);
    std::cout << "\nSorted array (using insertion sort):" << std::endl;
    print_array(size, figures);
    selection_sort(size, figures_copy);
    std::cout << "\nSorted array (using selection sort):" << std::endl;
    print_array(size, figures_copy);
}

void shift_once_to_right(figure * figures[], int from, int to) {
    for (int i = to; i > from; i--) {
        figures[i] = figures[i - 1];
    }
}

void insert_ordered(figure * figures[], int last_index, figure * element) {
    if (last_index == -1) {
        figures[0] = element;
        return;
    }
    int insert_at;
    int found = 0;
    for (int i = 0; i <= last_index && !found; i++) {
        figure * current = figures[i];
        if (element->area() < current->area()) {
            found = 1;
            insert_at = i;
        }
    }
    if (!found) {
        insert_at = last_index + 1;
    }
    shift_once_to_right(figures, insert_at, last_index + 1);
    figures[insert_at] = element;
}

void insertion_sort(const int size, figure * figures[]) {
    int sorted_until = -1;
    int unsorted_start = 0;
    while (unsorted_start < size) {
        insert_ordered(figures, sorted_until, figures[unsorted_start]);
        unsorted_start++;
        sorted_until++;
    }
}

void selection_sort(const int size, figure * figures[]) {
    //TODO: implement
}

void copy(const int size, figure * src[], figure * dest[]) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void print_array(const int size, figure * figures[]) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        figures[i]->draw();
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}