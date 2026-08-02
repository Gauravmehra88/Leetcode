class Solution {
public:
    int dp[31][3001];
    int rec(int i,int sum,vector<int>& a,int total){
        int remain=total-sum;
        int n=a.size();
        if(i>=n){
            return abs(remain-sum);
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans=INT_MAX;
        ans=min(ans,rec(i+1,sum+a[i],a,total));
        ans=min(ans,rec(i+1,sum,a,total));
        return dp[i][sum]=ans;
    }
    int lastStoneWeightII(vector<int>& a) {
        int sum=accumulate(a.begin(),a.end(),0L);
        memset(dp,-1,sizeof(dp));
        return rec(0,0,a,sum);
    }
};