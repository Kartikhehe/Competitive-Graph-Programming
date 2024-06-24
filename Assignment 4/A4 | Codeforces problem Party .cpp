#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vis(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(temp==-1){
            continue;
        }else{
            adj[temp].push_back(i);
        }
    }
    int answer=INT_MIN;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            queue<int> q;
            q.push(i);
            int check =0;
            while(q.empty()==false){
                int size = q.size();
                for(int j=0;j<size;j++){
                    int ok = q.front();
                    q.pop();
                    for(int k=0;k<adj[ok].size();k++){
                        q.push(adj[ok][k]);
                    }
                }check++;
                

            }answer = max(answer,check);
        }
    }
    cout<<answer;
    


    return 0;
}