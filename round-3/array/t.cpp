#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0)
            cout << i/2 << " ";
        else
            cout << (i-1)/2 << " ";
    }
    return 0;
}
