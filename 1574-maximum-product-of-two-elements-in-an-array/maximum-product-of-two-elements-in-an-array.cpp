class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int i=0,j=n-1;
        int res=0;
         while(i<n){
            j=0;
             while(j<n){
                if(i!=j){
                    res = max(res , (nums[i]-1) * (nums[j]-1));
                }
                j++;
             }
             i++;
         }
         return res;
    }
};