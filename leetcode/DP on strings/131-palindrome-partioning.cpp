#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// generate a 2d array to store the indices dp[i][j] means substring form index i to j is palindrome or not
vector<vector<bool>> checkPalindrome(string& s){
     int n = s.length();
     vector<vector<bool>>dp(n , vector<bool>(n,false));

     // diagonal elements as true as 1 length substr are always palindrome 
     for(int i = 0; i< n ; i++){
           dp[i][i] = true;
     }

     for(int L = 2; L<=n ; L++){
         for(int i = 0; i< n+1 - L ; i++){
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


void solve_RE(string& s, int i , vector<string>&part, vector<vector<string>>&result, vector<vector<bool>>&dp){
      
       if(i ==s.length()){
            result.push_back(part);
            return;
       }

       for(int j = i ; j<s.length(); j++){
           if(dp[i][j]){
             part.push_back(s.substr(i,j-i+1));
             solve_RE(s,j+1 , part,result,dp);
             part.pop_back();
           }
       }
}
    vector<vector<string>> partition(string s) {
        
        vector<vector<bool>>dp = checkPalindrome(s);
        vector<string>part;
        vector<vector<string>>result;
        solve_RE(s,0,part,result,dp);
        return result;

    }
};