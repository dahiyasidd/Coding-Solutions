#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dp[201][201];
int solve_RE( vector<vector<int>>&traingle, int row_number, int col_number){
    if(row_number >=traingle.size() || col_number>=traingle[row_number].size()) return  dp[row_number][col_number] =  0;
     
     if(dp[row_number][col_number]!=-1){
        return dp[row_number][col_number];
     }
     // same index number 
      int same = traingle[row_number][col_number] + solve_RE(traingle,row_number+1,col_number);
      // next index;
      int next = traingle[row_number][col_number] + solve_RE(traingle,row_number+1, col_number+1);

   return dp[row_number][col_number] = min(same,next);      

}

int solve_Tabulation(vector<vector<int>>triangle){
    int n = triangle.size();

     vector<vector<int>>dp(n , vector<int>(n,0));
     // last wali row ko same rakho triangle wali row ke 
 for( int j = 0 ; j< n ; j++){
      dp[n-1][j] = triangle[n-1][j];
 }
     for(int i = n-2 ; i>= 0 ; i--){
          for(int j =triangle[i].size()-1; j>=0 ; j--){
                     dp[i][j] = triangle[i][j] + min(dp[i+1][j] , dp[i+1][j+1]);
                  }
     }
     return dp[0][0];

}

    int minimumTotal(vector<vector<int>>& triangle) {
    //     memset(dp,-1,sizeof(dp));
    //    return solve_RE(triangle,0,0);
        return solve_Tabulation(triangle);
   
    }
};

