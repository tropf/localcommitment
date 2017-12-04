#include <iostream>
#include <vector>
#include <sstream>
#include <random>

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#define INCBIN_PREFIX
#include "incbin.h"

INCBIN(msgs, "commit_messages.txt");

using namespace std;

const std::vector<string> NAMES = {"Nick", "Steve", "Andy", "Qi", "Fanny", "Sarah", "Cord", "Todd",
    "Chris", "Pasha", "Gabe", "Tony", "Jason", "Randal", "Ali", "Kim",
    "Rainer", "Guillaume", "Kelan", "David", "John", "Stephen", "Tom", "Steven",
    "Jen", "Marcus", "Edy", "Rachel"}

mt19937 get_random(int start, int end) {
    mt19937 rng;
    rng.seed(random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return rng;
}




void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case "to" contains "from", like replacing "x" with "yx"
    }
}

vector<string> get_text(string text) {
    vector<string> v;
    stringstream ss(text);
    string line;
    while(getline(ss, line)) {
        v.push_back(line);
    }
    return v;
}

int main() {
    string msgs(msgs_data, msgs_data + msgs_size);
    mt19937 random1 = get_random(0, NAMES.size() - 1);
    replaceAll(msgs, "XNAMEX", NAMES[random1]);
    replaceAll(msgs, "XUPPERNAMEX", NAMES[random1]);


    auto v = get_text(msgs);

    mt19937 rng = get_random(0, v.size() - 1);

    cout << v[dist(rng)] << endl;
}
