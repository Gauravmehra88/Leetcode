class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
         return recur(nums , target , 0 , n-1);
    }

    int recur(vector<int>& nums , int target , int currsum , int index){
        if(index==0){
             int ways = 0;

              if(currsum + nums[0] == target) ways++; 
               if(currsum - nums[0] == target) ways++;

                return ways;
        }
        int plus = recur(nums , target , currsum + nums[index] , index-1);
        int minus = recur(nums , target , currsum - nums[index] , index-1);

        return plus + minus;
    }
};