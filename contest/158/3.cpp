// DALAO's
// i don't understand the problem
const int MOD = 1e9 + 7;
const int SIDES = 6;
const int MAX_ROLLS = 15;
const int STATES = SIDES * MAX_ROLLS;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<long long> dp(STATES, 0);

        for (int side = 0; side < SIDES; side++)
            dp[side] = 1;

        for (int i = 0; i < n - 1; i++) {
            vector<long long> next_dp(STATES, 0);

            for (int state = 0; state < STATES; state++) {
                int rolls = state / SIDES + 1;
                int side = state % SIDES;

                for (int die = 0; die < 6; die++) {
                    int new_rolls = side == die ? rolls + 1 : 1;

                    if (new_rolls > rollMax[die])
                        continue;

                    next_dp[(new_rolls - 1) * SIDES + die] += dp[state];
                }
            }

            for (int s = 0; s < STATES; s++)
                next_dp[s] %= MOD;

            dp = next_dp;
        }

        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    }
};