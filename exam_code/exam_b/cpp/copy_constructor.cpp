class my_class {

    public:

        //Empty constructor, initializes value with 0
        my_class(): value(0) {}

        //Constructor taking a value for the value field
        my_class(int v): value(v) {}

        //Copy-Constructor
        my_class(my_class other) {
            value = other.value;
        }

    private:
        int value;

};