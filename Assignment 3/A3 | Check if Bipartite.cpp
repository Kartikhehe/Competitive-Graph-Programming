//Assingment 3
//check if Bipartite
//Problem link:https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int Tnodes = graph.size();
        vector<int> colors(Tnodes,-1);
        
        int checkDiscont = 0;
        for(int j =0;j<Tnodes;j++){
            
            if(colors[j]==-1){
                queue<pair<int,int>> q;
                q.push({j,-1});
                colors[j] = 0;
        while(q.empty()==false){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            checkDiscont ++;
            for(int i=0;i<graph[node].size();i++){
                if(colors[graph[node][i]] == -1){
                q.push({graph[node][i],node});}
                if(colors[node]==0 && (colors[graph[node][i]]==-1 || colors[graph[node][i]]==1)){
                    colors[graph[node][i]]=1;
                }else if(colors[node]==1 && (colors[graph[node][i]]==-1 || colors[graph[node][i]]==0)){
                    colors[graph[node][i]]=0;
                    }else{
                        return false;
                    }
                
            }
        }}}
        return true;

    }
};