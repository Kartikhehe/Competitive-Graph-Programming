//Assingment 4
//LeetCode Problem: https://leetcode.com/problems/detect-cycles-in-2d-grid/
//Detect cylce in 2D grid.


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        //Completed in one go...Single run and single submit. Damn Nice. Good work Kartik.
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,pair<int,int>>> q;

        for(int x = 0;x<n;x++){
            for(int y =0;y<m;y++){
                if(vis[x][y]==0){
                    q.push({{x,y},{x,y}});
                    vis[x][y]=1;
                    char ch = grid[x][y];
                    int dr[]={0,0,1,-1};
                    int dc[]={1,-1,0,0};
                    while(q.empty()==false){
                        int r = q.front().first.first;
                        int c = q.front().first.second;
                        int prevr = q.front().second.first;
                        int prevc = q.front().second.second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            int newr = r + dr[i];
                            int newc = c + dc[i];
                            if(newr>=0 && newc>=0 && newr<n && newc<m){
                                if(grid[newr][newc]==ch && vis[newr][newc]==0){
                                    q.push({{newr,newc},{r,c}});
                                    vis[newr][newc]=1;
                                }else if(grid[newr][newc]==ch && (newc!=prevc || newr!=prevr)){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
       return false;
    }
};