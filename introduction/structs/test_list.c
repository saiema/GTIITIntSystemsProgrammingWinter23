#include <stdio.h>
#include <boolean.h>
#include <list_int.h>

int main() {
    list_int my_list = list_int_empty();
    printf("My empty list: %s\n", list_int_representation(my_list));
    list_int_add(my_list, 1);
    list_int_add(my_list, 2);
    list_int_add(my_list, 3);
    list_int_add(my_list, 42);
    list_int_add(my_list, 4);
    list_int_add(my_list, 83);
    list_int_add(my_list, 142);
    printf("My list: %s\n", list_int_representation(my_list));
    return 0;
}