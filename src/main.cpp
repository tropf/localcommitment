#include <iostream>
#include <vector>
#include <sstream>
#include <random>

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#define INCBIN_PREFIX
#include "incbin.h"

INCBIN(msgs, "commit_messages.txt");

using namespace std;

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
    auto v = get_text(msgs);

    mt19937 rng;
    rng.seed(random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, v.size() - 1);

    cout << v[dist(rng)] << endl;
}
