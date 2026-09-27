#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;
const size_t WIDTH = 20;

int utf8_width(unsigned char c){
    if (c < 0x80) return 1;
    if ((c&0xE0) == 0xC0) return 2;
    if ((c&0xF0) == 0xE0) return 3;
    if ((c&0xF8) == 0xF0) return 4;
    return 1;
}

string next_char(const string& s, size_t& i){
    size_t len = utf8_width(static_cast<unsigned char>(s[i]));
    string res = s.substr(i, len);
    i += len;
    return res;
}

int char_display_width(const string& c){
    unsigned char x = static_cast<unsigned char>(c[0]);
    if (x < 0x80) return 1;
    if ((x & 0xF0) == 0xE0) return 2;
    if ((x & 0xF8) == 0xF0) return 2;
    return 1;
}

int display_width(const string& s){
    int res = 0;
    for (size_t i = 0; i < s.size(); ){
        string c = next_char(s, i);
        res += char_display_width(c);
    }
    return res;
}

int main(int argc, char* argv[]){
    if (argc == 1) return 0;
    string input;
    for (int i = 1; i < argc; i++){
        if (i > 1) input += " ";
        input += argv[i];
    }

    vector<string> substrs;
    string cur_str;
    int cur_width = 0;
    for (size_t i = 0; i < input.size(); ){
        string c = next_char(input, i);
        int w = char_display_width(c);
        if (cur_width+w > WIDTH){
            substrs.push_back(cur_str);
            cur_str.clear();
            cur_width = 0;
        }
        cur_str += c, cur_width += w;
    }
    if (!cur_str.empty()){
        substrs.push_back(cur_str);
    }

    int width = 0;
    for (const string& s : substrs) width = max(width, display_width(s));
    cout << '/' << string(width, '-') << "\\\n";
    for (const string& s : substrs){
        cout << '|' << s << string(width-display_width(s), ' ') << "|\n";
    }
    cout << '\\' << string(width, '-') << "/\n";

    ifstream mili("mili.txt");
    assert(mili);
    string s;
    while (getline(mili, s)) cout << s << '\n';
    return 0;
}
