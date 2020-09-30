// binary_search C++
#include <iostream>     
#include <algorithm>    
#include <vector>     

bool myfunction (int i,int j) { return (i<j); }

void merge(vector<int> a, int low, int m, int high){
  vector<int> left,right;
  for(int i=low;i<=m;i++)
    left.push_back(a[i]);
  for(int i=m+1;i<=high;i++)
    left.push_back(a[i]);
  
  int i=0;
  int j=0;
  for(int k=low;k<=high;k++){
    if(i==left.size()){
      a[k] = right[j++];
    }
    else if(j==right.size()){
      a[k] = left[i++];
    }
    else if(left[i]<right[j]){
      a[k] = left[i++];
    }
    else{
      a[k] = right[j++];
    }
  }
  
  
}
void mySort(vector<int>a, int low, int high){
  if(low<high){
    int m = low+(high-low)/2;
    mySort(a,low,m);
    mySort(a,m+1,high);
    merge(a,low,m,high);
  }
}

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};
  std::vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1

  // using default comparison:
  std::sort (v.begin(), v.end());

  std::cout << "looking for a 3... ";
  if (std::binary_search (v.begin(), v.end(), 3))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  // using myfunction as comp:
  std::sort (v.begin(), v.end(), myfunction);

  std::cout << "looking for a 6... ";
  if (std::binary_search (v.begin(), v.end(), 6, myfunction))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  return 0;
}
