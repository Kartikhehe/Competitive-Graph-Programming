//Assignment 3
//problem link: https://www.interviewbit.com/problems/snake-ladder-problem/
//snake and ladder:

//couldn't get all test cases passed, even after spending 2 hours.

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    int vis[101]={0};
    int answer =INT_MAX;
    int sln[101] = {0}; //snake, ladder, or none. snake =-1, ladder = 1, none = 0
    vector<vector<int>> adj(101);
    for(int i=0;i<A.size();i++){
        adj[A[i][0]].push_back(A[i][1]);
        sln[A[i][0]]=1;
    
    }for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        sln[B[i][0]] = -1;
    
    }
    
    for(int i=1;i<101;i++){
        if(adj[i].empty()==true){
            for(int j =1;j<7;j++){
            if (i + j <= 100) {
                    adj[i].push_back(i + j);
                }}
        }
    }
    
    queue<int> q;
	    vis[1]=1;
	    q.push(1);
	    int level =0;
	    
	    while(q.empty()==false){
	        int size = q.size();
            int temp;
	        
	        for(int i=0;i<size;i++){
	            
	            temp = q.front();
	            q.pop();
	            if(temp == 100){answer = min(level, answer);level =0;}
	            for(int j=0;j<adj[temp].size();j++){
	                if(vis[adj[temp][j]] == 0){//checking if it isn't the previous(parent) node.
	                    q.push(adj[temp][j]);
	                    vis[adj[temp][j]]=1;
                        if (sln[adj[temp][j]] != 0) {
                        continue;
                    }
	                }
	            }
	        }if(size!=1 || temp==99){level++;}
	    }
        if(answer == INT_MAX){return -1;}
    return answer;
}
