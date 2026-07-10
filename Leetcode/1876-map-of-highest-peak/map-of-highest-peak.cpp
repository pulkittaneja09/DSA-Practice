class Solution {

public:
    void bfs(vector<vector<int>> &iswater,vector<vector<int>> &height,queue<pair<int,int>> &q){
        int m=iswater.size();
        int n=iswater[0].size();
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];
                if(nx>=0 && nx<m && ny>=0 && ny<n && height[nx][ny] ==-1 ){
                    height[nx][ny]=height[x][y]+1;
                    q.push({nx,ny});
                }

            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        bfs(isWater,height,q);
        return height;
    }
};