#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;
const size_t MAX_LEN = 20;

int main(){
    string input;
    cin >> input;
    size_t width = min(MAX_LEN, input.size());
    vector<string> sub;
    for (size_t i = 0; i < input.size(); i += width){
        sub.push_back(input.substr(i, width));
    }

    cout << '/' << string(width, '-') << "\\\n";
    for (string s : sub){
        cout << '|' << s << string(width-s.size(), ' ') << "|\n";
    }
    cout << '\\' << string(width, '-') << "/\n";

    ifstream mili("mili.txt");
    assert(mili);
    string s;
    while (getline(mili, s)) cout << s << '\n';
    return 0;
}
