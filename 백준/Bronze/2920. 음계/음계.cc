#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> notes(8);
    for (int i = 0; i < 8; ++i) {
        cin >> notes[i];
    }

    bool ascending = true;
    bool descending = true;

    for (int i = 0; i < 7; ++i) {
        if (notes[i] < notes[i + 1]) {
            descending = false;
        } else if (notes[i] > notes[i + 1]) {
            ascending = false;
        }
    }

    if (ascending) {
        cout << "ascending" << endl;
    } else if (descending) {
        cout << "descending" << endl;
    } else {
        cout << "mixed" << endl;
    }

    return 0;
}