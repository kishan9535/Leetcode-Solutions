class Solution {
public:

  vector<int>segmentTree;
  int n=50000;

  void Construct(){
    segmentTree.resize(4*n,0);
  }

  void updateSegTree(int idx,int val,int i,int l,int r){
    if(l==r){
        segmentTree[i]=val;
        return;
    }

    int mid=l+(r-l)/2;

    if(idx<=mid){
        updateSegTree(idx,val,2*i+1,l,mid);
    }
    else{
        updateSegTree(idx,val,2*i+2,mid+1,r);
    }

    segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
  }

int querysegTree(int s, int e,int i,int l, int r){
    if(l>e || r<s){
        return 0;
    }

    if(l>=s && r<=e){
        return segmentTree[i];
    }

    int mid=l+(r-l)/2;

    return max(querysegTree(s,e,2*i+1,l,mid),querysegTree(s,e,2*i+2,mid+1,r));
  }
  
  
  
      vector<bool> getResults(vector<vector<int>>& queries) {
        Construct();
        set<int>st;
        st.insert(0);
        vector<bool>ans;

        for(auto&it:queries){

            if(it[0]==1){
                int x=it[1];

                auto p=st.upper_bound(x);
                int nxt=(p!=st.end())?*p:-1;    
                int pre=*prev(p);

                updateSegTree(x,x-pre,0,0,n-1);
                if(nxt!=-1)updateSegTree(nxt,nxt-x,0,0,n-1);
                
                    st.insert(x);
            }
            else{
                int x=it[1];
                int sz=it[2];

                auto p=st.upper_bound(x);
                int pre=*prev(p);

                int maxgap=querysegTree(0,pre,0,0,n-1);
                int best=max(maxgap,x-pre);

                ans.push_back(best>=sz);
              
            }
        }
          return ans;
        
    }
};