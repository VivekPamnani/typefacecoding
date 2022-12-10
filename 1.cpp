/*

0 0 0 0 0 0
0 0 0 1 1 0
0 0 0 0 0 0
0 1 1 1 1 0
0 1 1 1 1 0
0 0 1 0 1 0
0 0 0 0 0 0

[2.5, 3, 4, 5]


0 0 0 0 0 0 0
0 1 1 1 0 1 0
0 0 0 0 1 1 0
0 1 1 1 1 0 0
*/

#include <bits/stdc++.h>

using namespace std;

int check(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited)
{
    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && visited[x][y]==0  && grid[x][y]==1) 
        return 1;
    return 0;
}
int M, N;
int coun=0;
vector<int> lef={1,-1,0,0};
vector<int> righ={0,0,1,-1};
void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c) {
    coun++;
    stack<pair<int,int>> st;
    st.push({r,c});
    visited[r][c] = coun;
    // int blackLeft, blackRight
    while(!st.empty())
    {
        int x,y;
        x=st.top().first;
        y=st.top().second;
        st.pop();
        visited[x][y]=coun;
        int i,j;
        for(i=0;i<4;i++)
        {
            if(check(x+lef[i],y+righ[i],grid, visited))
            {
                st.push({x+lef[i],y+righ[i]});
            }
        } 
    }
}

int main() {
    cin >> M;
    cin >> N;
    vector<vector<int>> grid(M, vector<int>(N, -1));
    vector<vector<int>> visited(M, vector<int>(N, 0));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]==0 and grid[i][j]==1) {
                bfs(grid, visited, i, j);
            }
        }
    }
    vector<int> max_x(coun,INT_MIN);
    vector<int> min_x(coun,INT_MAX);
    vector<int> max_y(coun,INT_MIN);
    vector<int> min_y(coun,INT_MAX);
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]!=0)
            {
                max_x[visited[i][j]-1]=max(max_x[visited[i][j]-1],i);
                max_y[visited[i][j]-1]=max(max_y[visited[i][j]-1],j);
                min_x[visited[i][j]-1]=min(min_x[visited[i][j]-1],i);
                min_y[visited[i][j]-1]=min(min_y[visited[i][j]-1],j);
            }
        }
    }
    // for(int i = 0; i < M; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(int i=0;i<coun;i++)
    {
        // cout << float(max_x[i]+min_x[i])/2 << ' ' << float(max_y[i]+min_y[i])/2 << ' ' << max_x[i]-min_x[i]+1 << ' ' << max_y[i]-min_y[i]+1 << endl;
        cout <<  float(max_y[i]+min_y[i])/2 << ' ' << float(max_x[i]+min_x[i])/2 << ' ' <<  max_y[i]-min_y[i]+1 << ' ' << max_x[i]-min_x[i]+1 << endl;
    }
}