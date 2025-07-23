#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    int solve_RE(string& word1 , string& word2, int i , int j , vector<vector<int>>&dp){
        if(i >= word1.size()){
            return word2.size() - j;  // insert the remaining elements from word2
        }
        else if(j>= word2.size()){
            return word1.size() - i; // delete the remaining elements form word1
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i] ==word2[j]){
            return dp[i][j] = solve_RE(word1, word2 , i+1, j+1,dp);
        }
        else {
            int insert = 1+ solve_RE(word1 , word2 , i , j+1,dp);
            int deleted = 1 + solve_RE(word1, word2 , i+1, j,dp);
            int replace =1+ solve_RE(word1 , word2 , i+1 , j+1,dp);
            return dp[i][j] =  min({insert,deleted, replace}); 
        }
    }
    

    int solve_Tabulation(string& word1, string& word2){
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i = 0; i<n+1 ; i++){
               dp[i][0] = i;
        }
        for(int i = 0; i<m+1 ; i++){
            dp[0][i] = i;
        }
dp[0][0] = 0;
        for(int i = 1; i<n+1; i++){
            for(int j = 1;j<m+1 ; j++){
                if(word1[i-1] ==word2[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int replace = 1+dp[i-1][j-1];
                    int deleted = 1+ dp[i-1][j];
                    int insert = 1+dp[i][j-1];
                    dp[i][j] =min({replace,deleted,insert});
                }
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        
        // int n = word1.size();
        // int m = word2.size();
        // vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
        // return solve_RE(word1 , word2 , 0 , 0,dp);
        return solve_Tabulation(word1 , word2);
    }
};