#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
}

vector<string> get_text(string text) {
    vector<string> v;
    stringstream ss(text);
    string line;
    while(getline(ss, line)) {
        v.push_back();
    }
    
    return v;
}
