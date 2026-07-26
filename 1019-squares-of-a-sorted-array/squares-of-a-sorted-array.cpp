class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int i=0,j=n-1;
         while(i<=j){
            if( abs(nums[i]) == abs(nums[j]) ){
                if(i!=j){ 
                ans.insert(ans.begin(),nums[i]*nums[i]);
                }
                ans.insert(ans.begin(),nums[i]*nums[i]);
                i++;
                j--;
            }
            else if(abs(nums[i]) > abs(nums[j]) ){
                ans.insert(ans.begin(),nums[i]*nums[i]);
                i++;
            }
            else{
                ans.insert(ans.begin(),nums[j]*nums[j]);
                j--;
            } 
         }
         return ans;
    }
};