//Assignment 4
//Solution LC Problem: https://leetcode.com/problems/critical-connections-in-a-network/description/
//critical connections in a network.
//Attempted and couldn't solve by own. Needed to learn the logic and algorithm from internet
class Solution {
private:
    int timer =1;
private:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> & vis, vector<int> &low,vector<int> &tin, vector<vector<int>> & answers){
        tin[node]= timer;
        low[node] = timer;
        timer++;
        vis[node]=1;
        for(auto it: adj[node]){
            if(it==parent)continue;
            if(vis[it]==0){
                dfs(it,node,adj,vis,low,tin,answers);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    answers.push_back({it,node});
                }
            }else{
                low[node]= min(low[it],low[node]);
            }
        }

    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> answers;
        vector<vector<int>> adj(n);
        for(int i =0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> low(n);
        vector<int> tin(n);
        dfs(0,-1,adj,vis,low,tin,answers);
        return answers;
    }
};