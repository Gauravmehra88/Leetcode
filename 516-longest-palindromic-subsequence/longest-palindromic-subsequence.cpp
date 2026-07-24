class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n=s.length();
        int m = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>>dp(n , vector<int>(m+1 , -1));
        return recur(s , t , n-1 , m-1 ,dp);
    }
    int recur(string &s, string &t, int idx1 , int idx2, vector<vector<int>>& dp){

        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
         if(s[idx1]==t[idx2]){
            return dp[idx1][idx2]=1 + recur(s , t, idx1-1 , idx2-1 ,dp);
        }
        else{
        
        int t1= 0 + recur(s , t , idx1-1 , idx2,dp);
        int t2=0 + recur(s , t , idx1 , idx2-1,dp);
        return dp[idx1][idx2] = max(t1,t2);
        }

        return dp[idx1][idx2] ;
    }
};