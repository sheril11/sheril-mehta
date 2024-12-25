#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int n_symbols;
    cout << "Enter the number of Symbols:";
    cin >> n_symbols;
    char symbols[n_symbols];
    cout << "Enter the Symbols:";
    for (int i = 0; i < n_symbols; i++){
        cin >> symbols[i];
    }
    int n_states,initial_state,final_state;
    cout << "Enter the number of states:";
    cin >> n_states;
    int states[n_states];
    for (int i = 0; i < n_states; i++){
        states[i] = i+1;
    }
    cout << "Initial State:";
    cin >> initial_state;
    cout << "Final State:";
    cin >> final_state;

    cout << "Transition table (state to symbol -> states)" << endl;
    int table[n_states][n_symbols];
    for (int i = 0; i < n_states; i++){
        for (int j = 0; j < n_symbols; j++){
            cout << states[i] << " to " << symbols[j] << "->";
            cin >> table[i][j];
        }
    }

    string s;
    cout << "Enter the string:";
    cin >> s;

    int currState = initial_state;
    bool isInvalid = false;
    for (int i = 0; i < s.length(); i++){
        int EleIndex;
        for(int j = 0; j < n_symbols; j++){
            cout << symbols[j] << s[i] << endl;
             if(symbols[j] == s[i]){
                EleIndex = j;
                isInvalid=false;
                break;
            }
            else{
                isInvalid = true;
            }
        }
        if(isInvalid) break;
        currState = table[currState-1][EleIndex];
        cout << currState << "  " << EleIndex << endl;
    }
    if(currState==final_state){
        cout << "String is Valid!";
    }
    else{
        cout << " String invalid!";
    }


    return 0;
}
