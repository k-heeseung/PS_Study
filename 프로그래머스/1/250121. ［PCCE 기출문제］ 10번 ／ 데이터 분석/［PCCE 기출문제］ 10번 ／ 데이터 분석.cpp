#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> m;
    m["code"] = 0;
    m["date"] = 1;
    m["maximum"] = 2;
    m["remain"] = 3;
    int data_len = data.size();
    int ext_idx = m[ext];
    auto it = remove_if(data.begin(), data.end(), [ext_idx, val_ext](auto &row){
        return (row[ext_idx] == val_ext) || (row[ext_idx] > val_ext);
    });
    data.erase(it, data.end());
    
    int sort_col = m[sort_by];
    sort(data.begin(), data.end(), [sort_col](const vector<int> &v1, vector<int> &v2){
        return v1[sort_col] < v2[sort_col];
    });
    
    
    return data;
}