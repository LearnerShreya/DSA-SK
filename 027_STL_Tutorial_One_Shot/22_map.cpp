#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    // inserting elements
    m["tv"] = 100;
    m["laptop"] = 100;
    m["headphones"] = 50;
    m["tablet"] = 120;
    m["watch"] = 50;

    // insert() and emplace()
    m.insert({"camera", 25});
    m.emplace("speaker", 80);

    // adding using subscript operator []
    m["phone"] = 70;

    cout << "All items in map:\n";
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }



    // print value using key
    cout << "Value of laptop: " << m["laptop"] << endl;



    
    // size()
    cout << "\nSize of map: " << m.size() << endl;

    // count()
    cout << "Count of key 'tablet': " << m.count("tablet") << endl;
    cout << "Count of key 'mic': " << m.count("mic") << endl;

    // find()
    auto it = m.find("laptop");
    if (it != m.end())
        cout << "Found: " << it->first << " -> " << it->second << endl;
    else
        cout << "Key not found\n";

    // erase()
    m.erase("watch");
    cout << "\nAfter erasing 'watch':\n";
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    // empty()
    if (m.empty())
        cout << "\nMap is empty\n";
    else
        cout << "\nMap is not empty\n";

    return 0;
}