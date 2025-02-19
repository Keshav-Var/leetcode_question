class Solution {
    string s = "";
    char arr[3] = {'a', 'b', 'c'};
public:
    string getHappyString(int n, int& k) {
        if(s.length() == n){
            k--;
            if(k==0) return s;
            else return "";
        }
        for(int i = 0; i < 3; i++){
            if(s.length() > 0 && s[s.length() - 1] == arr[i]) continue;
            s += arr[i];
            string temp = getHappyString(n, k);
            if(temp != "") return temp;
            s.pop_back();
        }
        return "";
    }
};