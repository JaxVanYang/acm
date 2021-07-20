#include <iostream>
#include <vector>
using namespace std;

vector<string> fracs[8];


void init(int n) {
    if (fracs[n].size()) return;
    init(n - 1);
    int part_size = fracs[n - 1].size();
    fracs[n].resize(part_size * 3);
    string blank = string(part_size, ' ');
    for (int i = 0; i < part_size; ++i) {
        string &part = fracs[n - 1][i];
        string side_part = part + blank + part;
        string mid_part = blank + part + blank;
        fracs[n][i].append(side_part);
        fracs[n][2 * part_size + i].append(side_part);
        fracs[n][part_size + i].append(mid_part);
    }
}

void init() {
    fracs[1].push_back("X");
    init(7);
}

void print(vector<string> &frac) {
    for (auto s : frac) {
        puts(s.c_str());
    }
}


int main() {
    init();
    int n;
    while (~scanf("%d", &n) && n != -1) {
        print(fracs[n]);
        puts("-");
    }
}