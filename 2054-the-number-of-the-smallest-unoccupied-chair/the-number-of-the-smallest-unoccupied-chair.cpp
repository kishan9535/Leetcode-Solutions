class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int arriv_time = times[targetFriend][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {end_time, chair_index}
        priority_queue<int, vector<int>, greater<int>> free;  
        int chair_size = 0;  
        sort(times.begin(), times.end());  
        
        for (auto it : times) {
            int st = it[0];  
            int ed = it[1]; 
            
            while (!pq.empty() && pq.top().first <= st) {
                free.push(pq.top().second); 
                pq.pop();  
            }
            
            int chair;
            if (free.empty()) {
                chair = chair_size++;
            } else {
                chair = free.top();
                free.pop();
            }
            
            if (st == arriv_time) {
                return chair;
            }
            
            pq.push({ed, chair});
        }

        return -1; 
    }
};
