#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRatings(vector<int> ratings) {
    vector<int> results;
    results.push_back(0);
    for(int i = 0; i < ratings.size()-1; ++i) {
        int tempsize = results.size();
        int howmany = 0;
        for(int j = 0; j < tempsize; ++j) {
            if(i+j < ratings.size()) {
                results.push_back(results[j] + ratings[i+j]);
                ++howmany;
            }
<<<<<<< HEAD
            
            else {
                results.push_back(results[j]);
            }
            
=======

            else {
                results.push_back(results[j]);
            }

>>>>>>> 8c0a5cc1eadf2473a708aae0e6a2b3dfdeac0546
            if(i+j+1 < ratings.size()) {
                results.push_back(results[j] + ratings[i+1+j]);
                ++howmany;
            }
        }
<<<<<<< HEAD
        
        if(i == ratings.size() - 2) {
            results.erase(results.begin(), results.begin()+tempsize-1);
        }
=======

        if(i == ratings.size() - 2) {
            results.erase(results.begin(), results.begin()+tempsize-1);
        }                                                                       
>>>>>>> 8c0a5cc1eadf2473a708aae0e6a2b3dfdeac0546
        else
            results.erase(results.begin(), results.begin()+tempsize);
    }
    for(auto c : results) {
        cout << c << " ";
    }
    cout << endl;
    return *max_element(results.begin(), results.end());
}

int main() {
    vector<int> vec1 = {-1, -2, -3, -4, -5};
    vector<int> vec2 = {9, -1, -3, 4, 5};
    vector<int> vec3 = {-1, -2, -3};
    int result = maxRatings(vec1);
    cout << result << endl;
    return 0;
}
