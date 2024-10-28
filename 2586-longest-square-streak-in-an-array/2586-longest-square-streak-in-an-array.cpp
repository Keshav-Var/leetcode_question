class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> isVisited(nums.size(), false);
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            int sequenceLen = 1;
            int currEle = nums[i];
            if(!isVisited[i]){
                while(currEle < 46341 && binary_search(nums.begin(), nums.end(), currEle * currEle)){
                    sequenceLen++;
                    currEle = currEle * currEle; 
                }
            }
            if(sequenceLen >= 2)
            ans = max(ans, sequenceLen);
        }
        return ans;
    }
};