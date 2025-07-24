#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// tc: O(2^(m+n))
// int dp[101][101];
// int solve_RE(int i , int j , int m, int n){
//       if( i<0 || i>= m || j<0|| j>=n) return dp[i][j] = 0;
//       if(i==m-1 && j==n-1) return dp[i][j] = 1;
//       if(dp[i][j] !=-1) return dp[i][j];
//       // move right 
//       int right =  solve_RE(i,j+1,m,n); 
//       // move down 
//       int down = solve_RE(i+1 , j, m , n);
//       return dp[i][j] = right + down;
// }

int solve_Tabulation(int& m, int& n){
   vector<vector<int>>dp(m,vector<int>(n,-1));
   // dp[i][j] ka pehla row or pehla col 1 hona chaiye 
   // dp[i][j] means ways to reach at i,j
   for(int i = 0 ; i< m ; i++){
        dp[i][0] = 1;
   }
   for(int i = 0 ; i<n ; i++){
    dp[0][i] = 1;
   }
dp[0][0] = 0;
   for(int i = 1 ; i<m ; i++){
    for(int j = 1 ; j<n ; j++){
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
   }
   return dp[m-1][n-1];

}
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve_RE(0,0,m,n);
        return solve_Tabulation(m,n);
    }
};