/*
Suppose you have an array A and an integer. You can divide this array in some ways. 
The condition is that the result of the division is not equal to k.
 The array has to be divided into as few divisions as possible, and even if it is not possible, it has to be said.

*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7 ios::sync_with_stdio(0);cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
using namespace std;
ll t,n,i,j,k,a,b,c,d,p,q,r,x,y,z,m,cnt,ans;
bool flag;
string s,s2;

void nahid()
{
    cin>>n>>k;
    vector<ll>v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    ll mx=*max_element(v.begin(),v.end());
    if(mx>k)
    {
        cout<<"NO Solution"<<endl;
        return;

    }
    ans=0;cnt=0;
    for(i=0;i<n;i++)
    {
        
        if(cnt+v[i]<=k)
        {
            cnt+=v[i];

        }
        else
        {
            cnt=0;
            ans++;
            cnt+=v[i];
        }
    }
    cout<<"We can split the array "<<ans<<" times"<<endl;
    
    
}
int main()
{
    MN7;
    nahid();
}

/*
7 15
12 1 5 6 7 2 3


We can split the array 2 times
*/


//2

/*
Split array into minimum number of subsets having difference between maximum and minimum element at most K
*/

/*
Input: arr[] = {1, 2, 3, 4, 5}, K = 2 
Output: 2
Explanation:
The given array can be divided into two sets {1, 2, 3} having the difference between maximum and minimum as 3 – 1= 2 and {4, 5} having the difference between maximum and minimum as 5 – 4 = 1.
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7 ios::sync_with_stdio(0);cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
using namespace std;
ll t,n,i,j,k,a,b,c,d,p,q,r,x,y,z,m,cnt,ans;
bool flag;
string s,s2;

void nahid()
{
    cin>>n>>k;
    vector<ll>v(n);
    for(i=0;i<n;i++)
    cin>>v[i];

   ll st=0,en=0;
   ans=1;
    while(en<n)
    {
        if(abs(v[en]-v[st])<=k)
        {
            en++;
        }
        else
        {
            ans++;
            st=en;
        }
    }
    cout<<"We can have "<<ans<<" subset."<<endl;
    
    
}
int main()
{
    MN7;
    nahid();
}

/*
5 2
1 2 3 4 5 

We can have 2 subset.

*/

