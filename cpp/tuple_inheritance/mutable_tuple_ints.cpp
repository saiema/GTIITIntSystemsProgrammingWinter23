#include <mutable_tuple_ints.hpp>

int mutable_tuple::set_fst(int fst) {
    int old_fst = fst;
    this->fst = fst;
    return old_fst;
}

int mutable_tuple::set_snd(int snd) {
    int old_snd = snd;
    this->snd = snd;
    return old_snd;
}