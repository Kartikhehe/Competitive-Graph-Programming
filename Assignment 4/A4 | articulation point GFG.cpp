//Assignment 4
//GFG problem :
//Articulation point 1: https://www.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point
//passed 162 out of 165 test cases
//time limit exceeded for the last 3 cases. Later watched the solution for an optimal approach
//Below is My Code and method.



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void visit(int node, vector<int> adj[],vector<int> &vis){
        int x = node==0 ? 1 : 0;
        vis[x] =1;
        queue<int> q;
        q.push(x);
        while(q.empty()==false){
            int temp = q.front();
            q.pop();
            for(auto it: adj[temp]){
                if(it!=node && vis[it]!=1){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
  
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> answer;
        if(V<3){
            answer.push_back(-1);
            return answer;
        }
        
        for(int i=0;i<V;i++){
            vector<int> vis(V);
            visit(i,adj,vis);
            vis[i]=1;
            for(int j=0;j<V;j++){
                if(vis[j]!=1){
                    answer.push_back(i);
                    break;
                }
            }
        }
        
        return answer;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends