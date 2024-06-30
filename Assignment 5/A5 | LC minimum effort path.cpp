//Assignment 5
//Lc problem link:https://leetcode.com/problems/path-with-minimum-effort/
//Minimum effort path

//Easy problem. Standard one.
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});  //effort,i,j
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty())
        {
             pair<int,pair<int,int>> it=pq.top();
             int effort=it.first;
             int row=it.second.first;
             int col=it.second.second;
             pq.pop();

            if(row==n-1 && col==m-1)
            return effort;

             for(int i=0;i<4;i++)
             {
                 int nrow=row+delrow[i];
                 int ncol=col+delcol[i];

                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                 {
                     int diff=abs(heights[row][col]-heights[nrow][ncol]);
                     int maxi=max(diff,effort);
                     if(maxi<dist[nrow][ncol])
                     {
                         dist[nrow][ncol]=maxi;
                          pq.push({maxi,{nrow,ncol}});
                     }
                 }
             }
        }
        return 0;
    }
};