class Solution {
    int digitSum(int num){
        int sum = 0;
        while(num != 0){
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size(); i++){
            int sum = digitSum(nums[i]);
            if(ht.contains(sum)){
                ans = max(ans, nums[ht[sum]] + nums[i]);
                if(nums[ht[sum]] < nums[i])
                ht[sum] = i;
            }
            else{
                ht.insert({sum, i});
            }
        }
        return ans;
    }
};