#include "../include/huffman.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    // example 1 
    {
        string text = "aaaaaaabbbccdeeeeffggggggggg";

        vector<char> symbols;
        vector<long long> freqs;

        for (int i = 0; i < (int)text.size(); i++) {
            char c = text[i];
            bool found = false;

            for (int j = 0; j < (int)symbols.size(); j++) {
                if (symbols[j] == c) {
                    freqs[j]++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                symbols.push_back(c);
                freqs.push_back(1);
            }
        }

        cout << "\nexample 1: \"" << text << "\"\n";

        // binary
        {
            Counters cnt;
            vector<char> out_symbols;
            vector<string> out_codes;

            build_binary_huffman_codes(symbols, freqs, out_symbols, out_codes, cnt);

            cout << "binary:\n";
            for (int i = 0; i < (int)out_symbols.size(); i++) {
                cout << out_symbols[i] << " -> " << out_codes[i] << "\n";
            }
            cout << "counters: " << cnt << "\n";
        }

        // ternary
        {
            Counters cnt;
            vector<char> out_symbols;
            vector<string> out_codes;

            build_ternary_huffman_codes(symbols, freqs, out_symbols, out_codes, cnt);

            cout << "ternary:\n";
            for (int i = 0; i < (int)out_symbols.size(); i++) {
                cout << out_symbols[i] << " -> " << out_codes[i] << "\n";
            }
            cout << "counters: " << cnt << "\n";
        }
    }

    // example 2
    {
        string text = "just some text to test this";

        vector<char> symbols;
        vector<long long> freqs;

        for (int i = 0; i < (int)text.size(); i++) {
            char c = text[i];
            bool found = false;

            for (int j = 0; j < (int)symbols.size(); j++) {
                if (symbols[j] == c) {
                    freqs[j]++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                symbols.push_back(c);
                freqs.push_back(1);
            }
        }

        cout << "\nexample 2: \"" << text << "\"\n";

        Counters cnt;
        vector<char> out_symbols;
        vector<string> out_codes;

        build_binary_huffman_codes(symbols, freqs, out_symbols, out_codes, cnt);

        for (int i = 0; i < (int)out_symbols.size(); i++) {
            cout << out_symbols[i] << " -> " << out_codes[i] << "\n";
        }
        cout << "counters: " << cnt << "\n";
    }

    return 0;
}
