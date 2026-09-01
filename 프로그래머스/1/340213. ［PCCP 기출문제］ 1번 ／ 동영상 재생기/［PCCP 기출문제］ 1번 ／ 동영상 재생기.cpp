#include <string>
#include <vector>

using namespace std;

int to_time (string str){
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_len_ = to_time(video_len);
    int pos_ = to_time(pos);
    int op_s_ = to_time(op_start);
    int op_e_ = to_time(op_end);
    
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
    int pos_m = pos_/60;
    int pos_s = pos_%60;
    if (pos_m < 10) answer_m = "0" + to_string(pos_m);
    else answer_m = to_string(pos_m);
    if (pos_s < 10) answer_s = "0" + to_string(pos_s);
    else answer_s = to_string(pos_s);
    string answer = answer_m + ":" + answer_s;
    
    return answer;
}