#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
void levelOrder(Node* root){
    if(root==NULL) return ;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* current=q.front();
            q.pop();
            cout<<current->data<<" ";
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
        }
        cout<<endl;
    }
}
int main(){
    //     1
    //    / \
    //   2   3
    //    / \    
    //   4   5
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    levelOrder(root);
    return 0;
}