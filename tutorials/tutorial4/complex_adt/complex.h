/*
* complex Number Abstract Data Type
*
* This header file declares the Abstract Data Type complex, and it's related operations
*/

struct Complex; // implementation related structure
typedef struct Complex * complex; // abstract data type

/*
* Creates a new complex number given two real values: `real` and `imaginary`.
*/
complex create_complex(const float real, const float imaginary);

/*
* Returns the string representation of a complex number
*/
char * complex_representation(const complex const complex_value);

/*
* Returns the addition of two complex numbers as a new complex number
* Takes two complex numbers: `complex_a` and `complex_b`
* Returns a new complex number representing `complex_a + complex_b`
*/
complex complex_addition(const complex const complex_a, const complex const complex_b);

/*
* Returns the subtraction of two complex numbers as a new complex number
* Takes two complex numbers: `complex_a` and `complex_b`
* Returns a new complex number representing `complex_a - complex_b` 
*/
complex complex_subtraction(const complex const complex_a, const complex const complex_b);

/*
* Returns the multiplication of two complex numbers as a new complex number
* Takes two complex numbers: `complex_a` and `complex_b`
* Returns a new complex number representing `complex_a * complex_b`
*/
complex complex_multiply(const complex const complex_a, const complex const complex_b);

/*
* Obtains the real part of a complex number
*/
float complex_real(const complex const complex_val);

/*
* Obtains the imaginary part of the complex number
*/
float complex_imaginary(const complex const complex_val);