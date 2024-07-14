class Solution {
public:
    string countOfAtoms(string formula) {
      string ans ="";
      stack<unordered_map<string,int>>st;
       st.push(unordered_map<string,int>());
      int n=formula.size(),i=0;
      while(i<n){
       if(formula[i]=='('){
        st.push(unordered_map<string,int>());
        i++;
       }
       else if (formula[i]==')'){
        unordered_map<string,int> curr=st.top();
        st.pop();
        i++;
        string multi;
        while(i<n && isdigit(formula[i])){
            multi.push_back(formula[i]);
            i++;
        }
        if(!multi.empty()){
            int multip=stoi(multi);
            for(auto &it:curr){
                string ele=it.first;
                int count=it.second;

                curr[ele]=count*multip;
            }
        }
        for(auto &it:curr){//update
            string ele=it.first;
            int count=it.second;
            st.top()[ele]+=count;
        }
       }
       else{
        string currele;
        currele.push_back(formula[i]);
        i++;
        while(i<n &&(isalpha(formula[i])&& islower(formula[i]))){
            currele.push_back(formula[i]);
            i++;
        }
        string currcount;
        while(i< n && isdigit(formula[i])){
            currcount.push_back(formula[i]);
            i++;
        }
        int currcount_integer= currcount.empty() ? 1 :stoi(currcount);
        st.top()[currele]+=currcount_integer;
       }
      }
      map<string,int>mp(st.top().begin(),st.top().end());

      for(auto i:mp){
        string ele=i.first;
        int count=i.second;
        ans+=ele;
        if(count>1){
            ans+=to_string(count);
        }
      }
      return ans;
    }
};