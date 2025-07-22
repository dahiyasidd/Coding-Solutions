#include<bits/stdc++.h>
using namespace std;
class Solution {
    int longest_common_subsequence(string &s, string& rev){
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        // dp[i][j] means length of longest common subsequence till length i of s and j of rev
        for(int i = 1; i<n+1 ; i++){
            for(int j = 1; j<n+1; j++){
                if(s[i-1] ==rev[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
public:
    int minInsertions(string s) {
        // find the longest common subsequence of the string and its reverse then subtract it from the length of the string 
        // this will give us the number of characters we need to insert further to make the string a palindrome 

     int n = s.length() ;   // length of the string s 
     string rev; 
      for(int i = n-1 ; i>=0 ; i--)
      {
        rev.push_back(s[i]);
      }
        int lcs = longest_common_subsequence(s,rev);
        return n - lcs;
    }
};
