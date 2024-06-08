//Assignment 3
//Flood fill
//Problem link:https://docs.google.com/document/d/1Wsm1DOs4eQ-W-o5m7pSvJ76Bt7Bu1FxduMoCWQ4Q5-4/edit
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //if(image==nullptr){return nullptr;}
        //interesting question. Took multiple attempt to solve completely but was really joyful.
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(image.size(),vector<int> (image[0].size(),0)) ;
        vis[sr][sc]=1;
        int current = image[sr][sc];
        image[sr][sc] = color;
        while(sr>= 0 && sc>=0 && sr<image.size() && sc <image[0].size() && q.empty()==false){
            auto temp = q.front();
            q.pop();
            sr = temp.first;
            sc = temp.second;
            if(sr-1>= 0 && image[sr-1][sc]==current && vis[sr-1][sc]==0){
                q.push({sr-1,sc});
                image[sr-1][sc]= color;
                vis[sr-1][sc]=1;
            }if(sc-1>= 0 && image[sr][sc-1]==current && vis[sr][sc-1]==0){
                q.push({sr,sc-1});
                image[sr][sc-1]= color;
                vis[sr][sc-1]=1;
            }if(sc+1< image[0].size() && image[sr][sc+1]==current && vis[sr][sc+1]==0){
                q.push({sr,sc+1});
                image[sr][sc+1]= color;
                vis[sr][sc+1]=1;
            }if(sr+1< image.size() && image[sr+1][sc]==current && vis[sr+1][sc]==0){
                q.push({sr+1,sc});
                image[sr+1][sc]= color;
                vis[sr+1][sc]=1;
            }

        }return image;
    }
};