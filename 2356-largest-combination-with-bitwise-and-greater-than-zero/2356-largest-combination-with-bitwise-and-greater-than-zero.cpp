class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = INT_MIN;
        for(auto it:candidates){
            if(it > maxi)
            maxi = it;
        }
        int i = 1;
        int ans = 0;
        while(i <= maxi){
            int count = 0;
            for(int j = 0; j < candidates.size(); j++){
                if(i & candidates[j])
                count++;
            }
            ans = max(ans, count);
            i = i<<1;
        }
        return ans;
    }
};