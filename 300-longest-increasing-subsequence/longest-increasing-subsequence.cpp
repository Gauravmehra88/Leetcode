class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n ,vector<int>(n+1,-1));
        return recur(nums , 0 , -1,dp);
    }
    int recur( vector<int>& nums , int idx, int previdx , vector<vector<int>> &dp){
         if(idx==nums.size()){
            return 0;
         }
         if(dp[idx][previdx + 1] != -1){
            return dp[idx][previdx+1];
         }
         int pick=0;
         if( previdx == -1  || nums[idx]>nums[previdx]){
            pick = 1 + recur(nums, idx+1 , idx ,dp);
         }
         int nopick = recur(nums , idx+1 , previdx , dp);

         return dp[idx][previdx+1] = max(pick,nopick);
    }
};