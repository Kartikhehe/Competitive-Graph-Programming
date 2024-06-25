//assignment 4
//Lc problem: https://leetcode.com/problems/longest-cycle-in-a-graph/description/
//Longest cycle in a graph



class Solution {
public:
    int isCycle(int sv, vector<vector<int>> &edges, vector<bool> &vis, set<int> &s){
        vis[sv]=true;
        s.insert(sv);
        for(int i=0;i<edges[sv].size();i++){
            if(s.find(edges[sv][i]) != s.end())
                return sv;
            if(!vis[edges[sv][i]]){
                int x = isCycle(edges[sv][i], edges, vis, s);
                if(x!=-1)
                    return x;
            }
        }
        s.erase(sv);
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int ans=-1;
        int n = edges.size();
        vector<vector<int>> v(n);
        for(int i=0; i<n; i++){
            if(edges[i]!=-1) v[edges[i]].push_back(i);
        }
        vector<bool> vis(edges.size(), false);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            set<int> S;
            int getAns=isCycle(i,v,vis,S);
            if(getAns>-1){
                int c=1;
                int sv=i;
                while(edges[sv]!=i)
                    sv=edges[sv], c++;
                ans=max(ans, c);
            }
        }
        return ans;
    }
};