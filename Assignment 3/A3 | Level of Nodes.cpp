//problem link: https://www.geeksforgeeks.org/problems/level-of-nodes-1587115620/1
// Assignment 3
//Level of Nodes
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	//VVI question(need to be revised a lot)
	//took a lot of time and attempts to take the correct approach and debug the mistakes.
	int nodeLevel(int V, vector<int> adj[], int X){
	    int vis[V] = {0};
	    queue<int> q;
	    vis[0]=1;
	    q.push(0);
	    int level =0;
	    
	    while(q.empty()==false){
	        int size = q.size();
	        
	        for(int i=0;i<size;i++){
	            
	            int temp = q.front();
	            q.pop();
	            if(temp == X){return level;}
	            for(int j=0;j<adj[temp].size();j++){
	                if(vis[adj[temp][j]] == 0){//checking if it isn't the previous(parent) node.
	                    q.push(adj[temp][j]);
	                    vis[adj[temp][j]]=1;
	                }
	            }
	        }level++;
	    }return -1;
	    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends