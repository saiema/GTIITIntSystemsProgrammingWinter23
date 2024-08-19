#include <cassert>
#include <stddef.h>

class MyElem {
    public: 
        // constructors
        bool accept() {
            return value % 2 == 0; 
        }
    private:
        int value;
};

int count(const int size, MyElem elements[]) {
    assert (elements != NULL);
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (elements[i].accept()) {
            counter++;
        }
    }
    return counter;
}