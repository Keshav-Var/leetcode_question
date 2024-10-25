class Solution {
public:
    bool isSubfolder(string s1, string s2){
        s1 = s1 + '/';
        if(s2.length()<s1.length())
        return false;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i])
            return false;
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        string curr = folder[0];
        for(int i = 0; i < folder.size(); i++){
            if(!isSubfolder(curr, folder[i])){
                curr = folder[i];
                ans.push_back(curr);
            }
        }
        return ans;
    }
};