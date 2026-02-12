#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H
#include<iostream>
#include "../lib_TVector/TVector.h"

template<typename TKay, typename TValue>
class TTable {
	virtual void insert(const TKay& kay, const TValue& val) = 0;
	virtual void finde(const TKay& kay) = 0;
	virtual void erase(const TKay& kay) = 0;
	virtual std::ostream& print(std::ostream& out) const noexcept = 0;
	virtual bool is_empty() const noexcept = 0;
	virtual bool consist(const TKay& kay) const noexcept = 0;
};

#endif // TABLE_TABLE_H