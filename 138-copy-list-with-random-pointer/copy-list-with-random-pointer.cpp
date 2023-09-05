/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
     Node* curr=head;
     Node* prev=NULL;
     Node* newhead=NULL;

     while(curr){
      Node* temp=new Node(curr->val);
      mp[curr]=temp;
      if(newhead==NULL){
          newhead=temp;
          prev=newhead;
      }
      else{
          prev->next=temp;
          prev=temp;
      }
      curr=curr->next;
     }
     curr=head;
      Node* newcur=newhead;
     while(curr){
       if(curr->random==NULL){
           newcur->random=NULL;
       }
       else{
           newcur->random=mp[curr->random];
       }
       curr=curr->next;
       newcur=newcur->next;
     }
     return newhead;   
    }
};