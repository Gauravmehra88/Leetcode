class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        int maxLen=1;
        for(int i=1;i<n;i++){
            for(int p=0;p<i;p++){
                if(nums[i]>nums[p]){
                        lis[i]=max(lis[i], 1 + lis[p]);
                }
            }
            if(lis[i]>maxLen){
                maxLen = lis[i];
            }
        }
        return maxLen;
    }
};