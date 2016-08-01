template<typename Type>
class SmartPtr;

template<typename Type>
class RefPtr
{
private:
	friend class SmartPtr<Type>;

	RefPtr(Type* ptr)
		: p(ptr), count(1) {
		;
	}
	~RefPtr() {
		delete p;
	}

	Type * p = nullptr;
	int count;
};
