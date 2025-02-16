class Solution {
private:
    bool solve(vector<int> &seq, vector<bool> &visited, int n, int index){
        while(index < seq.size() && seq[index] != -1) index++;
        if(index == seq.size()) return true;
        for(int i = n; i > 0; i--){
            if(visited[i]) continue;
            if(i == 1){
                visited[i] = true;
                seq[index] = i;
                if(solve(seq, visited, n, index+1)) return true;
                seq[index] = -1;
                visited[i] = false;
            }
            else if(i+index < seq.size() && seq[i + index] == -1){
                visited[i] = true;
                seq[index] = i;
                seq[index + i] = i;
                if(solve(seq, visited, n, index+1)) return true;
                seq[index] = -1;
                seq[index+i] = -1;
                visited[i] = false;
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2*n-1, -1);
        vector<bool> visited(n+1, false);
        solve(seq, visited, n, 0);
        return seq;
    }
};