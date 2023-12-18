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

int tuple::set_fst(int new_fst) {
    int old_fst = this->fst;
    this->fst = new_fst;
    return old_fst;
}

int tuple::set_snd(int new_snd) {
    int old_snd = this->snd;
    this->snd = new_snd;
    return old_snd;
}