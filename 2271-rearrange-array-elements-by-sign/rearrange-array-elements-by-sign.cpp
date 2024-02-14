class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size();
        int q=0;
           int w=1;
      vector<int >a(n,0);
       for(int i=0;i<n;i++)
       {
          
        if(nums[i]<0)
        {
            a[w]=nums[i];
           w +=2;
        }
        else
        {
            a[q]=nums[i];
           q +=2;
        }
       }

       return a;
    }
};