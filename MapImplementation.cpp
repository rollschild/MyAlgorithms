#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> m1;

    m1.insert(pair<int, int>(1, 40));
    m1.insert(pair<int, int>(2, 30));
    m1.insert(pair<int, int>(3, 60));
    m1.insert(pair<int, int>(4, 20));
    m1[5] = 50;
    m1[6] = 50;
    m1[7] = 49;
    m1[4] = 1000;
    m1[4] = -987; // will overwrite all previous values
    m1[8] = 50;
    m1[9] = 49;
    map<int, int>::iterator itr;
    cout << "Map m1: " << endl;
    cout << "Key\t" << "Value\t" << endl;
    for(itr = m1.begin(); itr != m1.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << "\t\n";
    }
    cout << endl;

    // construct m2 using m1
    map<int, int> m2(m1.begin(), m1.end());
    cout << "Now let's print m2: " << endl;
    cout << "Key\t" << "Value\t" << endl;
    for(itr = m2.begin(); itr != m2.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << "\t\n";
    }
    cout << endl;
    
    // remove all elements up to key=3 in m2
    m2.erase(m2.begin(), m2.find(3));
    cout << "Map m2 after erasing elements up to key = 3" << endl;
    cout << "Key\t" << "Value\t" << endl;
    for(itr = m2.begin(); itr != m2.end(); ++itr) {
         cout << itr->first << '\t' << itr->second << "\t\n";
     }
    cout << endl;
    
    // remove all elements with key = 4
    int num = 0;
    num = m2.erase(4);
    cout << "Now we try to remove all elements with key = 4" << endl;
    cout << num << " elements with key = 4 removed." << endl;
    for(itr = m2.begin(); itr != m2.end(); ++itr) {
         cout << itr->first << '\t' << itr->second << "\t\n";
     }
    cout << endl;

    // lower and upper bound for map m2 key = 6
    cout << "m2.lower_bound(6) : " << "\tKey = ";
    cout << m2.lower_bound(6)->first << "\t";
    cout << "Value = " << m2.lower_bound(6)->second << endl;
    cout << "m2.upper_bound(6) : " << "\tKey = ";
    cout << m2.upper_bound(6)->first << "\t";
    cout << "Value = " << m2.upper_bound(6)->second << endl;

    return 0;
}
