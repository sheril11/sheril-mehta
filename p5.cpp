#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_set>

using namespace std;


unordered_set<string> keywords = {"int", "char", "return", "void", "float", "struct"};
unordered_set<char> operators = {'+', '-', '*', '/', '=', ';', '{', '}', '(', ')'};


bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}


bool isOperator(char ch) {
    return operators.find(ch) != operators.end();
}


void tokenize(const string &code) {
    vector<string> tokens;
    string token;
    for (size_t i = 0; i < code.length(); ++i) {
        char ch = code[i];

        if (isspace(ch)) {
            continue;
        }

        if (isalpha(ch)) { 
            token += ch;
            while (isalnum(code[i + 1])) {
                token += code[++i];
            }
            if (isKeyword(token)) {
                cout << "Keyword: " << token << endl;
            } else {
                cout << "Identifier: " << token << endl;
            }
            token.clear();
        } else if (isdigit(ch)) {
            token += ch;
            while (isdigit(code[i + 1])) {
                token += code[++i];
            }
            cout << "Constant: " << token << endl;
            token.clear();
        } else if (isOperator(ch)) {
            cout << "Operator: " << ch << endl;
        } else if (ch == '\'') { 
            token += ch;
            token += code[++i]; 
            token += code[++i]; 
            cout << "String: " << token << endl;
            token.clear();
        } else if (ch == '"') { 
            token += ch;
            while (code[++i] != '"') {
                token += code[i];
            }
            token += '"';
            cout << "String: " << token << endl;
            token.clear();
        } else {
            cout << "Punctuation: " << ch << endl;
        }
    }
}

int main() {
    string code = R"(int main() {
    int a = 5;
    char b = 'x';
    return a + b;
})";

    tokenize(code);

    return 0;
}
