#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRatings(vector<int> ratings) {
    // int result = 0;
    vector<int> results;
    results.push_back(0);
    // cout << results.size() << endl;
    // cout << ratings.size() << endl;
    // vector<int>::iterator itr;
    for(int i = 0; i < ratings.size()-1; ++i) {
        int tempsize = results.size();
        // cout << tempsize << endl;
        // int sum1 = ratings[i+1];
        // int sum2 = ratings[i+2];
        for(int j = 0; j < tempsize; ++j) {
            if(i+j < ratings.size())
                results.push_back(results[j] + ratings[i+j]);
            if(i+j+1 < ratings.size())
                results.push_back(results[j] + ratings[i+1+j]);
        }

        /*
        for(auto c : results) {
            cout << c << " ";
        }
        cout << endl;
        */
        if(i == ratings.size() - 2) continue;
        results.erase(results.begin(), results.begin()+tempsize);
    }
    // sort(results.begin(), results.end());
    for(auto c : results) {
        cout << c << " ";
    }
    cout << endl;
    return *max_element(results.begin(), results.end());
}

int main() {
    vector<int> vec = {-1, -2, -3, -4, -5};
    vector<int> vec2 = {9, -1, -3, 4, 5};
    int result = maxRatings(vec2);                                              
    cout << result << endl;
    return 0;
}
