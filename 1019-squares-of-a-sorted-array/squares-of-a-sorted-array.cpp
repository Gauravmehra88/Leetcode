class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        for(int k:nums){
            ans.push_back(k*k);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};