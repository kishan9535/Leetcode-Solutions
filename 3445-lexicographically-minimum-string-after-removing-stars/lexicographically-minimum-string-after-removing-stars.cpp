class Solution {
public:
    typedef pair<char, int> P;

     struct comp{
        bool operator()(P &p1, P& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        priority_queue<P, vector<P>, comp> pq;
        int n = s.length();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '*')
                pq.push({s[i], i});
            else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

       /* while (cnt && !pq.empty()) {
            auto pt = pq.top();
            pq.pop();
            cnt--;
            int idx = pt.second;
            s[idx] = '*';
        }*/

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                ans += s[i];
            }
        }

        return ans;
    }
};
