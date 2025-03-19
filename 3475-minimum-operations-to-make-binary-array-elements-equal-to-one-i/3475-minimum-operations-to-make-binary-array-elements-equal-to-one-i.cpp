class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n-2; i++){
            if(nums[i] == 1) continue;
            nums[i] = 1;
            nums[i+1] = nums[i+1] == 0? 1 : 0;
            nums[i+2] = nums[i+2] == 0? 1 : 0;
            count++;
        }

        if(nums[n-3] == 0 && nums[n-2] == 0 && nums[n-1] == 0)
        return count+1;
        else if(nums[n-3] == 1 && nums[n-2] == 1 && nums[n-1] == 1)
        return count;
        else 
        return -1;
    }
};