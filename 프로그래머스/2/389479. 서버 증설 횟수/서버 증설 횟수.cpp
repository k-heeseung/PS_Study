#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(50,0);
    int len = players.size();
    for (int i=0; i<len; i++){
        cout << "i=" << i << ", server: " << server[i] << endl;
        int user = players[i];
        cout << "user = " << user << endl;
        int a = user/m; //필요한 서버 개수
        if (a > server[i]){
            int tmp = a-server[i];
            answer+=tmp;
            for (int j=i; j<i+k; j++){
                server[j] += tmp;
            }
        }
    }
    
    return answer;
}