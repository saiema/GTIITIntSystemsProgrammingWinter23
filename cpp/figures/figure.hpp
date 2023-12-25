#include <iostream>

/*
    Declarations of classes:
    1. figure, an abstract class representing a 2D figure with a center; a drawing function and a function to calculate it's area
    2. circle, rectangle, and triangle, specific 2D figures
    3. point, a point in a 2D space, this is a circle with radius 0
*/

class figure {
    // pure virtual method. Subclasses must implement
    public:
        virtual void draw() = 0;
        virtual float area() = 0;
    protected:
        int center_x;
        int center_y;
};

class circle : public figure {
    public:
        circle(int x, int y, float radius);
        void draw();
        float area();
    protected:
        float radius;
};

class point : public circle {
    public:
        point(int x, int y);
        void draw();
        float area();
};

class rectangle : public figure {
    public:
        rectangle(int x, int y, float width, float height);
        void draw();
        float area();
    private:
        float width;
        float height;
};

class triangle : public figure {
    public:
        triangle(int x, int y, float a, float b, float c);
        void draw();
        float area();
    private:
        float a;
        float b;
        float c;
};