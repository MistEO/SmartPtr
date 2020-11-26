#pragma once

#include "RefPtr.hpp"

template<typename Type>
class SmartPtr
{
public:
	SmartPtr() = default;

	SmartPtr(Type * ptr)
		: rp(new RefPtr<Type>(ptr)) {
		;
	}

	SmartPtr(const SmartPtr<Type>& sp)
		: rp(sp.rp) {
		++rp->count;
	}

	SmartPtr(SmartPtr<Type>&& sp)
		: rp(sp.rp) {
		sp.rp = nullptr;
	}

	~SmartPtr()
	{
		if (--rp->count == 0) {
			delete rp;
		}
	}

	SmartPtr<Type>& operator=(const SmartPtr<Type>& rhs) {
		if (--rp->count == 0) {
			delete rp;
		}
		rp = rhs.rp;
		++rhs.rp->count;

		return *this;
	}

	SmartPtr<Type>& operator=(SmartPtr<Type>&& rhs) {
		if (--rp->count == 0) {
			delete rp;
		}
		rp = rhs.rp;
		rhs.rp = nullptr;

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

	RefPtr<Type> * rp = nullptr;
};


template<typename Type, typename... Ts>
SmartPtr<Type> MakeSmart(Ts && ...params)
{
	return SmartPtr<Type>(new Type(std::forward<Ts>(params)...));
}

template<typename Type>
SmartPtr<Type> MakeSmart(size_t num)
{
	return SmartPtr<Type>(new Type[num]);
}