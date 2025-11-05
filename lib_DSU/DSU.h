#ifndef LIB_DSU_DSU_H_
#define LIB_DSU_DSU_H_

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
};
#endif // !LIB_DSU_DSU_H_
