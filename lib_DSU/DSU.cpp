#include "../lib_DSU/DSU.h"

DSU::DSU(size_t size) : _size(size) {
	_parent = new int[_size];
	_rank = new int[_size];
	for (int i = 0; i < _size; i++) {
		_parent[i] = i;
		_rank[i] = 0;
	}
}

DSU::~DSU() {
	delete[] _parent;
	delete[] _rank;
}

int DSU::find(int val) {
	if (_parent[val] == val)
		return val;
	else
		return _parent[val] = find(_parent[val]);
}

void DSU::unite(int val1, int val2) {
	if (val1 != val2) {
		int a = find(val1), b = find(val2);
		if (_rank[a] < _rank[b])
			_parent[a] = b;
		else {
			if (_rank[a] == _rank[b])
				_rank[a]++;
			_parent[b] = a;
		}
	}
}

int DSU::count() {
	std::unordered_set<int> Set(_parent, _parent + _size);
	return Set.size();
}