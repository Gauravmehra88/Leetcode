class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int total= accumulate(piles.begin() , piles.end() , 0);
       int n =piles.size();
       vector<vector<int>>dp(n , vector<int>(n , -1));
       int alice = recur(piles , 0 , n-1 , dp);
        int bob = total - alice;
        if(bob>alice){
            return false;
        }
        else return true;
    }

    int recur(vector<int>& piles , int i , int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int take_i= piles[i] +  min(recur(piles , i+2 , j,dp) , recur(piles ,i+1 , j-1,dp));
        int take_j = piles[j] + min(recur(piles , i , j-2,dp) , recur(piles , i+1 , j-1,dp));

        return dp[i][j] = max(take_i , take_j);
    }
};