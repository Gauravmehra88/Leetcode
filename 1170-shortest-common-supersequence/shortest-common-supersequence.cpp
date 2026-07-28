class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));

        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){ 
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else if(dp[i-1][j] >= dp[i][j-1]){ 
                    dp[i][j] = dp[i-1][j] ;
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
            string ans="";
         int a=n , b=m;
             while (a> 0 && b>0){
                 if(str1[a-1]==str2[b-1]){
                    ans+=str1[a-1];
                    a--,b--;
                 }
                 else if(dp[a-1][b] >= dp[a][b-1]){
                    ans+=str1[a-1];
                    a--;
                 }
                 else {
                     ans+=str2[b-1];
                     b--;
                 }
             }
             while(b>0){
                    ans.push_back(str2[b-1]);
                    b--;
                }
            while(a>0){
                    ans.push_back(str1[a-1]);
                    a--;
                }
             reverse(ans.begin(),ans.end());
            return ans;
    }
};