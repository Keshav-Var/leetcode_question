class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int i = 0, j = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i-j] = nums[i];
            if(nums[i] == 0) j++;
        }
        i = nums.size() - 1;
        while(j){nums[i] = 0; i--; j--;}
        return nums;
    }
};