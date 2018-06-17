#include <iostream>

using namespace std;

int MATRIX[4][4] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}};

bool whoKnows(int p1, int p2) {
    return MATRIX[p1][p2];
}

int find(int num) {
    int l = 0;
    int r = num - 1;
    while(l < r) {
        if(whoKnows(l, r)) {
            ++l;
        }
        else --r;
    }
    int vip = r;
    for(int i = 0; i < num; ++i) {
        if(i != vip && (whoKnows(vip, i) || !whoKnows(i, vip))) return -1;
    }

    return vip;
}

int main() {
    int n = 4;
    int id = find(n);
    id == -1 ? cout << "NOBODY!!! " : 
        cout << "Celebrity is " << id << endl;
    return 0;
}
