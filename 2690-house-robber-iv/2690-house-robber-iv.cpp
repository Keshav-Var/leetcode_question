class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto it:nums){
            maxi = max(maxi, it);
            mini = min(mini, it);
        }

        int s = mini, e = maxi;
        while(s < e){
            int mid = (s + e) / 2;
            int count = 0;
            int last = -2;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid && i - 1 != last){
                    last = i;
                    count++;
                }
            }
            if(count >= k)
            e = mid;
            else
            s = mid + 1;
        }
        return s;
    }
};