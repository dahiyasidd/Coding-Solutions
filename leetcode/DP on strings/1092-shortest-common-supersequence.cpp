#include<bits/stdc++.h>
using namespace std;

class Solution {
    int longest_common_subsequence(string& s1 , string& s2, int i , int j, vector<vector<int>>&dp){
          
          if(i>=s1.length() || j>=s2.length()) return 0;
          if(dp[i][j] != -1) return dp[i][j];

          if(s1[i] ==s2[j]){
            return dp[i][j] = 1+ longest_common_subsequence(s1,s2,i+1,j+1,dp);
          }
          else {
              int include_i = longest_common_subsequence(s1,s2,i+1,j,dp);
              int include_j = longest_common_subsequence(s1,s2,i,j+1,dp);
              return dp[i][j] = max(include_i , include_j);
          }
     
    }
public:
string removeOccurence(string& parent , string& subseq){
    string ans;
    int i = 0; int j = 0;
    while(i<parent.length() && j < subseq.length()){
        if(parent[i] != subseq[j]){
            ans.push_back(parent[i]);
            i++;
        }
        else {
            i++; j++;
        }
    }
    while(i<parent.length()){
        ans.push_back(parent[i]);
        i++;
    }
        return ans;
}
     string longest_common_subsequence_Tab(string& str1, string& str2){
        int n = str1.length();
        int m = str2.length();
          vector<vector<int>>dp(n+1, vector<int>(m+1,0));
          for(int i = 1; i<n+1 ; i++){
            for(int j = 1 ; j<m+1 ; j++){
                if(str1[i-1] ==str2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
          }
          int len_of_lcs =  dp[n][m];
          int k =m+n - len_of_lcs-1;
          string lcs(m+n -len_of_lcs, '0');
          int i = n , j = m;
          while(i>0 && j>0){
            if(str1[i-1] ==str2[j-1]){
                lcs[k--] = str1[i-1];
                i-- ; j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]){
                    lcs[k--] = str1[i-1];
                    i--;
                }
                else {
                    lcs[k--] = str2[j-1];
                    j--;
                }
            }
          }
          while(i>0){
               lcs[k--] = str1[i-1];
               i--;
          }
          while(j>0){
              lcs[k--] = str2[j-1];
              j--;
          }
          return lcs;
     
     }
    string shortestCommonSupersequence(string str1, string str2) {
        
        // vector<vector<int>>dp(str1.size() , vector<int>(str2.size(), -1));
        // int lcs_length = longest_common_subsequence(str1,str2,0,0,dp);
        int n = str1.length();
        int m = str2.length();
        string lcs = longest_common_subsequence_Tab(str1,str2);
        // string newStr1 = removeOccurence(str1,lcs);
        // string newStr2 = removeOccurence(str2,lcs);
        // return (newStr1 + lcs+ newStr2 );
        return lcs;
    }
};