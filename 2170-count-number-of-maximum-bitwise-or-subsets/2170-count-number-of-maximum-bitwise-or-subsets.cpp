class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto it : nums){
            maxOr = maxOr | it;
        }
        return helper(0, nums, 0, maxOr);
    }
    int helper(int index, vector<int>& nums, int currOr, int targetOr){
        if(index == nums.size()){
            return currOr == targetOr? 1:0;
        }
        return helper(index + 1, nums, currOr | nums[index], targetOr) + helper(index + 1, nums, currOr, targetOr);
    }
};