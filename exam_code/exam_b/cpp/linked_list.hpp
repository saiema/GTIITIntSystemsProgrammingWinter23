#include <cassert>

template <typename T>
class list {

    public:
        list() {
            //TODO: complete
        }

        ~list() {
            //TODO: complete
        }

        T remove_at(int pos) {
            assert(pos >= 0);
            assert(pos < list_size);
            //TODO: Complete
        }

        T at(int pos) {
            assert(pos >= 0);
            assert(pos < list_size);
            node<T> * current = head;
            int i = 0;
            while (i < pos) {
                current = current.get_next();
            }
            return current.get_value();
        }

        int size() {
            return list_size;
        }

        bool is_empty() {
            return list_size == 0;
        }

    private:
        template <typename E>
        class node {
            public:
                node(E value) {
                    this->value = value;
                    this->next = nullptr;
                }

                node(node<E> &other) : value(other.value), next(other.next) {}

                ~node() {}

                void set_next(node<E> *next) {
                    this->next = next;
                }

                node<E> *get_next() {
                    return next;
                }

                void set_value(E value) {
                    this->value = value;
                }

                E get_value() {
                    return value;
                }

            private:
                E value;
                node<E> *next;
        };
        node<T> * head;
        int list_size;
};