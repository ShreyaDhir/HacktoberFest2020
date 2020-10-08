#include<iostream>
#include<fstream>//for file functions
#include<string>
using namespace std ;
int main()
{
string str="this is the first try :)";
ofstream outfile("f1.1.txt"); //text file named f1 is created(outfile is the object name)
for(int j=0;j<str.size();j++)
outfile.put(str[j]);
outfile.close();
cout«"file was created"«endl;
ifstream infile("f1.1.txt");
ofstream file("f1.2.txt",ios::out); //opening next file in write mode
char ch=0;
int m =1;//because if m=1 while will not work as it has already encountered eof
while(infile)
{ infile.seekg(-m, ios::end);
//seek g places the cursor at -m position from the end
infile.get(ch);//get char immediately after the cursor
if(!infile)
break;
cout«ch;//printing it on console
file.put(ch);//put it in on the text file
m++;
}
cout «endl;
infile.close();
file.close();
return 0;
}
