/*---------------------------------------------------------------------
 *                  code : bst_creation
 *               @author :  Atul Uttam
 *          Date Created :  24-02-2023(19:51:20)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}
void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
bool search(Node*root, int key){
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(root->data > key){
        return search(root->left, key);
    }
    return search(root->right, key);
    
}
Node* findMin(Node* root){
    if(root->left != NULL)
        root = root->left;
    return root;
}
//bst deletion
Node* remove(Node* root,int key){
    if(root==NULL)
        return NULL;
    else if(key<root->data){
        root->left = remove(root->left, key);
    }
    else if(key>root->data){
        root->right = remove(root->right, key);
    }
    else{
        // this else block will execute when the current node matches with the key
        //case 1 no children
        if(root->left==NULL and root->right==NULL){
            delete root;
            root = NULL;
        }
        // single child
        else if(root->left==NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    int arr[] = {8, 10, 13, 2, 12, 15, 45, 78, 3, 6, 5, 4, 1};
    for (auto i : arr)
    {
        root = insert(root, i);
    }
    printInorder(root);
    int key;
    cin >> key;
    // cout << search(root, key)<<endl;
    root = remove(root, key);

    printInorder(root);

    return 0;
}
