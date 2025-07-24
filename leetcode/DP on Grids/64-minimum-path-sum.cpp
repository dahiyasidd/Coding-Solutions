#include<bits/stdc++.h>
using namespace std;

class Solution {

int dp[201][201];
    int solve_RE(int i , int j , vector<vector<int>>& grid , int rows , int cols){
         if(i<0 || j<0 || i>=rows || j>=cols){
            return dp[i][j] = 500;
         }
         if(dp[i][j] != -1) return dp[i][j];
         if(i ==rows-1 && j==cols-1) return dp[i][j] =  grid[i][j];
         // move down 
         int down = grid[i][j] + solve_RE(i+1,j,grid,rows,cols);
         // move right
         int right = grid[i][j] + solve_RE(i,j+1,grid,rows,cols);
         return dp[i][j] =  min(down , right);
    }
    int solve_Tabulation(vector<vector<int>>&grid){
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols,0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i<rows ; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i = 1; i<cols ; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int i = 1; i<rows ; i++){
            for(int j = 1; j<cols; j++){
                 dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[rows-1][cols-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //  int rows  = grid.size();
        //  int cols =grid[0].size();
        //  memset(dp,-1,sizeof(dp));
        //  return solve_RE(0,0,grid,rows,cols);
        return solve_Tabulation(grid);
    }
};