#include <string>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    int len = friends.size();
    vector<vector<int>> data(len, vector<int>(len, 0));
    vector<vector<int>> index(len, vector<int>(3,0));
    vector<int> count(len, 0);
    int giver, receiver;
    for (auto s : gifts){
        int space_idx = s.find(" ");
        string first = s.substr(0, space_idx);
        string second = s.substr(space_idx+1, -1);
        for (int i=0; i<len; i++){
            if (first == friends[i]) giver = i;
            else if (second == friends[i]) receiver = i;
        }
        data[giver][receiver]++;
    }
    
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++){
            index[i][0] += data[i][j];
            index[j][1] += data[i][j];
        }
    }
    
    for (int i=0; i<len; i++){
        for (int j=i+1; j<len; j++){
            if (data[i][j] > data[j][i]) count[i]++;
            else if (data[i][j] < data[j][i]) count[j]++;
            else {
                int first = index[i][0]-index[i][1];
                int second = index[j][0]-index[j][1];
                if ( first > second ) count[i]++;
                else if (first < second ) count[j]++;
            }
        }
    }
    
    for (auto i : count){
        if (answer < i) answer = i;
    }
    
    return answer;
}