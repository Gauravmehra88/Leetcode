class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n , vector<int>(m+1 , -1));
        return recur(text1 , text2 , n-1 , m-1 ,dp);
    }
    int recur(string &text1 , string &text2 , int idx1 , int idx2, vector<vector<int>>& dp){

        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
         if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2]=1 + recur(text1 , text2 , idx1-1 , idx2-1 ,dp);
        }
        else{
        
        int t1= 0 + recur(text1 , text2 , idx1-1 , idx2,dp);
        int t2=0 + recur(text1 , text2 , idx1 , idx2-1,dp);
        return dp[idx1][idx2] = max(t1,t2);
        }

        return dp[idx1][idx2] ;
    }
};