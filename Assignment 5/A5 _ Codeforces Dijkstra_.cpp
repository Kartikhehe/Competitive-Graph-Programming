//assignment 5 
//codeforces problem link:https://codeforces.com/contest/20/problem/C
// Dijsktra?


#include <bits/stdc++.h>
using namespace std;


//took multiple attempts but, was worth solving. Learnt a lot from this question

void printParents(unordered_map<int,int> &parents,int n,int curr){
    if(curr == -1){
        return;
    }
    printParents(parents,n,parents[curr]);
    cout<<curr<<" ";
    return;
    
}




int main() {
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<pair<int,int>>> adj(n+1);//node, weight'
    for(int i =0;i<m;i++){
        int a,b,w;
        cin>>a;cin>>b;cin>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        
    }

    vector<long long> dist(n+1,LLONG_MAX);
    dist[1]=0;
    vector<bool> visited(n + 1, false);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    q.push({0,1});
    unordered_map<int,int> parents;
    while(q.empty()==false){
        long long distance = q.top().first;
        int node = q.top().second;
        
        q.pop();
         if (visited[node]) continue;
        visited[node] = true;
        for(auto it: adj[node]){//here, it.second is weight and first is node adjacent
            if(it.second + distance < dist[it.first]){
                parents[it.first] = node;
                dist[it.first]= it.second + distance;
                q.push({dist[it.first],it.first});
            }
        }
    }parents[1] =-1;

    //printing parents
    if(dist[n]!=LLONG_MAX){
        printParents(parents,n,n);
    }else{
        cout<<"-1";
        return 0;
    }
    
    

    return 0;
}