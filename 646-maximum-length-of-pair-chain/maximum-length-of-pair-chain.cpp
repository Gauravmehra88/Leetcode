class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());

        //isme LIS(longest increasing subsequence ka code hi lagega )
        vector<int>lis(n,1);

        int maxlen=1;
        for(int i=1;i<n;i++){
            for(int p=0;p<i;p++){
                if(pairs[i][0] > pairs[p][1]){
                    lis[i]=max(lis[i], 1 + lis[p]);
                }
            }
            maxlen= max(maxlen,lis[i]);
        }
        return maxlen;
    }
};