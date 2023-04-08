/*---------------------------------------------------------------------
 *                  code : print_within_range
 *               @author :  Atul Uttam
 *          Date Created :  24-02-2023(23:40:25)
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

void printRange(Node *root, int k1, int k2)
{
    if (root == NULL)
        return;

    if (root->data >= k1 and root->data <= k2)
    {
        printRange(root->left, k1, k2);
        cout << root->data << " ";
        printRange(root->right, k1, k2);
    }
    else if (root->data > k2)
    {
        printRange(root->left, k1, k2);
    }
    else
    {
        printRange(root->right, k1, k2);
    }
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
    cout << endl;
    int k1, k2;
    cin >> k1 >> k2;
    
    printRange(root, k1, k2);
    cout << endl;

    return 0;
}
