//implimanting our own tokeniser function.
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

char *mystrtok(char *str, char delim)
{
    //string and single char acts as deliminator
    static char *input= NULL;
    if(str!=NULL){
        input=str;
    }
    //check base case after final token has bin returned
    if(input==NULL){
        return NULL;
    }
    //start extracting tokens and store in an array.
    char *output = new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++)
    {   //copy till deliminator
        if(input[i]!=delim){
            output[i] = input[i];
        }
        else{
            output[i]='\0';
            input = input +i+1;//shift to next token
            return output;
        }
    }

    //corner case
    output[i]='\0';
    input=NULL;
    return output;
}

int main()
{
    char s[100] = "today is a rainy day";

    char *ptr = mystrtok(s,' ');
    //return addres of first token in array till " "
    cout<<ptr<<endl;//first word.

    ptr = mystrtok(NULL,' ');
    cout<<ptr<<endl;//it maintain the pointer at previous state
    while(ptr!=NULL)
    {
        ptr = mystrtok(NULL,' ');
        cout<<ptr<<endl;
    }
    //wecan use "a"at place of " " then it will tokenise string at 'a' character
    char s1[] = "CobingBlocks";
         char s2 = 'B';
         char *ptr = strchr( s1, s2);
         cout << ptr;
    return 0;
}
