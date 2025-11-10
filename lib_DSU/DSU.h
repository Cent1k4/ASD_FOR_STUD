#ifndef LIB_DSU_DSU_H_
#define LIB_DSU_DSU_H_

#include <unordered_set>
class DSU

{
	size_t _size;
	int* _parent;
	int* _rank;

public:
	DSU(size_t size = 1);
	~DSU();
	void unite(int, int);
	int find(int);
	int count();
};
#endif // !LIB_DSU_DSU_H_
