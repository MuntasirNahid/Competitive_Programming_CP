// Decimal to any other Base or Any other base to decimal:
#include <bits/stdc++.h>
using namespace std;

int Convert_To_Decimal(string s, int base)
{
    int power = 1, n = 0;
    for (int i = s.size() - 1; i <= 0; i--)
    {
        n += (s[i] - '0') * power;
        power *= base;
    }
    return n;
}

string BaseConvert(int n, int base)
{
    if (n == 0)
        return "0";
    int x = 0, power = 1, k;
    string d;
    while (base * power <= n)
    {
        power *= base;
        x++;
    }
    while (n > 0)
    {
        k = n / power;
        d += k + '0';
        n -= (k * power);
        power /= base;
    }
    if (d.size() < x)
    {
        while (d.size() < x)
        {
            d += '0';
        }
    }
    return d;
}

int main()
{

    int i, base, n;
    cin >> n >> base;
    string s = BaseConvert(n, base);
    cout << "In Base 10 = " << n << endl
         << "In "
         << " Base " << base << " =" << s << endl;
}

//If we want to find LSB we just have to do : x&1
//If we want to find i-th(0 based indexing) bit of x: (x>>i)&1

//a+b=(a|b)+(a&b);

//