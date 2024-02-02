class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int>ans;
       queue<int>que;
       for(int i=1;i<=8;i++){
           que.push(i);
       }
       while(!que.empty()){
           int temp=que.front();
           que.pop();
           int lastEl=temp%10;
           if(temp>=low && temp<=high){
               ans.push_back(temp);
           }
           if(lastEl+1<=9){
               int a=temp*10+(lastEl+1);
               que.push(a);
           }
       }
       return ans; 
    }
};