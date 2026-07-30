class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= 1 + (i/8);
        }
        return ans;
    }
};