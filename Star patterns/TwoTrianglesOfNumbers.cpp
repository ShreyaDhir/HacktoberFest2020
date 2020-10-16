#include <iostream>
using namespace std;
//Code for pattern of two triangles
int main(){
 for(int i=1;i<=7;i++) // Printing inverted triangle
 {
  for(int j=1;j<i;j++)
   cout<<" ";

for(int j =i;j<=7;j++)
   cout<<j<<" ";
   
   cout<<"\n";
}
 for(int i=6;i>=1;i--){  //Printing erect triangle
     
     for(int j=i-1;j>0;j--)
     cout<<" ";
     for(int j=i;j<=7;j++)
         cout<<j<<" ";
         cout<<"\n";
     }
}
