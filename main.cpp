#include <iostream>
#include <vector>
using namespace std;
const size_t MAX_LEN = 20;

int main(){
    string input;
    cin >> input;
    vector<string> sub;
    for (size_t i = 0; i < input.size(); i += MAX_LEN){
        sub.push_back(input.substr(i, min(input.size(), i+MAX_LEN)));
    }

    size_t res_len = min(MAX_LEN, input.size());
    cout << '/' << string(res_len, '-') << "\\\n";
    for (string s : sub) cout << '|' << s << "|\n";
    cout << '\\' << string(res_len, '-') << "/\n";
}
