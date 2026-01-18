#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<vector<string>>> recipes;
unordered_map<string, int> memo;

int min_cost(const string &potion) {
    if (memo.count(potion)) return memo[potion];

    if (!recipes.count(potion)) return memo[potion] = 0;
    
    int best = INT_MAX;
    for (auto &ingredients : recipes[potion]) {
        int cost = (int)ingredients.size() - 1; 
        for (auto &ing : ingredients) {
            cost += min_cost(ing);
        }
        best = min(best, cost);
    }
    return memo[potion] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string line;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        auto eq = line.find('=');
        string lhs = line.substr(0, eq);
        string rhs = line.substr(eq + 1);

        vector<string> ingredients;
        string token;
        stringstream ss(rhs);
        while (getline(ss, token, '+')) {
            ingredients.push_back(token);
        }
        recipes[lhs].push_back(ingredients);
    }

    string target;
    cin >> target;

    cout << min_cost(target) << "\n";
    return 0;
}