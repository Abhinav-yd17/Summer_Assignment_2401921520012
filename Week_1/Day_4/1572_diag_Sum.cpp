#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0 , j = 0 ;
        int sum = 0 ;
        while(i<mat.size() && j < mat.size()){
        sum = sum + mat[i][j];
        i++;
        j++;
        }
       i = 0 ;
       j = mat.size()-1;
       while(i<mat.size()&&j>=0){
        if(i!=j){

         sum = sum + mat[i][j];
        }
         i++;
         j--;

       }
       return sum ;
        
    }
};