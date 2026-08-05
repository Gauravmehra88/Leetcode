class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        for(int i =0 ; i<n ; i++){ 
            for(int j=i+1 ; j < n ; j++){
                long long a =  gcd(nums[i],nums[j]);
                long long aa = a*a;
                long long b = (1LL *nums[i] * nums[j]) / aa ;
                ans=max(ans , b);
            }

        }
        return ans;
    }
};