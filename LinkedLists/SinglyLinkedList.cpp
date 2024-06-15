//ctrl+shift+b
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
    this->data=data;
    this->next=NULL;

  }
  ~Node(){
    int value=this->data;
    if(next!=NULL){
      delete next;
      next=NULL;
    }
    cout<<"Memory is free for data : "<<value<<endl;
  }
};
 void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head= temp;

  }
  void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
  }
  void InsertAtPosition(Node* &head,Node* &tail,int d,int position){
    if(position == 1){
     insertAtHead(head,d);
     return;
     }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
      temp=temp->next;
      cnt++;
    }
    if(temp->next==NULL){
      InsertAtTail(tail,d);
      return;
    }
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
  }
  void deleteNode(Node* &head,int position){
    if(position==1){
      Node*temp=head;
      head=head->next;
      temp->next=NULL;
      delete temp;
    }else{
      Node* curr=head;
      Node*  prev=NULL;
      int cnt=1;
      while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
      }
      prev->next=curr->next;
      curr->next=NULL;
      delete curr;
    }

  }
  void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

  }
int main(){
   Node* n1=new Node(10);
   cout<<n1->data<<endl;
   cout<<n1->next<<endl;
   Node* head=n1;
   Node* tail=n1;
   insertAtHead(head,12);
   insertAtHead(head,15);
   print(head);
   InsertAtTail(tail,12);
   InsertAtTail(tail,15);
   print(head);
   InsertAtPosition(head,tail,52,6);
   InsertAtPosition(head,tail,78,1);
   print(head);
   cout<<"Head " <<head->data<<endl;
   cout<<"Tail " <<tail->data<<endl;
   deleteNode(head,1);
   print(head);
   cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    return 0;
}