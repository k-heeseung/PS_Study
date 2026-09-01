#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int video_len_idx = video_len.find(":");
    int video_len_m = stoi(video_len.substr(0, video_len_idx));
    int video_len_s = stoi(video_len.substr(video_len_idx+1));
    int pos_idx = pos.find(":");
    int pos_m = stoi(pos.substr(0, pos_idx));
    int pos_s = stoi(pos.substr(pos_idx+1));
    int op_s_idx = op_start.find(":");
    int op_s_m = stoi(op_start.substr(0, op_s_idx));
    int op_s_s = stoi(op_start.substr(op_s_idx+1));
    int op_e_idx = op_end.find(":");
    int op_e_m = stoi(op_end.substr(0, op_e_idx));
    int op_e_s = stoi(op_end.substr(op_e_idx+1));
    int video_len_ = (video_len_m)*60 + video_len_s;
    int pos_ = (pos_m)*60 + pos_s;
    int op_s_ = (op_s_m)*60 + op_s_s;
    int op_e_ = (op_e_m)*60 + op_e_s;
    
    for (auto c : commands){
        // 오프닝 건너뛰기
        if (pos_ >= op_s_ && pos_ <= op_e_) pos_ = op_e_;
        if (c=="prev"){
            pos_ -= 10;
            if (pos_ < 0) pos_ = 0;
        }
        else if (c=="next"){
            pos_ += 10;
            if (pos_ > video_len_) pos_ = video_len_;
        }
        // 오프닝 건너뛰기
        if (pos_ >= op_s_ && pos_ <= op_e_) pos_ = op_e_;
    }
    
    string answer_m, answer_s;
    pos_m = pos_/60;
    pos_s = pos_%60;
    if (pos_m < 10) answer_m = "0" + to_string(pos_m);
    else answer_m = to_string(pos_m);
    if (pos_s < 10) answer_s = "0" + to_string(pos_s);
    else answer_s = to_string(pos_s);
    answer = answer_m + ":" + answer_s;
    
    return answer;
}