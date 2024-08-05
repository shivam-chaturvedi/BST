#include<iostream>

using namespace std;

class BST{
    private:
    struct Node{
        int key;
        Node *left,*right;
        Node(int key):key(key),left(nullptr),right(nullptr){}
    };

    Node *root=nullptr;

    Node *insert(Node *root,int key){
        if(!root){
            // if tree is empty
            return new Node(key);
        }
        else if(key>root->key){
            // key should be inserted in right part
            root->right=insert(root->right,key); //it will recusively call the insert(Node*,int) and than return new node
        }
        else if(key<root->key){
            // key belongs to left side
            root->left=insert(root->left,key);
        }
        else{
            // key is already there and in BST we dont store duplicate keys
            return root;
        }

        return root;
    }

    void inorder(Node *root){
        // inorder traversal
        // in inorder first left part then root then right part
        // i forgot base condition silly mistake
        if(!root){
            return;
        }

        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }

    Node * min(Node * root){
        // we know that left part contain always lower value than parent
        if(!root){
            return nullptr;
        }

        while(root->left){
            root=root->left;
        }
        return root;
    }
    // this method should return new tree after removing the key 
    Node * remove(Node *root,int key){
        if(!root){
            // if root is nullptr
            return root;
        }
        else if(key<root->key){
            // key maybe present in left part
            root->left=remove(root->left,key);
        }
        else if(key>root->key){
            // hmm it make sense as we need to updade each parent child 
            root->right=remove(root->right,key);
        }
        else{
            // we found key
            // there are three cases the node to be removed has no child
            if(!root->right && !root->left){
                // if the root has no child 
                delete root; //dont confuse with the member variable root because this is the local variable root 
                return nullptr;
            }
            else if(!root->left){
                // node to be deleted has right child only
                Node *temp=root->right; //right child address now in temp
                delete root;
                return temp; //we just simply return right child after deleting the node
            }
            else if(!root->right){
                Node * temp=root->left;
                delete root;
                return temp;
            }
            else{
                // if node has both left and right child
                // so we need to find inorder successor or inorder predecessor
                // so first make max or min method 
                // first find minChild

                Node *minChild=min(root->right); //inorder successor
                root->key=minChild->key; //root value removed
                // now recursively remove minChild
                root->right=remove(root->right,minChild->key); //we must chnage the right subtree after removing value from it
            }
        }
        return root;
    }
    public:

    BST():root(nullptr){}

    void insert(int key){
        // method overloading 
        root=insert(root,key);
    }

    void inorder(){
        inorder(root);
    }

    int min(){
        Node * minChild=min(root);
        return minChild?minChild->key:-1;
    }

    void remove(int key){
        root=remove(root,key); //as it will return new tree (root)
    }

};


int main(){
    BST tree;
    tree.insert(4);
    // tree.insert(2);
    tree.insert(34);
    tree.insert(42824);
    tree.insert(23);
    tree.insert(4);
    cout<<"Tree Before Removing 34 is ";
    tree.inorder();
    tree.remove(34);
    cout<<endl<<"Tree after removing 34 is ";
    tree.inorder();
    cout<<endl;
    return 0;
}