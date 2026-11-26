class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int e_r = entrance[0];
        int e_c = entrance[1];
        deque<vector<int>> q;
        maze[e_r][e_c] = '+';
        q.push_back({e_r,e_c,0});
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){

            vector<int> curr = q.front();
            int r = curr[0];
            int c = curr[1];
            int steps = curr[2];
            q.pop_front();
            if((r != e_r || c != e_c) && (r == 0 || c == 0 || r == m-1 || c == n-1) ) return steps;
            for(int i=0;i<dir.size();i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr >=0 && nc >= 0 && nr <=m-1 && nc <=n-1 && maze[nr][nc] == '.'){
                    maze[nr][nc] = '+';
                    q.push_back({nr,nc,steps+1});
                }
            }
        }
        return -1;
    }
};