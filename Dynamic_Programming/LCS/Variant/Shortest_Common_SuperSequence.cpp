/*
Given two strings str1 and str2, the task is to find the length of the shortest string that has
both str1 and str2 as subsequences.

subsequence must maintain order

a=AGGTAB
b=GXTXAYB
supersequence: AGGXTXAYB
length=9

Basically Longest common subsequence will be  in ans(GTAB) + extra characters
so ans is : LCS length + extra char of every string
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = (n + m) - dp[n][m];

    cout << "Shortest common supersequence size length = " << len << endl;
}
/*
AGGTAB
GXTXAYB

Shortest common supersequence size length = 9
AGGXTXAYB
*/



//Priting the shortest common supersequence string
 int n = str1.size(), m = str2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1]; 
                }
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    //Got My LCS Length;

    //Now it's time to get supersequence string

    string ans = "";

    int i = n, j = m;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            ans+=str1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=str1[i-1];
            i--;
        }
        else
        {
            ans+=str2[j-1];
            j--;
        }
    }
    while(i>0){
        ans+=str1[i-1];
        i--;
    }
    while(j>0){
        ans+=str2[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;

