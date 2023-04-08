/*---------------------------------------------------------------------
 *                  code :  dijkstra_algorithm
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(02:31:14)
 --------------------------------------------------------------------*/

#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <climits>
using namespace std;

class Graph
{
    int TotalVertices;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        TotalVertices = v;
        l = new list<pair<int, int>>[TotalVertices];
    }

    void addEdge(int from, int to, int wt, bool undir = true)
    {

        l[from].push_back({wt, to});
        if (undir)
        {
            l[to].push_back({wt, from});
        }
    }

    int dijkstra(int src, int dest)
    {

        // Data Structures
        vector<int> dist(TotalVertices, INT_MAX);
        set<pair<int, int>> s;

        // 1. Init
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty())
        {

            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it); // Pop

            // Iterate over the nbrs of node
            for (auto nbrPair : l[node])
            {
                //......

                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (distTillNow + currentEdge < dist[nbr])
                {
                    // remove if nbr already exist in the set

                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    // insert the updated value with the new dist
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // Single Source Shortest Dist to all other nodes
        for (int i = 0; i < TotalVertices; i++)
        {
            cout << "Node " << i << " Dist " << dist[i] << endl;
        }
        return dist[dest];
    }
};

int main()
{

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkstra(0, 4) << endl;
}
