//Assignment 3
//Find if path exists in graph
//problem link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
class Solution {
public:
    bool validPath(int nodes, vector<vector<int>>& B, int source, int A) {
        if(nodes>source && nodes>A && B.empty()){return true;}
    
    vector<vector<int>> adj(nodes);
    for(auto it: B){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
        
    }
    queue<int> q;
    vector<int> vis(nodes,0);
    q.push(source);
    vis[source]=1;
    while(q.empty()==false){
        int temp = q.front();
        q.pop();
        for(auto ok: adj[temp]){
            if(ok==A){return true;}
            if(vis[ok]==0){
                vis[ok]=1;
                q.push(ok);
            }
        }
    }return false;
    }
};