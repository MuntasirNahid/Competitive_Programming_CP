/*
https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=34&ab_channel=AdityaVerma
Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The problem is not actually to perform the multiplications,
but merely to decide in which order to perform the multiplications.

Have many matrix,we have to multiply them with each other in minimum cost.here cost is number of multiplication

imagine :
a= 2*3 matric and b=3*6 matrix
now multiplication cost will be=2*3*6=36

using different parentheses combination we will find different cost,here we want the minimun of them

a=10*30 ,b=30*5,c=5*60

(ab)c=4500
a(bc)=2700
both of them are temporary answer.
ans =min(4500,2700)=2700

number of matrix=array size-1;
arr[]=2 3 4 5
a=2*3,b=3*4,c=4*5
which means ,Ai=arr[i-1]*arr[i]
step:
1)Find i,j value:

so in start,
i=1 and j=n-1
because if i=0 then i-1=-1 which is invalid

2)find proper basecase:
base case:
when i>j this means size=0
when i==j this means size =1.which will also return zero.because we cannot form a matrix from this. as arr[i-1]*arr[i]

3)Move k ->i to j

if(k=i;k<j)then in last iteration i->k matrix will be okay but k+1->j matrix will be empty
so(k=1;k<j-1) will be appropriate

recursion calls will give us temporary cost.then we have to manually calculate the final cost.

example:
40 20 30 10 30
i=1,k=2,j=4
temporary ans will give the multiplication cost of (A*B)  and (C*D).final cost will give the cost of multiplying AB  with CD
(AB)(CD)=40*30 _ 30*30
    cost=40 * 30 *30
so final cost=arr[i-1]*arr[k]*arr[j];
so for one  iteration final_temporary_ans=temp_ans + final cost

ans will be minimum of these final_temporary_ans
*/

#include <bits/stdc++.h>
using namespace std;
int Find_MCM(int arr[], int i, int j)
{
    // base case:
    if (i >= j)
        return 0;

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_sum = Find_MCM(arr, i, k) + Find_MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, temp_sum);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = Find_MCM(arr, 1, n - 1);
    cout << "Minimum number of Multiplication needed = " << ans << endl;
}
/*
5
40 20 30 10 30

output:
Minimum number of Multiplication needed = 26000
*/