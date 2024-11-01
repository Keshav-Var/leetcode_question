class Solution {
public:
    string makeFancyString(string s) {
        int idx = 0;
        for(int i = 0; i < s.length();){
            char ch = s[i];
            int count = 0;
            while(s[i] == ch){
                if(count < 2){
                    s[idx++] = s[i];
                    count++;
                }
                i++;
            }
        }
        // cout<<s<<endl;
        s.erase(s.begin()+idx, s.end());
        return s;
    }
};