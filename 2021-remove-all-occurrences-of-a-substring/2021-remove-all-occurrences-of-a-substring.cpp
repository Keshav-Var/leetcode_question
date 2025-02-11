class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        stack<char> st;
        stack<char> temp;
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);
            if(st.size() >= m){
                for(int i = m - 1; i >= 0; i--){
                    if(st.top() == part[i]){
                        temp.push(st.top());
                        st.pop();
                    }
                    else break;
                }
                if(temp.size() == m){
                    temp = stack<char>();
                }
                else{
                    while(!temp.empty()){
                        st.push(temp.top());
                        temp.pop();
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};