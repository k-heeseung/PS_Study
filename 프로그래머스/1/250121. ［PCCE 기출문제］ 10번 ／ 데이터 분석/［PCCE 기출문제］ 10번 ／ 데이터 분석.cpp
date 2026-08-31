#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> m;
    m["code"] = 0;
    m["date"] = 1;
    m["maximum"] = 2;
    m["remain"] = 3;
    int data_len = data.size();
    int ext_idx = m[ext];
    for (int i=0; i<data_len; i++){
        if (data[i][ext_idx] < val_ext){
            answer.push_back(data[i]);
        }
    }
    int sort_col = m[sort_by];
    sort(answer.begin(), answer.end(), [sort_col](const vector<int> &v1, vector<int> &v2){
        return v1[sort_col] < v2[sort_col];
    });
    
    
    return answer;
}