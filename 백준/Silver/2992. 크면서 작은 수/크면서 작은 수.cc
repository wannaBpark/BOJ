#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    string original = s;
    if(next_permutation(s.begin(), s.end())) {
        cout << s;
    } else {
        cout << 0;
    }
    return 0;
}
