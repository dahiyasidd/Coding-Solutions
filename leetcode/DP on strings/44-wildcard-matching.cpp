#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[2001][2001];
    bool solve_RE(string& s, string& p, int i ,int j){
         if(i>=s.length() && j>=p.length()){
              return dp[i][j] = true;
         }
         if(j>=p.length() && i<s.length()) return dp[i][j] = false;
         if(s[i]!=p[j] && (p[j]!='?' && p[j]!='*')) return dp[i][j]= false;
            if(i>=s.length()){
  for(int k = j; k<p.length() ; k++){
     if(p[k]!='*') return dp[i][j] = false;
  }}
        
         if(s[i] == p[j] || p[j]=='?'){
            return dp[i][j]= solve_RE(s,p,i+1,j+1);
         }
      if(dp[i][j] !=-1) return dp[i][j];
         bool ans = false;
         if(p[j] =='*'){
            for(int select = 0 ; select<= s.length()-i; select++){
                bool temp =  solve_RE(s,p,i+select,j+1);
                ans = ans || temp;
            }
         }
         return dp[i][j]= ans;
    }
public:
    bool isMatch(string s, string p) {
       
        // if(s.empty() && isNotStar ) return false;
        memset(dp,-1,sizeof(dp));
        return solve_RE(s,p,0,0);
    }
};