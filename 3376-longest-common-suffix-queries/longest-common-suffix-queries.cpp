class Solution {
public:

  struct trieNode{
    int idx;
    trieNode* chil[26];

     ~trieNode(){
        for(int i=0;i<26;i++){
            delete chil[i];
        }
    }
  };

  trieNode* getNode(int i){
    trieNode* tmp =new trieNode();
    tmp->idx=i;

    for(int i=0;i<26;i++){
        tmp->chil[i]=NULL;
    }
    return tmp;
  }

 void insertTrie(trieNode* p,int i,vector<string>&words){
    string word=words[i];
    int n=word.size();

    for(int j=n-1;j>=0;j--){
        int ch=word[j]-'a';

        if(p->chil[ch]==NULL){
            p->chil[ch]=getNode(i);
        }
        p=p->chil[ch];

        if(words[p->idx].size()>n){
            p->idx=i;
        }
    }
  }

  int search(trieNode* p,string &word){
    int res_i=p->idx;
    int n=word.size();

    for(int i=n-1;i>=0;i--){
        int ch=word[i]-'a';
        p=p->chil[ch];

        if(p==NULL){
            return res_i;
        }
        res_i=p->idx;
    }
    return res_i;
  }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        int m=wordsContainer.size();
        int n=wordsQuery.size();
        vector<int>ans(n);

        trieNode* root=getNode(0);

        for(int i=0;i<m;i++){
            if(wordsContainer[root->idx].size()>wordsContainer[i].size()){
                root->idx=i;
            }
            insertTrie(root,i,wordsContainer);
        }

        for(int i=0;i<n;i++){
            ans[i]=search(root,wordsQuery[i]);
        }
        delete(root);

        return ans;
        
    }
};