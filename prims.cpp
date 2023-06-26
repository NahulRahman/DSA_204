

#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999


#define V 6

int G[V][V] = { { 0, 4, 4, 0, 0,0 },
						{ 4, 0, 2, 0, 0,0 },
						{ 4, 2, 0, 3, 2,4 },
						{ 0, 0, 3, 0, 0,3 },
						{ 0, 0, 2, 0, 0,3 },
						{0,0,4,3,3,0}};

int main() {
  int no_edge;

  int selected[V];

  memset(selected, false, sizeof(selected)); // for loop

  no_edge = 0;

  selected[0] = true;

  int x;
  int y;

  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
