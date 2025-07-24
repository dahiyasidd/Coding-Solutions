#include<bits/stdc++.h>
using namespace std;

// very important and uses dp on strings 
class Solution {
    int solve_RE(string &text1 , string &text2 , int i , int j){
           
           if(i>=text1.length() || j>=text2.length()) return 0;

// this can be included in the answer 
           if(text1[i] == text2[j]){
                  return 1 + solve_RE(text1 , text2 , i+1 , j+1);
           }
           else {
              int take_i_skip_j = solve_RE(text1 , text2 , i , j+1);
              int take_j_skip_i = solve_RE(text1 , text2 , i+1 , j);
              return max(take_i_skip_j , take_j_skip_i);
           }
    }

        int solve_Memo(string &text1 , string &text2 , int i , int j,vector<vector<int>>& dp){
           
           if(i>=text1.length() || j>=text2.length()) return 0;
           if(dp[i][j]!=-1 ) return dp[i][j];

// this can be included in the answer 
           if(text1[i] == text2[j]){
                  return dp[i][j] = 1 + solve_Memo(text1 , text2 , i+1 , j+1, dp);
           }
           else {
              int take_i_skip_j = solve_Memo(text1 , text2 , i , j+1,dp);
              int take_j_skip_i = solve_Memo(text1 , text2 , i+1 , j, dp);
              return dp[i][j]= max(take_i_skip_j , take_j_skip_i);
           }
    }

    int solve_Tabulation(string& text1 , string& text2 ){
         int n = text1.length();
         int m = text2.length();
// dp[i][j] means s1 of length i and s2 of length j inki  longest common subsequence kya hai
         vector<vector<int>>dp(n+1 , vector<int>(m+1, 0));
             for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];   // by seeing the memoization code 
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
    }
    /*
      Time Complexity: O(n * m)
      Space Complexity: O(n * m)
    */

        int solve_Tabulation2(string& text1 , string& text2 ){
         int n = text1.length();
         int m = text2.length();
// dp[i][j] means s1 of length i and s2 of length j inki  longest common subsequence kya hai
         vector<vector<int>>dp(n+1 , vector<int>(m+1, 0));
         for(int i = 0; i<m+1 ; i++){
            dp[0][i] = 0;
         }
        for(int i = 0; i<n+1 ; i++){
            dp[i][0] = 0;
         }

             for(int i = 1; i < n+1; i++) {
        for(int j = 1; j <m+1; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];   // by seeing the memoization code 
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // return solve_RE(text1 , text2 , 0, 0);

        //    memset(dp, -1, sizeof(dp));
    // vector<vector<int>> dp(text1.size(), vector<int>(text2.size() ,-1));
    //     return solve_Memo(text1, text2, 0, 0, dp);

    // return solve_Tabulation(text1 , text2);
    return solve_Tabulation2(text1 , text2);
    }
};