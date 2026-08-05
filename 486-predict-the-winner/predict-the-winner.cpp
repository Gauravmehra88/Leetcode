class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
         int  total = accumulate(nums.begin() , nums.end() , 0);
         vector<vector<int>>dp(n , vector<int>(n , -1));
        int p1 = recur(nums , 0 , n-1 , dp);
        int p2 = total - p1;
        if(p1>=p2){
            return true;
        }
        return false;
        
    }

     int recur(vector<int> &nums , int i , int j ,vector<vector<int>>&dp ){
        if(i>j) return 0;
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int pick_i = nums[i] + min( recur(nums , i+2 , j,dp) , recur(nums , i+1 , j-1,dp));
        int pick_j = nums[j] + min( recur(nums , i , j-2,dp) , recur(nums , i+1 , j-1,dp));

        return dp[i][j] = max(pick_i , pick_j);
     }
};