Kompilacja testów
W katalogu kody/:
bash:
g++ -std=c++17 *.cpp -o testy.exe
Uruchamianie:
./testy.exe

Generowanie danych do wykresów
Kompilacja z flagą GENERATE_DATA:
bash:
g++ -std=c++17 -DGENERATE_DATA *.cpp -o generate_data.exe
Uruchamianie:
./generate_data.exe

Tworzenie wykresów
W katalogu sprawozdanie/:
python plots.py