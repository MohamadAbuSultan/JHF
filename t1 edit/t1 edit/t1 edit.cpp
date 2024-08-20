#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isCompleteDeck(map<char, map<int, int>>& cardMap) {
    for (const auto& suit : cardMap) {
        for (int i = 1; i <= 13; ++i) {
            if (suit.second.at(i) == 0) {
                return false;
            }
        }
    }
    return true;
}

int calculateCompleteDecks(vector<pair<int, char>> cardCounts) {
    map<char, map<int, int>> cardMap = {
        {'K', {}},
        {'H', {}},
        {'S', {}},
        {'D', {}}
    };

    for (auto& suit : cardMap) {
        for (int i = 1; i <= 13; ++i) {
            suit.second[i] = 0;
        }
    }

    for (const auto& card : cardCounts) {
        cardMap[card.second][card.first]++;
    }

    int completeDecks = 0;
    while (isCompleteDeck(cardMap)) {
        completeDecks++;
        for (auto& suit : cardMap) {
            for (int i = 1; i <= 13; ++i) {
                suit.second[i]--;
            }
        }
    }

    return completeDecks;
}

int main() {
    vector<pair<int, char>> cardCounts = {
        {1, 'K'}, {2, 'K'}, {3, 'K'}, {4, 'K'}, {5, 'K'}, {6, 'K'}, {7, 'K'}, {8, 'K'}, {9, 'K'}, {10, 'K'}, {11, 'K'}, {12, 'K'}, {13, 'K'},
        {1, 'H'}, {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'},
        {1, 'S'}, {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'},
        {1, 'D'}, {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'},
         {1, 'K'}, {2, 'K'}, {3, 'K'}, {4, 'K'}, {5, 'K'}, {6, 'K'}, {7, 'K'}, {8, 'K'}, {9, 'K'}, {10, 'K'}, {11, 'K'}, {12, 'K'}, {13, 'K'},
        {1, 'H'}, {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'},
        {1, 'S'}, {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'},
        {1, 'D'}, {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'},
         {1, 'K'}, {2, 'K'}, {3, 'K'}, {4, 'K'}, {5, 'K'}, {6, 'K'}, {7, 'K'}, {8, 'K'}, {9, 'K'}, {10, 'K'}, {11, 'K'}, {12, 'K'}, {13, 'K'},
        {1, 'H'}, {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'},
        {1, 'S'}, {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'},
        {1, 'D'}, {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'}
    };

    int completeDecks = calculateCompleteDecks(cardCounts);
    cout << "Number of complete decks: " << completeDecks << endl;

    return 0;
}
