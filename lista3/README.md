# AISD – Lista 3

Projekt zawiera implementacje + testy dla: **CUT_ROD**, **LCS**, **ACTIVITY_SELECTOR** oraz **Huffman**.  
Wyniki (liczba `cmp` i `assign`) są pokazane w sprawozdaniu i na wykresach.

## Kompilacja (Windows, g++)
Uwaga: każdy plik testowy ma własny `main()`, więc kompiluję je osobno.

```powershell
g++ -std=c++17 kody/src/generate.cpp -Ikody/include -o generate.exe
g++ -std=c++17 kody/src/cut_rod.cpp kody/tests/tests_cut_rod.cpp -Ikody/include -o cut_rod_tests.exe
g++ -std=c++17 kody/src/LCS.cpp kody/tests/tests_LCS.cpp -Ikody/include -o lcs_tests.exe
g++ -std=c++17 kody/src/activity_selector.cpp kody/tests/tests_activity_selector.cpp -Ikody/include -o activity_tests.exe
g++ -std=c++17 kody/src/huffman.cpp kody/tests/tests_huffman.cpp -Ikody/include -o huffman_tests.exe