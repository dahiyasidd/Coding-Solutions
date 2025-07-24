#include<bits/stdc++.h>
using namespace std;


class Solution {

    int solve_RE(int i , int j ,vector<vector<int>>& obstacle, int& rows, int& cols){
        if(i<0 || j<0 || i>=rows|| j>=cols || obstacle[i][j] ==1) return 0;
        if(i ==rows-1 && j==cols-1 ) return 1;
        
        // move right
        int right = solve_RE(i,j+1,obstacle,rows,cols);

        // move down 
        int down = solve_RE(i+1,j,obstacle,rows,cols);
        return right + down ;
    }
    int solve_Tabulation(vector<vector<int>>&obstacle){
         
         int rows = obstacle.size();
         int cols = obstacle[0].size();
         vector<vector<int>>dp(rows,vector<int>(cols,0));
         // -1 means not visited yet 
         for(int i = 0; i< rows ; i++ ){
          if(obstacle[i][0] == 0)
                {dp[i][0] = 1;}
                else break;
            
         }

       for(int i = 0; i<cols ;i++){
        if(obstacle[0][i] ==0){
            dp[0][i] = 1;
        }
        else{
            break;
        }
       }
dp[0][0] = 1;
       for(int i = 1 ; i<rows ; i++){
        for(int j = 1; j<cols ; j++){
            if(!obstacle[i][j]){
                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
       }
       return dp[rows-1][cols-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         
         if(obstacleGrid[0][0] ==1) return 0;
         int rows = obstacleGrid.size();
         int cols = obstacleGrid[0].size();
         return solve_RE(0,0,obstacleGrid,rows,cols);
        // return solve_Tabulation(obstacleGrid);
    }
};