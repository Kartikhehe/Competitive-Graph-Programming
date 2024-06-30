//Assignment 5
//LC problem : https://leetcode.com/problems/cheapest-flights-within-k-stops/
//Cheapest flights within K stops



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<tuple<int, int, int>> q; // (cost, current node, stops)
        q.push({0, src, 0});
        dist[src] = 0;

        while(!q.empty()){
            auto [cost, node, stops] = q.front();
            q.pop();
            
            if (stops > k) {
                continue;
            }

            for (auto& [next, price] : adj[node]) {
                int new_cost = cost + price;
                if (new_cost < dist[next]) {
                    dist[next] = new_cost;
                    q.push({new_cost, next, stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
