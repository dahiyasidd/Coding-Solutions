#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
bool checkPalindrome(string& s, int i , int j ,vector<vector<int>>&dp){
    if(i>j) return true;

     if(dp[i][j] !=-1){
    return dp[i][j];
                }
    if(s[i] ==s[j]){
        return dp[i][j] = checkPalindrome(s,i+1,j-1,dp);
                }
    else {
        return dp[i][j] = false;
    }
}

int solve_Memoization(string &s ){

int len = s.length();
vector<vector<int>>dp(len+1, vector<int>(len+1,-1));
int count = 0;
    for(int i = 0; i< len ; i++){
        for(int j = i ;j <len ; j++){
            if(checkPalindrome(s,i,j,dp)){
                count++;
            }
        }
    }
    return count;
}

int solve_Tabulaion(string& s){
    int n = s.length();
    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    int count_1s = n;
    // dp[i][j] means that we substring from i  to j is palindrome or not
    for(int i = 0; i<n+1; i++){
        dp[i][i] = 1;
       
    } 
    for(int len = 2; len <n+1; len++){
        for(int i = 0; i<n+1 - len ; i++){
             int j =  i + len -1;
                if(s[i] ==s[j] && i+1 ==j){
                    dp[i][j] = 1;
                   
                }
                else if(s[i] ==s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1];
                    
                }
          count_1s += dp[i][j];
        }
    }
    return count_1s;
}
    int countSubstrings(string s) {


    //   return solve_Memoization(s);   
    return solve_Tabulaion(s);
    }
};


// is sawal ke pattern ko ratt lena hai 
// dp[i][j] means i se lekar j ke beech wali substring palindrome hai ya nahi 
