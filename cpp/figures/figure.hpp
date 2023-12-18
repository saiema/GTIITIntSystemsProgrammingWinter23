class figure {
    // pure virtual method. Subclasses must implement
public:
    virtual void draw() = 0;
};

class circle : public figure {
    public:
        circle(int x, int y, int r);
        void draw();
    private:
        int center_x, center_y, radius;
};

class rectangle : public figure {
    public:
        rectangle(int x, int y, int w, int h);
        void draw();
    private:
        int center_x;
        int center_y;
        int width;
        int height;
};