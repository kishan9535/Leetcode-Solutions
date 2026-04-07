class Robot {
public:
    int idx=0;
    vector<vector<int>>ans;
    bool moved=false;
    Robot(int width, int height) {
        
        for(int i=0;i<width;i++){
            ans.push_back({i,0,0});
        }

        for(int j=1;j<height;j++){
            ans.push_back({width-1,j,1});
        }

        for(int i=width-2;i>=0;i--){
            ans.push_back({i,height-1,2});
        }

        for(int j=height-2;j>0;j--){
            ans.push_back({0,j,3});
        }
        ans[0][2]=3;
    }
    
    void step(int num) {
       moved=true;
       int m=ans.size();
       idx=(idx+num)%m;
      
    }
    
    vector<int> getPos() {
     return {ans[idx][0],ans[idx][1]};   
    }
    
    string getDir() {
      if(!moved)return "East";

      int d=ans[idx][2];
      if(d==0)return "East";
      if(d==1)return "North";
      if(d==2)return "West";
      return "South";  
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */