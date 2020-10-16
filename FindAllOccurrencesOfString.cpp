/*This program uses two strings and checks all the instances where the second string appears in first string (may be jumbled) 
*and returns the indices wherever the second string is present 
*/


#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Function to check all occurences of s2 in s1
void check(string &s1, string &s2){
   if(s2.length()>s1.length())
    {
       cout<<"Not possible";
    }
      int n= s2.length();
      sort(s2.begin(), s2.end());
    for(int i=0;i<=s1.size()-n;i++){
          string s3 = s1.substr(i, n);
          sort(s3.begin(), s3.end());
           if(s3 == s2)
            cout<<"Substring "<<s1.substr(i,n)<<" present at " <<"index "<<i<<"\n";
}
}


int main() // main function
{
string S1, S2;
cin>>S1>>S2;
  check(S1,S2);
  return 0;
}
