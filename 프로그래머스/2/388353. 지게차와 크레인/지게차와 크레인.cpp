#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<vector<int>> mark(55, vector<int>(55,-1));
int n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int check(int i, int j, int time){
    vector<vector<int>> visited(55, vector<int>(55,0));
    stack<pair<int, int>> s;
    s.push({i,j});
    visited[i][j] = 1;
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        for (int i=0; i<4; i++){
            int cur_x = x+dx[i];
            int cur_y = y+dy[i];
            if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m) return 1;
            if (visited[cur_x][cur_y]) continue;
            else if (mark[cur_x][cur_y] != -1 && mark[cur_x][cur_y] != time){
                s.push({cur_x, cur_y});
                visited[cur_x][cur_y] = 1;
            }
        }
    }
        
    return 0;
}

void find(int type, string r, int time, vector<string> &map){
    if (type==1){
      for (int i=0; i<n; i++){
          for (int j=0; j<m; j++){
              if (mark[i][j] == -1 && map[i][j] == r[0]){ // 찾는 물건
                  if (check(i, j, time)) mark[i][j] = time;

              }
          }
      }
    }
    else { //type = 2
        for (int i=0; i<n; i++){
          for (int j=0; j<m; j++){
              if (mark[i][j] == -1 && map[i][j] == r[0]) mark[i][j] = time;
          }
      }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size();
    m = storage[0].size();

    int len = requests.size();
    for(int i=0; i<len; i++){
        string r = requests[i];
        if (r.length() > 1){
            find(2, r, i, storage);
        }
        else{
            find(1, r, i, storage);
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mark[i][j]==-1) answer++;
        }
    }
    
    return answer;
}