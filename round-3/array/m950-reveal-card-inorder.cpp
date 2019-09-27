// ~75min, 1 submission, LOL I don't why I just wrap my head around for the first 50 min

/*

The problem gives an algorithm from output_deck to revealed_deck (following),
we need to find an algorithm from revealed_deck to output_deck
a b c d e f g

c d e f g b, a
e f g b d, a c
g b d f, a c e
d f b, a c e g
b f, a c e g d
f, a c e g d b

a c e g d b f      <=  known

The problem gives an algorithm from output_deck to revealed_deck,
we need to find an algorithm from revealed_deck to output_deck

// output, known
f, a c e g d b      // give known back to output head
    f, a c e g d b  // put output back to back head
b f, a c e g d      // give known back to output head
    f b, a c e g d  // put output back to back head
d f b, a c e g      // give known back to output head
    b d f, a c e g
g b d f, a c e
    f g b d, a c e
e f g b d, a c
    d e f g b, a c
c d e f g b, a
    b c d e f g, a
a b c d e f g
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 0) return {};
        sort(deck.begin(), deck.end());// deck now is known deck

        vector<int> output_deck;

        while (deck.size() > 0) {
            if (output_deck.size() > 0) {
                int temp = output_deck[output_deck.size()-1];
                output_deck.insert(output_deck.begin(), temp);
                output_deck.pop_back();
            }

            output_deck.insert(output_deck.begin(), deck[deck.size()-1]);
            deck.pop_back();
        }

        return output_deck;
    }
};

/*
Runtime: 20 ms, faster than 15.02% of C++ online submissions for Reveal Cards In Increasing Order.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Reveal Cards In Increasing Order.
*/
