//Assignment 3
//Interview bit: path in a directed graph
//Problem link: https://www.interviewbit.com/problems/path-in-directed-graph/

int Solution::solve(int A, vector<vector<int> > &B) {
    int nodes =0;
    //creating adjaceny vector
    
    for(auto it: B){
        nodes= max(nodes,it[0]);
        nodes = max(nodes, it[1]);
        
    }
    
    vector<vector<int>> adj(nodes+1);
    for(auto it: B){
        adj[it[0]].push_back(it[1]);
        
    }
    queue<int> q;
    int vis[nodes+1]= {0};
    q.push(1);
    vis[1]=1;
    while(q.empty()==false){
        int temp = q.front();
        q.pop();
        for(auto ok: adj[temp]){
            if(ok==A){return 1;}
            if(vis[ok]==0){
                vis[ok]=1;
                q.push(ok);
            }
        }
    }return 0;
}
