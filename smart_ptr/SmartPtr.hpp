#pragma once

#include "RefPtr.hpp"


template<typename Type>
class SmartPtr
{
public:
	SmartPtr() { ; }

	SmartPtr(Type * ptr)
		: rp(new RefPtr<Type>(ptr)) {
		;
	}

	SmartPtr(const SmartPtr<Type>& sp)
		: rp(sp.rp) {
		++rp->count;
	}

	~SmartPtr()
	{
		if (--rp->count == 0) {
			delete rp;
		}
	}

	SmartPtr<Type>& operator=(const SmartPtr<Type>& rhs) {
		++rhs.rp->count;
		if (--rp->count == 0) {
			delete rp;
		}
		rp = rhs.rp;

		return *this;
	}
	Type& operator*() const {
		return *(rp->p);
	}
	Type* operator->() const {
		return rp->p;
	}

	Type* get() const {
		return rp->p;
	}

private:

	RefPtr<Type> * rp;
};
