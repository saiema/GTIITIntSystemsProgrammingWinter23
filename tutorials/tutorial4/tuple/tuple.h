/*
* tuple Number Abstract Data Type
* 
* A tuple is an ordered collection of 2 elements
*
* This header file declares the Abstract Data Type tuple, and it's related operations
*/

struct Tuple; // implementation related structure
typedef struct Tuple * tuple; // abstract data type

/*
* Creates a new tuple with values `fst` and `snd`.
* Value `fst` will be the first element of the tuple
* Value `snd` will be the second eleent of the tuple
*/
tuple tuple_create(const int fst, const int snd);

/*
* Returns the string representation of a tuple
*/
char * tuple_representation(const tuple const tuple_val);

/*
* Obtaines the first element of a tuple
*/
int tuple_fst(const tuple const tuple_val);

/*
* Obtaines the second element of a tuple
*/
int tuple_snd(const tuple const tuple_val);

/*
* Sets the value of the first element of a tuple
*/
int tuple_set_fst(tuple const tuple_val, const int fst_new);

/*
* Sets the value of the second element of a tuple
*/
int tuple_set_snd(tuple const tuple_val, const int snd_new);

