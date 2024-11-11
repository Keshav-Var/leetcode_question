class Solution {
public:
    int search(vector<int>& nums, int x) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto it:nums){
            maxi = max(it, maxi);
        }
        vector<bool> arr(maxi, true);
        arr[0] = false;
        arr[1] = false;
        for(int i = 2; i < maxi; i++){
            if(arr[i]){
                int temp = i + i;
                while(temp < maxi){
                    arr[temp] = false;
                    temp += i;
                }
            }
        }
        vector<int> primes;
        for(int i = 0; i < maxi; i++){
            if(arr[i])
            primes.push_back(i);
        }
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int j = search(primes, nums[i] - nums[i + 1]);
            if (j == primes.size() || primes[j] >= nums[i]) {
                return false;
            }
            nums[i] -= primes[j];
        }
        return true;
    }
};