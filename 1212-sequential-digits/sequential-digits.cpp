class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int>ans;
        queue<int>que;

        for(int i=1;i<=8;i++){
            que.push(i);
        }

        while(!que.empty()){
            int ele=que.front();
            que.pop();
            int l=ele%10;
            ele=(ele*10)+(l+1);

            if(l+1>9)continue;

            if(ele>=low && ele<=high){
                ans.push_back(ele);
            }
            else if(ele>high)break;

            que.push(ele);
        }
        return ans;  
    }
};