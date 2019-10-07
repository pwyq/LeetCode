#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
string largestTimeFromDigits(vector<int>& A) {
  sort(begin(A), end(A), greater<int>());
  for (int i : A)
      cout << i << " ";
  cout << endl;
  do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6) 
      cout << to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]) << endl;
  while (prev_permutation(begin(A), end(A)));
  return "";
}

int main() {
    vector<int> a = {1,2,3,4};
    largestTimeFromDigits(a);
    vector<int> b = {0,9,3,4};
    largestTimeFromDigits(b);
    vector<int> c = {0,0,3,4};
    largestTimeFromDigits(c);
    return 0;
}
