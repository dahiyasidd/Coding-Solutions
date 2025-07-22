#include<bits/stdc++.h>
using namespace std;

class Solution {
 
    int solve_RE(vector<int>& nums, int i, int prev_taken_idx){         // TC O(2^n) SC O(n)
        if(i>=nums.size()){
            return 0; 
        }
       
       int take = 0;
       if(prev_taken_idx ==-1 || nums[i] >nums[prev_taken_idx]){
           take = 1+ solve_RE(nums,i+1,i);  // two variables are changing so 2D dp array will be used
       }
          int not_take = solve_RE(nums,i+1,prev_taken_idx);
          return max(take,not_take);
    }

    int solve_Memo(vector<int>& nums, int i, int prev_taken_idx, vector<vector<int>>&dp){    // TC O(n^2) SC O(n^2)
        if(i>=nums.size()){
            return 0; 
        }
       if(prev_taken_idx!=-1 && dp[i][prev_taken_idx] !=-1) {
        return dp[i][prev_taken_idx];
       }
       int take = 0;
       if(prev_taken_idx ==-1 || nums[i] >nums[prev_taken_idx]){
           take = 1+ solve_RE(nums,i+1,i);  // two variables are changing so 2D dp array will be used
       }
          int not_take = solve_RE(nums,i+1,prev_taken_idx);

          if(prev_taken_idx !=-1)
          return dp[i][prev_taken_idx] = max(take,not_take);
          return max(take,not_take);
    }

int solve_Tabulation(vector<int>& nums){
    int n = nums.size();
    vector<int>dp(n,1); // dp[i] -. i index par khatam hone wala sabse bada subsequence 
 dp[1] = 1;

   for(int curr = 1; curr<n; curr++){
       
       for(int prev = 0; prev<curr ; prev++){

           if(nums[prev]<nums[curr]){
             dp[curr] = max(dp[prev] +1 , dp[curr]) ;
           }
           
       }
      
   }

    return *max_element(dp.begin(), dp.end());
}
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // int n = nums.size();
        // vector<int>dp(n+1,0);
        // dp[0] = 0;
        // dp[1] = 1;
        // for(int i = 2; i<=n; i++){
        //       int curr = nums[i-1]; 
        //       int prev = nums[i-2];
        //       if(curr<prev){
        //         dp[i] = max(dp[i-1],1);
        //       }
        //       else if(curr> prev) {
        //         dp[i] = dp[i-1] +1;
        //       }
        // }
        // return dp[n] ==0 ? 1 :dp[n];


        // return solve_RE(nums,0,-1);
//   int n = nums.size();
//   vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

//        return solve_Memo(nums,0,-1,dp);

if(nums.size()<2) return nums.size();
return solve_Tabulation(nums);
    }
};