#include <tuple_ints.hpp>


tuple::tuple(int fst, int snd) {
    this->fst = fst;
    this->snd = snd;
}

int tuple::get_fst(void) {
    return this->fst;
}

int tuple::get_snd(void) {
    return this->snd;
}