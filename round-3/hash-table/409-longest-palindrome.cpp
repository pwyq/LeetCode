#include <unordered_map>
#include <iostream>
#include <cassert>
using namespace std;

// Runtime: 4 ms, faster than 83.03% of C++ online submissions for Longest Palindrome.
// Memory Usage: 8.8 MB, less than 93.33% of C++ online submissions for Longest Palindrome. 

class Solution {
public:
    int longestPalindrome(string s) {
        cout << "----------------------------------\n";
        unordered_map<char, int> m;   // change to unordered_map later; map is used for easier debugging
        for (char c : s)
            m[c]++;

        int sum = 0;
        int single = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second % 2 == 0)
                sum += it->second;
            else {
                sum += (it->second-1);
                if (single == 0) single = 1;
            }
            cout << it->first << " : " << it->second;
            cout << "\tsum = " << sum << endl; 
        }
        return sum + single;
    }
};

int main() {
    string s1 = "abccccdd";
    int r1 = Solution().longestPalindrome(s1);
    assert(r1 == 7);


    string s2 = "ccccca";
    int r2 = Solution().longestPalindrome(s2);
    assert(r2 == 5);

    string s3 = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    int r3 = Solution().longestPalindrome(s3);
    assert(r3 == 983);

    string s4 = "abccccddbbbbaa";
    int r4 = Solution().longestPalindrome(s4);
    assert(r4 == 13);
    return 0;
}
