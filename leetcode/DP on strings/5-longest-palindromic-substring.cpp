#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1001][1001];
public:

//   dp[i][j] = 0 , not palindrome 
//   dp[i][j] = 1 ,  palindrome 
//   dp[i][j] = 0 , not solved yet 


// memoization

//     bool isPalindrome(string &str, int i , int j ){
//         if(i>=j)  return dp[i][j] = true;
 
//  if(dp[i][j]!=-1) {
//     return dp[i][j];
//  }
//         if(str[i] ==str[j]){
//             return dp[i][j] =  isPalindrome(str,i+1,j-1);
//         }
//         return dp[i][j] = false;
//     }

//     string longestPalindrome(string s) {
//         int n = s.length();
//         int longestPalindromeLength = 1;
//         string ans = s.substr(0,1);
//     //   vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
//     memset(dp,-1,sizeof(dp));
//       for(int i = 0; i< n ; i++){
//           for(int j= i ; j< n ; j++){
//                if(longestPalindromeLength <(j-i+1) && isPalindrome(s,i,j) ){
//                 longestPalindromeLength = j-i +1;
//                     ans = s.substr(i,longestPalindromeLength);
//                } 
//           }
//       }
//  return ans;
//     }

    // tabulation

    string solve_Tabulation(string& s){
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // initialise the diagonal elements by 1
        for(int i = 0; i<n ; i++){
            dp[i][i] =1;
        }
       int maxLen = 1;
       int start_idx = 0;
        for(int len = 2 ; len < n+1; len++){
             for(int i = 0 ; i< n+1 - len ; i++){
                int j = i+ len-1;
                if(len==2 && s[i] ==s[j]){
                   dp[i][j] = 1;
                   if(maxLen <2){
                    start_idx = i;
                    maxLen = 2;
                   }
                } 
                else if(s[i] ==s[j] && dp[i+1][j-1] ==1) {
                    dp[i][j] = 1;
                    if(maxLen < j-i +1){
                        maxLen = j-i+1;
                        start_idx = i;
                    }
                }
                else {
                    dp[i][j] = 0;
                }
             }
        }
        return s.substr(start_idx,maxLen);
    }
string longestPalindrome(string s){
    return solve_Tabulation(s);
}


// brute force

    // bool isPalindrome(string &str, int i , int j){
    //     if(i>=j)  return true;
 
    //     if(str[i] ==str[j]){
    //         return  isPalindrome(str,i+1,j-1);
    //     }
    //     return  false;
    // }
    //     string longestPalindrome(string s) {
    //   // btute force
    //   int maxLen = 1;
    //   int n = s.length();
    //   string ans = s.substr(0,1);
    //   for(int i = 0; i<n; i++){
    //       for(int j = i+1; j<n; j++ ){
    //         if( j-i+1 > maxLen && isPalindrome(s,i,j) ){
    //             maxLen = j-i+1;
    //             ans = s.substr(i,maxLen);
    //         }
    //       }
    //   }
    //   return ans;
    // }
};