class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0];
        int temp = nums[0];
        for(int i = 1; i < nums.size();){
            while(i < nums.size() && nums[i] > nums[i - 1]){
                temp += nums[i];
                i++;
            }
            res = max(res, temp);
            if(i < nums.size()){
                temp = nums[i];
                res = max(res, temp);
                i++;
            }
        }
        return res;
    }
};