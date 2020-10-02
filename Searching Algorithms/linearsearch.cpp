//Name: Atreyo Mandal
//Proff: Student at SNU,Kolkata,West Bengal,India
// Lang: C++

#include <iostream>
using namespace std;
int main() {
   int search, c, n=6;
   int arr[] = { 12, 35, 69, 74, 165, 54};
   search=165;
   for (c = 0; c < n; c++) {
      if (arr[c] == search) {
         printf("%d is present at location %d.\n", search, c+1);
         break;
      }
   }
   if (c == n)
      printf("%d isn't present in the array.\n", search);
   return 0;
}
