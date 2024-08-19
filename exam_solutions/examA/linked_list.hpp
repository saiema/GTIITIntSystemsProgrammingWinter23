#include <cassert>

template <typename T>
class list {

    public:
        list() {
            this->head = nullptr; // nullptr is equivalent to NULL
            this->size = 0;
        }

        ~list() {
            while(size() > 0) {
                remove_at(0);
            }
        }

        T remove_at(int pos) {
            assert(pos >= 0);
            assert(pos < list_size);
            node<T> * to_delete; 
            if (pos == 0) {
                to_delete = this->head;
                this->head->set_next(this->head->get_next());
            } else {
                node<T> * current = this->head;
                //we want to go to the previous node of the one we need to delete
                for (int i = 0; i < pos - 1; i++) {
                    current = current->get_next();
                }
                to_delete = current->get_next();
                current->set_next(current->get_next());
            }
            T value = to_delete->get_value();
            delete to_delete;
            this->size--;
            return value;
        }

        T at(int pos) {
            assert(pos >= 0);
            assert(pos < list_size);
            node<T> * current = head;
            int i = 0;
            while (i < pos) {
                current = current->get_next();
                i++;
            }
            return current->get_value();
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