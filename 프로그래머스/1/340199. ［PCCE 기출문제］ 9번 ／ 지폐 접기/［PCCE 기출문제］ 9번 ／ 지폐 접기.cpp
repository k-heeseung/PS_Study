#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wallet_a = wallet[0];
    int wallet_b = wallet[1];
    if (wallet_a > wallet_b) {
        int tmp = wallet_a;
        wallet_a = wallet_b;
        wallet_b = tmp;
    }
    while(1){
        if (bill[0] > bill[1]){
            if (bill[0] > wallet_b || bill[1] > wallet_a){
                bill[0] = bill[0]/2;
                answer++;
            }
            else return answer;
        }
        else {
            if (bill[1] > wallet_b || bill[0] > wallet_a){
                bill[1] = bill[1]/2;
                answer++;
            }
            else return answer;
        }
    }
}