/*
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[])
that prints all occurrences of pat[] in txt[]. You may assume that n > m.
*/
#include <bits/stdc++.h>
using namespace std;

void PatternSearch(char *pat, char *txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int j;
    for (int i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)

            if (txt[i + j] != pat[j])
                break;

        if (j == m)
            cout << "Pattern found at index : " << i << endl;
    }
}
int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    PatternSearch(pat, txt);
    return 0;
}
//The number of comparisons in the worst case is O(m*(n-m+1)).