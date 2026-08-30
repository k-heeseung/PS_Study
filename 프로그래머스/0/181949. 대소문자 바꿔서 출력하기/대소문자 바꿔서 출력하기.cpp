#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (auto c : str){
        if (c <= 'z' && c >= 'a')
            c -= 'a' - 'A';
        else c += 'a' - 'A';
        cout << c;
    }
    
    return 0;
}