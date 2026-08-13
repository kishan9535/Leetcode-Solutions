class Solution {
public:
   
   struct Node{

    int pre=0;
    int suf=0;
    int maxlen=0;
    char lchar=0;
    char rchar=0;
   };

   int n;
   vector<Node>segTree;

   Node merge(const Node&L , const Node& R, int llen, int rlen){

    Node res;

    res.lchar=L.lchar;
    res.rchar=R.rchar;

    res.pre=L.pre;

    if(L.pre==llen && L.rchar==R.lchar){
        res.pre=L.pre+R.pre;
    }

    res.suf=R.suf;

    if(R.suf==rlen && L.rchar==R.lchar){
        res.suf=R.suf+L.suf;
    }

    res.maxlen=max(L.maxlen,R.maxlen);

    if(L.rchar==R.lchar){

        res.maxlen=max(res.maxlen, L.suf+R.pre);
    }

    return res;

   }

   void buildSegmentTree(int i, int l, int r, string &s){

    if(l==r){
        segTree[i]={1,1,1,s[l],s[l]};
        return;
    }

     int mid=l+(r-l)/2;

     buildSegmentTree(2*i+1,l,mid,s);
     buildSegmentTree(2*i+2,mid+1,r,s);

     segTree[i]=merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);

   }

   void update(int i, int l, int r, int pos, char ch){
      
     if(l==r){
        segTree[i]={1,1,1,ch,ch};
        return;
     }

     int mid=l+(r-l)/2;

     if(pos<=mid){
        update(2*i+1,l,mid,pos,ch);
     }
     else{
        update(2*i+2,mid+1,r,pos,ch);
     }

     segTree[i]=merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);

   }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        
        n=s.length();
        segTree.assign(4*n,Node());

        buildSegmentTree(0,0,n-1,s);
        
        int k=queryCharacters.size();

        vector<int>ans(k);

        for(int i=0;i<k;i++){

            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            update(0,0,n-1,pos,ch);

            ans[i]=segTree[0].maxlen;

        }
        return ans;



    }
};