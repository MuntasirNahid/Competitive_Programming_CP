/*
https://www.youtube.com/watch?v=D7AFvtnDeMU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=32&ab_channel=AdityaVerma

Matrix chain multipication

variation:
---------
1)printing mcm
2)Evaluate Expression to TRUE/Boolean Parentheses 
3)Min/max value of expression
4)palindrome partitioning
5)scramble string
6)egg dropping problem

Identification + Format:
------------------------
string or array available
string or array  breaking feeling
for(i,j)-> i=left end/side, k=somewhere between i-j ,j=right end/side
    for(i,k),for(k+1,j)->temporary answer(many time break,many temp answer)
        ->will have to count final answer from temp answers


general format:solve(int arr[],int i,int j){
    if(i>j)
    return 0;
    for(int k=i;k<j;k++)//k start or end varies for different problem..it's a formate
    {
        calculating temporary ans:
    temp_ans=solve(arr,i,k)+(solve(arr,k+1,j));
    /* ||&& * anything  -*/
    ans=function(temp_ans)//max,min,bla blah
    }
}





