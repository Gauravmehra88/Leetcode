class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int value : nums){
            if(s.find(value)!=s.end()){
                return value;
                break;
            }
            s.insert(value);
        }
        return -1;
    }
};