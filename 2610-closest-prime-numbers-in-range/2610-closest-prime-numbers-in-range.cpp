class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        isPrime[0] = false; isPrime[1] = false;
        for(int i = 2; i <= right; i++){
            if(isPrime[i]){
                for(int j = 2; i*j <= right; j++){
                    isPrime[i*j] = false;
                }
            }
        }
        // for(auto it:isPrime)
        // cout<<it<<" ";

        int mini = INT_MAX;
        int num1 = -1, num2 = -1;

        for(int i = left; i <= right;){
            if(isPrime[i]){
                int j = i;
                i++;
                while(i <= right && !isPrime[i])
                i++;
                if(i <= right && i - j < mini){
                    num1 = j;
                    num2 = i;
                    mini = i - j;
                }
            }
            else{
                i++;
            }
        }
        return {num1, num2};
    }
};