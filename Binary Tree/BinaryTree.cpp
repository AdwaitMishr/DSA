#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node* left;
    node* right;
    node(int d) {
       this -> data = d;
       this -> left = NULL;
       this -> right = NULL; 
    }
};
node* buildTree(node* root) {
    cout << "Enter the data: " << endl;
    int d;
    cin >> d;
    root = new node(d);
    if(d == -1)
        return NULL;
     cout << "Enter data for left of " << d << ": " << endl;
     root -> left = buildTree(root -> left);
     cout << "Enter data for right: " << d << ": " << endl;
     root -> right = buildTree(root -> right);   
}
void levelOrderTraversal(node* root) {
        queue <node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            node* temp = q.front();
            q.pop();
            if(temp == NULL) {
                cout << endl;
                if(!q.empty())
                    q.push(NULL);
            }else {
                cout << temp -> data << "  ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
            }
            

        }

}
void inorderTraversal(node* root) {
    if(root == NULL)
        return;
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);    
}
void preorderTraversal(node* root) {
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);    
} 
void postorderTraversal(node* root) {
    if(root == NULL)
        return;
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";    
}
void buildTreeLevelorder(node* &root) {
    queue<node*> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << "Enter left node for: " << temp -> data << endl;
        int ldata;
        cin >> ldata;
        if(ldata != -1) {
            temp -> left = new node(ldata);
            q.push(temp -> left); 
            }
        cout << "Enter right node for: " << temp -> data << endl;
        int rdata;
        cin >> rdata;
        if(rdata != -1) {
            temp -> right = new node(rdata);
            q.push(temp -> right); 
            }    
    }

}
void reverseLevelorderTraversal(node* root) {
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            s.push(NULL);
            if(!q.empty())
                q.push(NULL);
            }else {
                s.push(temp);

  
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
            }
    }

    
    while (!s.empty()) {
        node* temp = s.top();
        s.pop();
        if (temp == NULL) {
            cout << endl;  
        } else {
            cout << temp->data << " ";
        }
    }
    cout << endl;
}
int main() {
    node* root = NULL;
    root = buildTree(root); // recursive tree build
    //buildTreeLevelorder(root);
    cout << "Level order Traversal :" << endl; 
    levelOrderTraversal(root);
    reverseLevelorderTraversal(root);
    cout << "Inorder Traversal : "; 
    inorderTraversal(root);
    cout << "\nPreoder Traversal : ";
    preorderTraversal(root);
    cout << "\nPostorder Traversal : ";
    postorderTraversal(root);
return 0;
}




//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
/*       1
    3           5
 7    11    17    NULL
*/