#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <memory>
#include <regex>
#include <map>

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#define INCBIN_PREFIX
#include "incbin.h"

INCBIN(msgs, "commit_messages.txt");

using namespace std;

const std::vector<string> NAMES = {"Nick", "Steve", "Andy", "Qi", "Fanny", "Sarah", "Cord", "Todd",
    "Chris", "Pasha", "Gabe", "Tony", "Jason", "Randal", "Ali", "Kim",
    "Rainer", "Guillaume", "Kelan", "David", "John", "Stephen", "Tom", "Steven",
    "Jen", "Marcus", "Edy", "Rachel"};

mt19937& get_rng() {
    static shared_ptr<mt19937> rng_ptr = NULL;
    if (NULL == rng_ptr) {
        rng_ptr = std::make_shared<mt19937>(mt19937());
        rng_ptr->seed(random_device()());
    }

    return *rng_ptr;
}

int get_random(int start, int end) {
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return dist(get_rng());
}

void replace_all(std::string& str, const std::string& from, const std::string& to) {
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

void replace_nums(std::string& str) {
    regex random_num_regex("XNUM(\\d+)(?:,(\\d+))?X");
    map<string, string> replacements;

    for (auto it = sregex_iterator(str.begin(), str.end(), random_num_regex); it != sregex_iterator(); it++) {
        smatch match = *it;
        
        int lower, upper;
        
        if ("" == match[2]) {
            lower = 1;
            upper = std::stoi(match[1]);
        } else {
            lower = std::stoi(match[1]);
            upper = std::stoi(match[2]);
        }

        replacements[match[0]] = std::to_string(get_random(lower, upper));
    }

    for (auto it : replacements) {
        replace_all(str, it.first, it.second);
    }
}

int main() {
    string msgs(msgs_data, msgs_data + msgs_size);
    int random = get_random(0, NAMES.size() - 1);
    replace_all(msgs, "XNAMEX", NAMES[random]);
    replace_all(msgs, "XUPPERNAMEX", NAMES[random]);
    replace_all(msgs, "XNUMX", std::to_string(get_random(1, 100)));

    // replace nums
    replace_nums(msgs);

    auto v = get_text(msgs);
    int text_index = get_random(0, v.size() - 1);
    cout << v[text_index] << endl;
}
