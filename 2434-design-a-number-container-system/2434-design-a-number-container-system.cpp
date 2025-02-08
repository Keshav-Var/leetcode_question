class NumberContainers {
    unordered_map<int, int> indexNumber;
    unordered_map<int, set<int>> numberIndex;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(indexNumber.contains(index)){
            int oldNumber = indexNumber[index];
            numberIndex[oldNumber].erase(index);
            if(numberIndex[oldNumber].empty()){
                numberIndex.erase(oldNumber);
            }
        }
        indexNumber[index] = number;
        numberIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numberIndex.contains(number))
        return *numberIndex[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */