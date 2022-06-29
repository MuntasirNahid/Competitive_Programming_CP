/*
https://www.youtube.com/watch?v=1OkZKjxRokU&ab_channel=ApnaCollege

The N Queen is the problem of placing N chess queens
on an N×N chessboard so that no two queens attack each other.
Queen can move in any direction

we dont have to check right,or down side.we just have to check left and upper size

if we want to place the queen in a row,we dont have to check that row too..because in every row there will be only one queen.

*/
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &arr, int x, int y, int n)
{

    // column safe check
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1) // already have a queen in this column
        {
            return false;
        }
    }
    int row = x, col = y;
    // upper left diagonal//row kome,column kome
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x, col = y;
    // upper right diagonal// row kome,column bare
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(vector<vector<int>> &arr, int x, int n)
{
    // base case
    if (x >= n) // queen is placed in every row
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1; // queen place

            // if I place queen in this place,then I have to check if it is
            // possible to place rest queen in other row
            if (nQueen(arr, x + 1, n)) // next row gulakey pathalam
            {
                return true;
            }
            // else
            arr[x][col] = 0; // backtrack // queen boshano jaynai porer step gulatey.. that's why eikhane amra queen boshabo na
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0; // chessboard
        }
    }
    if (nQueen(arr, 0, n)) // if returns true
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    cout<<"Solution is not possible!"<<endl;
}
//Time Complexity: O(N ^2)

/*
4
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0
*/