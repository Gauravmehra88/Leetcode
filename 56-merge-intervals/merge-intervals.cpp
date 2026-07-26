class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());

        int i=0;
        while(i<n){
            int mini=intervals[i][0];
            int maxi=intervals[i][1];

            while(i+1<n  && maxi>=intervals[i+1][0]){ 
                mini= min(mini, intervals[i+1][0]);
                maxi=max(maxi , intervals[i+1][1]);
                i++;
            }
             ans.push_back({mini , maxi});
             i++;
        }
        return ans;

    }
};