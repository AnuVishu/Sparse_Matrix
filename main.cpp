#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int main()
{
    vector<string> input;
    int tt;

    cin >> tt;
    string name;
    for(size_t i=0 ; i<tt ; ++i) {
        input.pb(input);
    }

    for(size_t i=0 ; i<tt ; ++i) {
        cout << input[i] << endl;
    }
}
