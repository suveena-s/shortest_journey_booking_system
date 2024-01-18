//
//  main.cpp
//  Shortest DSA Proj
//
//  Created by Shivam Sharma on 03/01/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
struct Node {
    int distance;
    int vertex;
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

class RailNetwork{
    vector<vector<Edge>>  adjacency_list;
    int num_vertices;
    public: 
        RailNetwork(int num_vertices){
            this->num_vertices = num_vertices;
            adjacency_list.resize(num_vertices);
        }
        void railNetworkInput(int source,int destination,int distance){
            adjacency_list[source].push_back(Edge(destination, distance));
        }
        vector<int> dijkstra(int source, int destination) {
            vector<int> seats;
            priority_queue<Node> pq;
            vector<int> distances(num_vertices, INF);
            unordered_map<int, int> previous;

            pq.push({0, source});
            distances[source] = 0;

            while (!pq.empty()) {
                Node current = pq.top();
                pq.pop();

                if (current.distance > distances[current.vertex]) {
                    continue;
                }

                for (const Edge& edge : adjacency_list[current.vertex]) {
                    int alt = current.distance + edge.weight;
                    if (alt < distances[edge.to]) {
                        distances[edge.to] = alt;
                        previous[edge.to] = current.vertex;
                        pq.push({alt, edge.to});
                    }
                }
            }

            // Print out the shortest path
            stack<int> path;
            int current = destination;
            while (current != source) {
                path.push(current);
                current = previous[current];
            }
            path.push(source);

            cout << "Shortest path from station " << source+1 << " to station " << destination+1 << ":" << endl;
            while (!path.empty()) {
                cout<<path.top()+1<< " ";
                seats.push_back(path.top());
                path.pop();
            }
            cout << endl;
            return seats;
        }
};
