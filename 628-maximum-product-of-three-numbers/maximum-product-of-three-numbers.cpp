class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long m=nums.size();
        long long out=0;
        long long ans=0;
          sort(nums.begin(),nums.end());
         out = nums[m-1] * nums[m-2] * nums[m-3];
          ans=nums[0]* nums[1] * nums[m-1];
          return max(out,ans);   
    }
};