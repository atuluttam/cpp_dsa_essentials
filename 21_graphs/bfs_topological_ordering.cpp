/*---------------------------------------------------------------------
 *                  code :  bfs_topological_ordering
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(01:19:07)
 --------------------------------------------------------------------*/

#include <iostream>
#include <list>
#include <queue>
#include <vector>
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

    void addEdge(int from, int to)
    {
        // directed graph
        l[from].push_back(to);
    }

    void bfsTopologicalSort()
    {
        vector<int> indegree(TotalVertices, 0);

        // iterate over all the edges to find the right endegree
        for (int i = 0; i < TotalVertices; i++)
        {
            for (auto neighbour : l[i])
            {
                indegree[neighbour]++;
            }
        }
        // bfs]
        queue<int> q;
        // push all the nodes having 0 indegree
        for (int i = 0; i < TotalVertices; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // start poping
        while (!q.empty())
        {
            int node = q.front();
            cout << node << ",";
            q.pop();

            // iterate over neighbours of this node and reduce their indegreeby 1
            for (auto neighbour : l[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
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

    g.bfsTopologicalSort();

    return 0;
}
