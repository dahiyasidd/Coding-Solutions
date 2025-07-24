#include<bits/stdc++.h>
using namespace std;


class Solution {
    int dp[101][101];
    int solve_RE(vector<vector<int>>& matrix, int i, int j){
        if( j<0 || j>=matrix[i].size()){
            return 1e9;
        }
        if(dp[i][j] !=-1) return dp[i][j];
        if(i ==matrix.size()-1) return dp[i][j] = matrix[i][j];
        int diagonally_left = matrix[i][j] + solve_RE(matrix,i+1,j-1);
        int diagonally_right = matrix[i][j] + solve_RE(matrix,i+1,j+1);
        int directly_below = matrix[i][j] + solve_RE(matrix,i+1,j);
        return dp[i][j] = min({diagonally_left,diagonally_right,directly_below});
    }

    int solve_Tabulation(vector<vector<int>>&matrix){
        int n = matrix.size();
          vector<vector<int>>dp(n,vector<int>(n+2,-1));
          for(int i = 1 ; i<=n ; i++){
             dp[0][i] = matrix[0][i-1];
          }
          for(int i = 0; i<n ; i++){
            dp[i][0] = 1e9;
           dp[i][n+1] = 1e9;
          }
      for(int i = 1 ; i< n ;i++){
        for(int j = 1 ; j<=n ; j++){
             dp[i][j] = matrix[i][j-1] + min({dp[i-1][j] , dp[i-1][j-1] , dp[i-1][j+1]});
        }
      }
      return *min_element(dp[n-1].begin(), dp[n-1].end());
    }

    int solve_SpaceOptimized(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev = matrix[0];  // First row

    for (int i = 1; i < n; ++i) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j) {
            int up = prev[j];
            int left = (j > 0) ? prev[j - 1] : 1e9;
            int right = (j < n - 1) ? prev[j + 1] : 1e9;
            curr[j] = matrix[i][j] + min({up, left, right});
        }
        prev = curr;  // Move to next row
    }

    return *min_element(prev.begin(), prev.end());
}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int mini = INT_MAX;
        // memset(dp,-1,sizeof(dp));
        // for(int i = 0 ;i<matrix.size(); i++){
        //  mini = min(mini,solve_RE(matrix,0,i));
        // }
        // return mini;
        // return solve_Tabulation(matrix);
        return solve_SpaceOptimized(matrix);
    }
};