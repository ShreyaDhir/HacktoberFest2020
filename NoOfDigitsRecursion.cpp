#include<iostream>
using namespace std;

// int countDigits(int n){

//     static int c = 1;
     

// if(n/10==0) return c;
// else
// {
//     c++;
//     return countDigits(n/10);
// }



// }
int countDigits(int n){

    
     

if(n==0) return 0;

    return 1 + countDigits(n/10);
}




int main(int argc, char const *argv[])
{
    cout<<countDigits(300);
    cout<<countDigits(3000);

    return 0;
}
