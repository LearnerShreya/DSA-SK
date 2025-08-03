#include <iostream>
using namespace std;

int main() {
    // Use short when value is small, e.g., age (saves memory)
    short age = 25;
    cout << "Age (short): " << age << endl;

    // Use long for larger numbers like population or file sizes
    long population = 1000000L;
    cout << "Population (long): " << population << endl;

    // Use long long for very large numbers like scientific data
    long long starsInGalaxy = 9223372036854775807LL;
    cout << "Stars in Galaxy (long long): " << starsInGalaxy << endl;

    // Use signed when values can be both positive and negative, e.g., temperature
    signed int temperature = -15;
    cout << "Temperature (signed int): " << temperature << "°C" << endl;

    // Use unsigned when values are always positive, e.g., count or ID
    unsigned int studentCount = 150;
    cout << "Student Count (unsigned int): " << studentCount << endl;

    return 0;
}



// Age (short): 25
// Population (long): 1000000
// Stars in Galaxy (long long): 9223372036854775807
// Temperature (signed int): -15°C
// Student Count (unsigned int): 150