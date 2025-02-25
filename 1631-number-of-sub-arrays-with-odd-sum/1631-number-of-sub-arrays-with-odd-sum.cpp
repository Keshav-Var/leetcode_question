class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int oddPrefixSum = 0;
        int evenPrefixSum = 1;
        int count = 0;
        int prefixSum = 0;
        for(int i = 0; i < arr.size(); i++){
            prefixSum += arr[i];
            if(prefixSum%2 == 0){
                count = (count+oddPrefixSum)%mod;
                evenPrefixSum++;
            }
            else{
                count = (count+evenPrefixSum)%mod;
                oddPrefixSum++;
            }
        }
        return count;
    }
};