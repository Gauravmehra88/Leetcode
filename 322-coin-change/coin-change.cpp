class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1,-1));
        int result = recur(coins , amount , n-1 ,dp);
        if(result == 1e9){
            return -1;
        }
        else return result;
        
    }

    int recur(vector<int>&coins , int amount , int index , vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        } 
        if(index==0){
            if(amount % coins[index]==0){
                return amount/coins[index];
            }
            else return 1e9;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        int pick= 1e9;
        if(coins[index]<=amount){
            pick = 1 + recur(coins, amount-coins[index] , index,dp);
        }
         int nopick= 0 + recur(coins , amount,index-1,dp);

         dp[index][amount] = min(pick,nopick);
         return dp[index][amount];
    }
};