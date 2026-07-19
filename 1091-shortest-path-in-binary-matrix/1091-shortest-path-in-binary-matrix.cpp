class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1|| grid[n-1][n-1]==1){
            return -1;
        }
        queue<vector<int>>q;
        q.push({0,0,1});//row,col,current_path_length
        while(!q.empty()){
            vector<int>cur=q.front();
            q.pop();
            int r=cur[0];
            int c=cur[1];
            int dist=cur[2];
            if(r==n-1 && c==n-1){
                return dist;
            }
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        q.push({nr,nc,dist+1});

                    }
                }
            }

        }
        return -1;
        
    }
};