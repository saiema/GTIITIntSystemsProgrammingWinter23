#include <iostream>

using namespace std;

template <int N>
struct Factorial 
{
        enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> 
{
        enum { value = 1 };
};

int main()
{
    // compile-time evaluation
    int f13 = Factorial<13>::value;
    int f12 = Factorial<12>::value;
    int f11 = Factorial<11>::value;
//     int f10 = Factorial<10>::value;
//     int f8 = Factorial<8>::value;
    int f4 = Factorial<4>::value; // == 24
//     int f3 = Factorial<3>::value;
//     int f2 = Factorial<2>::value;
//     int f1 = Factorial<1>::value;
    int f0 = Factorial<0>::value; // == 1 (already computed by Factorial<4>)

    //cout << f0 << " " << f1 << " " << f2 << " "  << f3 << " "  << f10 << endl;
    return 0;
}