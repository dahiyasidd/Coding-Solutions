#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int mincuts_dp[2001];
 int MiniCuts(string& s, int i , vector<vector<bool>>&dp){
    if(i==s.length()) return mincuts_dp[i] = 0;
    int miniCuts = s.length();
     if(mincuts_dp[i] != -1) return mincuts_dp[i];
    for(int j = i ; j<s.length() ; j++){
            if(dp[i][j]){
                int cuts = 1 + MiniCuts(s,j+1,dp);
                miniCuts = min(miniCuts, cuts);
            }
    }
    return mincuts_dp[i] = miniCuts;
 }

vector<vector<bool>>checkPalindrome(string& s){
    int n = s.length();
     vector<vector<bool>>dp(n , vector<bool>(n,false));

     for(int i=0; i<n ; i++){
       dp[i][i] = true;
     }
      for(int L = 2; L <=n ; L++){
        for(int i = 0; i<n+1-L ; i++){
            int j = i+L-1;
            if(s[i] ==s[j]){
                   if(L ==2){
                    dp[i][j] = true;
                   }
                   else {
                     dp[i][j] = dp[i+1][j-1];
                   }
            }

        }
      }
      return dp;
}
    int minCut(string s) {
        
        memset(mincuts_dp,-1,sizeof(mincuts_dp));
        vector<vector<bool>>dp = checkPalindrome(s);
  return MiniCuts(s,0,dp)-1;
    }
};