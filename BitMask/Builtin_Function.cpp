#include <bits/stdc++.h>
using namespace std;
int main()
{
    //__builtin_popcount(x):This function is used to count the number of one’s(set bits) in an integer.
    /*
    if x = 4
    binary value of 4 is 100
    Output: No of ones is 1
    */
    int n;
    cin >> n;
    cout << "Number of One in Binary Representation " << __builtin_popcount(n) << endl;

    // Note: Similarly you can use __builtin_popcountl(x) & __builtin_popcountll(x) for long and long long data types.

    /*
    __builtin_parity(x): This function is used to check the parity of a number.
    This function returns true(1) if the number has odd parity else it returns false(0) for even parity.
    */
    cout << "Parity Bit " << __builtin_parity(n) << endl;

    // Note: Similarly you can use __builtin_parityl(x) & __builtin_parityll(x) for long and long long data types

    //__builtin_clz(x): This function is used to count the leading zeros of the integer. Note : clz = count leading zero’s
    // Example: It counts number of zeros before the first occurrence of one(set bit).

    // a = 16
    // Binary form of 16 is 00000000 00000000 00000000 00010000
    // Output: 27

    cout << "Leading Zeroes = " << __builtin_clz(n) << endl;

    /*
    Note: __builtin_clz(x) This function only accept unsigned values
    Note: Similarly you can use __builtin_clzl(x) & __builtin_clzll(x) for long and long long data types.
    */

    //__builtin_ctz(x):This function is used to count the trailing zeros of the given integer. Note : ctz = count trailing zeros.
    // Example: Count no of zeros from last to first occurrence of one(set bit).

    /*
    a = 16
    Binary form of 16 is 00000000 00000000 00000000 00010000
    Output: ctz = 4
    */

    cout << "Trailing Zeroes = " << __builtin_ctz(n) << endl;
}