class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total =0;
        for(int m:nums){
            total+=m;
        }
        vector<vector<int>>dp(n , vector<int>( (total * 2)+1 , -1));
         return recur(nums , target , 0 , n-1,total, dp);
    }

    int recur(vector<int>& nums , int target , int currsum , int index ,int total , vector<vector<int>> &dp){
        if(index==0){
             int ways = 0;

              if(currsum + nums[0] == target) ways++; 
               if(currsum - nums[0] == target) ways++;

                return ways;
        }
        if(dp[index][currsum +total]!=-1){
            return dp[index][currsum + total];
        }
        int plus = recur(nums , target , currsum + nums[index] , index-1,total ,dp);
        int minus = recur(nums , target , currsum - nums[index] , index-1,total ,dp);

        return  dp[index][currsum + total] = plus + minus;
    }
};