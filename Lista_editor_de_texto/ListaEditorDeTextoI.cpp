#include <bits/stdc++.h>

using namespace std;

const string valido = "abcdefghijklmnopqrstuvwxyz-";

int main() {
  string entrada, saida = "|";

  cin >> entrada;

  int pos_cursor = 0;

  for (char comando : entrada) {
    if (valido.find(comando) != string::npos) {
      saida.insert(pos_cursor++, 1, comando);
    } else if (comando == 'R') {
      saida.insert(pos_cursor++, 1, '\n');
    } else if (comando == '<') {
      if (pos_cursor > 0) {
        swap(saida[pos_cursor], saida[pos_cursor-1]);
        --pos_cursor;
      }
    } else if (comando == '>') {
      if (pos_cursor < saida.size()-1) {
        swap(saida[pos_cursor], saida[pos_cursor+1]);
        ++pos_cursor;
      }
    } else if (comando == 'D') {
      if (pos_cursor < saida.size()-1) {
        saida.erase(pos_cursor+1, 1);
      }
    } else if (comando == 'B') {
      if (pos_cursor > 0) {
        saida.erase(pos_cursor-1, 1);
        --pos_cursor;
      }
    }
  }

  cout << saida << '\n';
}