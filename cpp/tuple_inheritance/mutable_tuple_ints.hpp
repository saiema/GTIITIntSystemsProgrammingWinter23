#ifndef MUTABLE_TUPLE_HPP
#define MUTABLE_TUPLE_HPP

#include <tuple_ints.hpp>

class mutable_tuple: public tuple {

    public:
        mutable_tuple(int fst, int snd) : tuple(fst, snd) {};

        int set_fst(int fst);
        int set_snd(int snd);

};

#endif