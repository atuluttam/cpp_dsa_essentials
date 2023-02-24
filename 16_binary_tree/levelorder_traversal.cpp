/*---------------------------------------------------------------------
 *                  code : levelorder_traversal
 *               @author :  Atul Uttam
 *          Date Created :  19-02-2023(16:50:18)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

// input:  1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1, here -1 means that it is null
// lvelorder:
// 1
// 2 3
// 4 5 6
// 7

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

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void levelOrderPrint(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            // insert a new null for next leve
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

int main()
{
    Node *root = buildTree();
    cout << "pre-order: " << endl;
    levelOrderPrint(root);
    cout << endl;

    return 0;
}
