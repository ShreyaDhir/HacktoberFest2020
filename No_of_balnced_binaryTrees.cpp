// To find the number of balanced binary trees of height h
#include<bits/stdc++.h>
using namespace std;

//Complexity of this code is Exponential : O(2^n); 
/* 
long long int countTrees(int h){

    if(h == 0){
        return 0;
    }
    if(h == 1){
        return 1;
    }
    if(h == 2){
        return 3;
    }

    int answer = pow(countTrees(h-1),2) + 2*countTrees(h-1)*countTrees(h-2);

    return answer;

}
 */

//MEMOISED CODE:
/* long long int countTrees(int h, int *arr){

    if(h == 0){
        return 0;
    }
    if(h == 1){
        return 1;
    }
    if(h == 2){
        return 3;
    }
    if(arr[h] > 0)return arr[h];

    int answer = pow(countTrees(h-1,arr),2) + 2*countTrees(h-1,arr)*countTrees(h-2,arr);
    arr[h] = answer;
    return answer;
}
 */


//Using DP tabulation
long long int countTrees(int h,int *dp){

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;


    for(int i=3;i<=h;i++){
        dp[i] = pow(dp[i-1],2) + 2*dp[i-1]*dp[i-2];
    }

    return dp[h];

}


int main(){

    //Answer of this code can be large so take modulo 10^9 + 7

    int h;
    cin>>h;
    int *arr = new int[h+1];

    for(int i=0;i<=h;i++){
        arr[i] = 0;
    }
    cout << countTrees(h,arr);

    delete [] arr;
}