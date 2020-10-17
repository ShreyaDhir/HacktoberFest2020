#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) 
{
    bool is_col = false;
    int r = matrix.size();
    int c = matrix[0].size();
    for(int i = 0; i < r; ++i)
    {
        if(matrix[i][0] == 0) is_col = true;
        for(int j = 1; j < c; ++j)
        {
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < r; ++i)
        for(int j = 1; j < c; ++j)
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    if(matrix[0][0] == 0)
        for(int j = 0; j < c; ++j)
            matrix[0][j] = 0;
    if(is_col)
        for(int i = 0; i < r; ++i)
            matrix[i][0] = 0;
}