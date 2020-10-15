//tokenisation using 'strtok()'.

#include<iostream>
#include<cstring>
using namespace std;

//char *strtok(char *s,char *delimiters)
// returns a token on each subsequent call
// on first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as null

int main()
{
    char s[100] = "today is a rainy day";

    char *ptr = strtok(s," ");
    //return addres of first token in array till " "
    cout<<ptr<<endl;//first word.

    ptr = strtok(NULL," ");
    cout<<ptr<<endl;//it maintain the pointer at previous state
    while(ptr!=NULL)
    {
        ptr = strtok(NULL," ");
        cout<<ptr<<endl;
    }
    //wecan use "a"at place of " " then it will tokenise string at 'a' character

    return 0;
}
