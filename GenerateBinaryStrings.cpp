#include <iostream>
#include <queue>

using namespace std;

void print(string str) {
    queue<string> q;
    q.push(str);

    while(!q.empty()) {
        string s = q.front();
        // size_t please NOTICE this
        size_t index = s.find('?');
        if(index != string::npos) {
            s[index] = '0';
            q.push(s);
            s[index] = '1';
            q.push(s);
        }
        else {
            cout << s << endl;
        }
        q.pop();
    }
}

int main() {
    string str = "1??0?101";
    print(str);
    return 0;
}
