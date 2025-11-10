#include "../lib_island/island.h"


int counting_islands(int _row, int _col, const int* mas) {
	DSU A(_row * _col +1);
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			int val = i * _col + j;

			if (mas[val] == 0) 
				A.unite(val, _row * _col);
			
			else {

				if (j > 0 && mas[val - 1] != 0) {
					A.unite(val, val - 1);
				}

				if (i > 0 && mas[val - _col] != 0) {
					A.unite(val, val - _col);
				}
			}
		}
	}
	return A.count() - 1;
}
