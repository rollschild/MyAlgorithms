#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getStores(string directions) {
    vector< vector<bool> > stores(1, vector<bool>(1));
    int l = directions.length();
    if(l == 0) return 0;
    int counter = 0;
    stores[0][0] = true;
    int r = 0;
    int c = 0;
    for(int i = 0; i < l; ++i) {
        char dir = directions[i];
        if(dir == '<') {
            if(c == 0) {
                auto itr = stores[r].begin();
                stores[r].insert(itr, false);
                stores[r][c] = true;
                ++counter;
            }
            else {
                if(stores[r][c-1] == false) {
                    stores[r][c-1] = true;
                    ++counter;
                }
                --c;
            }
        }
        if(dir == '>') {
            if(c == stores[r].size()-1) {
                // end of row
                stores[r].push_back(true);
                ++counter;
                c = stores[r].size()-1;    
            }
            else {
                if(stores[r][c+1] == false) {
                    stores[r][c+1] = true;
                    ++counter;
                }
                ++c;
            }
        }
        if(dir == '^') {
            // up
            if(r == 0) {

                int rowsize = stores[r].size();
                auto itr = stores.begin();
                stores.insert(itr, vector<bool>(rowsize));
                // r is still 0 here
                stores[r].assign(rowsize, false);
                stores[r][c] = true;
                ++counter;
            }
            else {
                if(stores[r-1][c] == false) {
                    stores[r-1][c] = true;
                    ++counter;
                }
                --r;
            }
        }
        if(dir == 'v') {
            if(r == stores.size()-1) {
                int rowsize = stores[r].size();
                stores.push_back(vector<bool>(rowsize));
                r = stores.size() - 1;
                stores[r].assign(rowsize, false);
                stores[r][c] = true;
                ++counter;
            }
            else {
                if(stores[r+1][c] == false) {
                    stores[r+1][c] = true;
                    ++counter;
                }
                ++r;
            }
        }
    }

    return counter;

}



int main() {
    string str = "^v<>^^><vv";
    cout << getStores(str) << endl;
    return 0;
}
