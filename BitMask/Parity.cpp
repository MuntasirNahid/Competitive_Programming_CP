/*
Parity: Parity of a number refers to whether it contains an odd or even number of 1-bits.
The number has “odd parity”,if it contains odd number of 1-bits and
is “even parity” if it contains even number of 1-bits.
*/
/*
Initialize: n = 13 (1101)   parity = 0

n = 13 & 12  = 12 (1100)   parity = 1
n = 12 & 11 = 8  (1000)   parity = 0
n = 8 & 7 = 0  (0000)    parity = 1
*/

#include <bits/stdc++.h>
using namespace std;
// Function to get parity of number n. It returns 1
// if n has odd parity, and returns 0 if n has even
// parity
bool findParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}
int main()
{
    unsigned int n;
    cin >> n;
    cout << "parity of " << n << " is = " << (findParity(n) ? "odd" : "even");
    // parity of 7 is = odd
}