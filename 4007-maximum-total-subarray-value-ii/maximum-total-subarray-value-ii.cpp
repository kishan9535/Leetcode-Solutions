

class SegmentTree{

    public:
      vector<int>segmentTree;
      bool ismin;

      SegmentTree(vector<int>& nums,bool flag){
        int n=nums.size();
        this->ismin=flag;
        segmentTree.resize(4*n);

        buildSegmentTree(0,0,n-1,nums);
      }

      void buildSegmentTree(int i,int l,int r,vector<int>& nums){

        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }

         int mid=l+(r-l)/2;

         buildSegmentTree(2*i+1,l,mid,nums);
         buildSegmentTree(2*i+2,mid+1,r,nums);

         if(ismin){
            segmentTree[i]=min(segmentTree[2*i+1],segmentTree[2*i+2]);
         }
         else{
            segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
         }
      }

      int querySegmentTree(int s,int e,int i,int l,int r){

        if(l>e ||r<s){
            return ismin ? INT_MAX:INT_MIN;
        }

        if(l>=s && r<=e){
            return segmentTree[i];
        }

        int mid=l+(r-l)/2;

        int a=querySegmentTree(s,e,2*i+1,l,mid);
        int b=querySegmentTree(s,e,2*i+2,mid+1,r);

        if(ismin){
            return min(a,b);
        }
        return max(a,b);
      }

      int query(int l,int r,int n){
        return querySegmentTree(l,r,0,0,n-1);
      }
};






class Solution {
public:


 long long getValue(int l,int r, SegmentTree& minSt,SegmentTree& maxSt,int n){
    int mini=minSt.query(l,r,n);
    int maxi=maxSt.query(l,r,n);

    return (long long)maxi-mini;
   }

    typedef long long ll;

    long long maxTotalValue(vector<int>& nums, int k) {

        int n=nums.size();

        SegmentTree minSt(nums,true);
        SegmentTree maxSt(nums,false);

        priority_queue<tuple<ll,int,int>>pq;


        for(int i=0;i<n;i++){
            ll val=getValue(i,n-1,minSt,maxSt,n);
            pq.push({val,i,n-1});
        }

        ll ans=0;

        while(k--){
            auto [val,l,r]=pq.top();
            pq.pop();
            ans+=val;

            ll nxtbextval=getValue(l,r-1,minSt,maxSt,n);
            pq.push({nxtbextval,l,r-1});
        }

        return ans;
        
    }
};