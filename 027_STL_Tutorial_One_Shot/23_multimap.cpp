#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, int> m;

    // inserting values using emplace
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("laptop", 120);
    m.emplace("watch", 50);

    cout << "Before erase:\n";
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    // erase one occurrence of "tv"
    auto it = m.find("tv");  // finds the first "tv"
    if (it != m.end()) {
        m.erase(it);
    }

    cout << "\nAfter erasing one 'tv':\n";
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    // erase all "tv" entries
    m.erase("tv");

    cout << "\nAfter erasing all 'tv':\n";
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "\nSize: " << m.size() << endl;
    cout << "Empty: " << (m.empty() ? "Yes" : "No") << endl;

    return 0;
}