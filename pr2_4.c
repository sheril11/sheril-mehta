#include <bits/stdc++.h>
using namespace std;

struct Transition {
    int next_state;
    char input_symbol;
};

int main() {
    int num_symbols, num_states, initial_state, num_accepting_states;
    vector<char> symbols;
    vector<int> accepting_states;
    unordered_map<int, vector<Transition>> transitions;

    cout << "Enter the number of input symbols: ";
    cin >> num_symbols;
    cout << "Enter the input symbols: ";
    for (int i = 0; i < num_symbols; i++) {
        char symbol;
        cin >> symbol;
        symbols.push_back(symbol);
    }

    cout << "Enter the number of states: ";
    cin >> num_states;
    cout << "Enter the initial state: ";
    cin >> initial_state;

    cout << "Enter the number of accepting states: ";
    cin >> num_accepting_states;
    cout << "Enter the accepting states: ";
    for (int i = 0; i < num_accepting_states; i++) {
        int state;
        cin >> state;
        accepting_states.push_back(state);
    }

    cout << "Enter transitions (state input_symbol->next_state):\n";
    for (int i = 0; i < num_states * num_symbols; i++) {
        int state, next_state;
        char input_symbol;
        cin >> state >> input_symbol >> next_state;
        transitions[state].push_back({next_state, input_symbol});
    }

    string input_string;
    cout << "Enter the input string: ";
    cin >> input_string;

    if (input_string.empty()) {
        cout << "String rejected!\n";
        return 0;
    }

    char start_symbol = input_string.front();

    if (!isalpha(start_symbol)) {
        cout << "String rejected!\n";
        return 0;
    }


    for (char c : input_string) {
        if (!isalnum(c)) {
            cout << "String rejected!\n";
            return 0;
        }
    }

    int current_state = initial_state;
    bool valid = true;

    for (char c : input_string) {
        bool found = false;
        for (auto &trans : transitions[current_state]) {
            if (trans.input_symbol == c) {
                current_state = trans.next_state;
                found = true;
                break;
            }
        }
        if (!found) {
            valid = false;
            break;
        }
    }

    if (valid && find(accepting_states.begin(), accepting_states.end(), current_state) != accepting_states.end()) {
        cout << "String accepted!\n";
    } else {
        cout << "String rejected!\n";
    }

    return 0;
}
