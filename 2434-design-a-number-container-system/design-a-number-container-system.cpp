class NumberContainers {
public:
    unordered_map<int,int>idxtonum;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>numtoidx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        idxtonum[index]=number;

        numtoidx[number].push(index);
    }
    
    int find(int number) {
        if(!numtoidx.count(number)){
            return -1;
        }
        auto &pq=numtoidx[number];
        while(!pq.empty()){
            int idx=pq.top();
            if(idxtonum[idx]==number){
                return idx;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */