
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* prev;
  Node(int d){
    this->data=d;
    this->next=NULL;
    this->prev=NULL;
  }
  ~Node(){
    int value =this->data;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"Memory is free for the data : "<<value<<endl;
  }
};
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    //empty list
    if(head==NULL){
        head=temp;
    }else{        
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    if(tail==NULL){
        tail=temp;
    }else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    
}
void insertAtPosition(Node* &head,Node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
       
    }else{
        int cnt=1;
        Node* temp=head;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertAtTail(tail,d);
           
        }else{
        Node* nodeToInsert=new Node(d);
        nodeToInsert->next=temp->next;
        temp->next=nodeToInsert;
        nodeToInsert->prev=temp;
        (nodeToInsert->next)->prev=nodeToInsert;
    }
    }
}
void deleteNode(Node* &head,int pos){
    if(pos==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
        Node* curr=head;
        Node*  pre=NULL;
        int cnt=1;
        while(cnt<pos){
            pre=curr;
            curr=curr->next;
            cnt++;
      }
      curr->prev=NULL;
      pre->next=curr->next;
      curr->next=NULL;
      delete curr;

    }

}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtHead(head,11);
    insertAtHead(head,19);
    print(head);
    insertAtTail(tail,45);
    insertAtTail(tail,89);
    print(head);
    insertAtPosition(head,tail,3,77);
    insertAtPosition(head,tail,5,21);
    print(head);
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    deleteNode(head,1);
    print(head);
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    return 0;
}