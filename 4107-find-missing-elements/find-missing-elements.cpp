class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b = nums[n-1];
        vector<int>ans;
        int i = 0;
        int j = a;
        while(i<n&& j<=b){
            if(j!=nums[i]){
                ans.push_back(j);
                j++;
                continue;
            }
            i++,j++;  
        }
        return ans;

    }
};