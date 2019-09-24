class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // int ones = 0;
        // for (int i = bits.size() - 2; i >= 0 && bits[i] != 0; i--) {
        //     ones++;
        //     cout << "i = " << i << endl;
        // }
        // return (ones % 2 == 0);
        
        // int size = bits.size();
        // for (int i = 0; i < size; i++){
        //     if (bits[i] == 1) { 
        //         if (i + 1 != size - 1) {
        //             i++;                  
        //         }
        //         else {
        //             return false;
        //         };
        //     }
        //     else {
        //         if(i == size - 1) {
        //             return true;
        //         }
        //     }
        // }
        // return true;

        // bool flag = false;
        // for (int i = 0; i < bits.size();) {
        //     if (bits[i] == 1) flag = false, i += 2;
        //     else flag = true, ++i;
        // }
        // return flag;
        
        int bsize = bits.size() - 1;
        int i = 0;
        while(i < bsize){
            if(bits[i] == 0){
                ++ i;
            }
            else{
                i += 2;
            }
            
        }
        return (i == bsize)&&(bits[i] == 0);
    }
};

// Runtime: 4 ms, faster than 94.09% of C++ online submissions for 1-bit and 2-bit Characters.
// Memory Usage: 8.8 MB, less than 53.27% of C++ online submissions for 1-bit and 2-bit Characters.

/*
2: A'
3: B'+A
4: C'+A'B
5: D'+B'C+AC
6: E'+C'D+BDA'
7: F'+D'E+CEB'
8: G'+E'F+DFC'+BDFA'
*/
