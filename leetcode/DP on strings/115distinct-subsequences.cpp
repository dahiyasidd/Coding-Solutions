#include<bits/stdc++.h>
using namespace std;

 const int M = 1e9 + 7;
class Solution {

    int dp[1001][1001];
    int solve_RE(string& s, string&t , int i, int j){
          if( j>=t.length()) return dp[i][j] = 1;
         if(i>=s.length() ) return dp[i][j] = 0;
       

   if(dp[i][j] !=-1) return dp[i][j];
// include // 
int include = 0;
if(s[i] == t[j])
 {  
     include =  solve_RE(s,t,i+1,j+1);
 
 }
  // exclude 
  int exclude =  solve_RE(s,t,i+1,j);

      return dp[i][j] = include + exclude;    

    }

    int solve_Tabulation(string& s, string& t){
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // akhiri row hogi 0 aakhiri column hoga 1
        for(int j = 0 ; j<=m ; j++){
            dp[n][j]= 0;
        }
        for(int j = 0 ; j<=n ; j++){
            dp[j][m]= 1;
        }
        for(int i = n-1; i>=0 ; i--){
               for(int j = m-1;j>=0; j--){
               int sum = 0;
               if(s[i] ==t[j]){
                dp[i][j] = (dp[i+1][j+1] + dp[i+1][j])%M;
               }
              else  dp[i][j] =dp[i+1][j];
               }
        }
return dp[0][0];
    }
public:
    int numDistinct(string s, string t) {
    //     memset(dp,-1,sizeof(dp));
    //    return solve_RE(s,t,0,0);
    return solve_Tabulation(s,t);
    }
};