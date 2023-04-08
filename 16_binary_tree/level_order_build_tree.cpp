/*---------------------------------------------------------------------
 *                  code : level_order_build_tree
 *               @author :  Atul Uttam
 *          Date Created :  19-02-2023(20:35:53)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

// input:  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, here -1 means that it is null
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
            // insert a new null for next level
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
Node *levelOrderBuild()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            current->left = new Node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int main()
{
    Node *root = levelOrderBuild();
    cout << "pre-order: " << endl;
    levelOrderPrint(root);
    cout << endl;

    return 0;
}
