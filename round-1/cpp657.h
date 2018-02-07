class Solution {
public:
    bool judgeCircle(string moves) {
        int numL, numR, numD, numU;
        numL = numR = numD = numU = 0;
        for (int i = 0; i < moves.size(); ++i) {
            if (moves[i] == 'L')
                numL++;
            else if (moves[i] == 'R')
                numR++;
            else if (moves[i] == 'U')
                numD++;
            else
                numU++;
        }
        
        if ((numL != numR) || (numD != numU))
            return false;
        else
            return true;
    }
};
