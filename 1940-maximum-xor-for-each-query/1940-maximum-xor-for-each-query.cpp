class Solution {
public:
    void hashSetBits(int num, vector<int>& hash){
        int i = 0;
        while(num){
            if(num & 1)
            hash[i]++;
            num = num>>1;
            i++;
        }
        return;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> kvalues(nums.size(), 0);
        vector<int> hash(maximumBit, 0);
        for(int i = 0; i < nums.size(); i++){
            hashSetBits (nums[i], hash);
            int temp = 1;
            int ans = 0;
            for(int  it = 0; it < maximumBit; it++){
                if(hash[it]%2 == 0)
                ans = ans | temp;
                // cout<<ans<<" "<<hash[it]<<" "<<temp<<endl;
                temp = temp<<1;
            }
            kvalues[i] = ans;
        }
        reverse(kvalues.begin(), kvalues.end());
        return kvalues;
    }
};