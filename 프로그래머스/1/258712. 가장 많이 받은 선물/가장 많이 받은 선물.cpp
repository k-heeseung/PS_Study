#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int len = friends.size();
    vector<vector<int>> data(len, vector<int>(len, 0));
    vector<int> index(len, 0);
    vector<int> count(len, 0);
    map<string, int> m;
    for (int i=0; i<len; i++){
        m.insert({friends[i], i});
    }
    int giver, receiver;
    for (auto s : gifts){
        int space_idx = s.find(" ");
        string first = s.substr(0, space_idx);
        string second = s.substr(space_idx+1, -1);
        giver = m[first];
        receiver = m[second];
        data[giver][receiver]++;
        index[giver]++;
        index[receiver]--;
    }
    
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++){
            if (data[i][j] > data[j][i]) count[i]++;
            else if (data[i][j] == data[j][i]){
                if (index[i]>index[j]) count[i]++;
            }
        }
        answer = max(count[i], answer);
    }
    
    return answer;
}