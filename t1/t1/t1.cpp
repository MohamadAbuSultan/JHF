#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateCompleteDecks(vector<pair<int, char>> cardCounts) {
    int minDecks = INT_MAX;
    for (int i = 0; i < cardCounts.size(); i++) {
        int decks = cardCounts[i].first / 12;
        if (decks < minDecks) {
            minDecks = decks;
        }
    }
    return minDecks;
}

int calculateCompleteDecksWithoutPair(int countK, int countH, int countS, int countD) {
    int decksK = countK / 12;
    int decksH = countH / 12;
    int decksS = countS / 12;
    int decksD = countD / 12;

    int minDecks = min(min(decksK, decksH), min(decksS, decksD));
    return minDecks;
}

int main() {
    vector<pair<int, char>> cardCounts = {
        {96, 'K'},
        {96, 'H'},
        {96, 'S'},
        {96, 'D'}
    };

    int completeDecks = calculateCompleteDecks(cardCounts);
    cout << completeDecks << endl;

    int countK = 48;
    int countH = 48;
    int countS = 48;
    int countD = 48;

    int completeDecksWithoutPair = calculateCompleteDecksWithoutPair(countK, countH, countS, countD);
    cout << completeDecksWithoutPair << endl;

    return 0;
}
