#ifndef TUPLE_HPP
#define TUPLE_HPP

class tuple {

    private:
        int fst;
        int snd;
    
    public:

        tuple(int fst, int snd);

        int get_fst();
        int get_snd();

        int set_fst(int new_fst);
        int set_snd(int new_snd);
};

#endif