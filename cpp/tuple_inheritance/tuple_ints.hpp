#ifndef TUPLE_HPP
#define TUPLE_HPP

class tuple {

    protected:
        int fst;
        int snd;
    
    public:

        tuple(int fst, int snd);

        int get_fst();
        int get_snd();

};

#endif