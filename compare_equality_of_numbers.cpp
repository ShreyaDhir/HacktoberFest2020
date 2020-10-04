/* This program compares the equality of three numbers given by the user */
// This program uses a function named equality which compares the value of the entered numbers


#include<iostream>
using namespace std;

int equality(int a, int b, int c)
{   
        if(a==b && b==c)
            return 3;
    else 
        if(a==b || b==c)
            return 2;
    else
            return 0;
}

int main()
{   
    system("cls");
    int a,b,c,count;
    cout<<"Enter three values: ";
    cin>>a>>b>>c;
    count = equality(a, b, c);
    cout<<"\nTotal number of equal values is "<<count<<endl;
    system("pause");
    return 0;
}