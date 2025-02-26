class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMinSum = nums[0];
        int currMaxSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            currMaxSum = max(currMaxSum+nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);
            currMinSum = min(currMinSum+nums[i], nums[i]);
            minSum = min(minSum, currMinSum);
        }
        return max(maxSum, abs(minSum));
    }
};