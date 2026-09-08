#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int len = mats.size();
    int flag;
    int pk_x = park.size();
    int pk_y = park[0].size();
    int answer = -1;
    
    // 내림차순 정렬
    sort(mats.begin(), mats.end(), [](int a, int b){
        return a > b;
    });
    for (int i=0; i<len; i++){
        for (int x=0; x+mats[i]<=pk_x; x++){
            for (int y=0; y+mats[i]<=pk_y; y++){
                flag = 1;
                for (int j=0; j<mats[i]; j++){
                    for (int k=0; k<mats[i]; k++){
                        int cur_x = x+j;
                        int cur_y = y+k;
                        if (park[cur_x][cur_y] != "-1"){
                            flag = 0;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag){
                    return mats[i];
                }
            }
        }
    }
    return answer;
}