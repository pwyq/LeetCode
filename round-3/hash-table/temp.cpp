#include <iostream>
#include <vector>
using namespace std;

int main() {
    int zz = 'Z' - 'a';
    int aa = 'A' - 'a';
    cout << aa << ", " << zz << endl;

    int x = 'a' - 'a';
    int y = 'z' - 'a';
    cout << x << ", " << y << endl;

    cout << char(-32+'a') << endl;
    cout << char(-7+'a') << endl;
    return 0;
}
