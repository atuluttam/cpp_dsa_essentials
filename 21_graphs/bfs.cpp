/*---------------------------------------------------------------------
 *                  code :  bfs
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(00:17:33)
 --------------------------------------------------------------------*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int TotalVertices;
    list<int> *l;

public:
    Graph(int v)
    {
        TotalVertices = v;
        l = new list<int>[TotalVertices];
    }

    void addEdge(int from, int to, bool undir = true)
    {
        l[from].push_back(to);
        if (undir)
        {
            l[to].push_back(from);
        }
    }

    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[TotalVertices]{0};

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int front = q.front();
            cout << front << endl;
            q.pop();

            // push the neighbours of the current node inside the queue if they are not visited
            for (auto neighbour : l[front])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.bfs(1);

    return 0;
}
