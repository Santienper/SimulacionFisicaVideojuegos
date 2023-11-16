template<typename T = void>
class SpPtr {
public:
	SpPtr(const T& value) : offset(0) {
		ptr = new T*();
		*ptr = new T(value);
		references = new int(1);
		check = (long long int*)new void*(*ptr);
	}

	SpPtr(T* ptr = nullptr) : offset(0) {
		this->ptr = new T*();
		*(this->ptr) = ptr;
		references = new int(1);
		check = (long long int*)new void*(ptr);
	}

	SpPtr(const SpPtr<T>& other) : ptr(other.ptr), references(other.references), check(other.check), offset(other.offset) {
		(*references)++;
	}

	SpPtr<T>& operator=(SpPtr<T>& other) {
		this->~SpPtr();
		ptr = other.ptr;
		references = other.references;
		(*references)++;
		check = other.check;
		offset = other.offset;
		return *this;
	}

	~SpPtr() {
		if(!(--(*references))) {
			delete references;
			if(*ptr) delete *ptr;
			delete ptr;
			delete check;
		}
	}

	T& operator*() {
		checkPtr();
		return **ptr;
	}

	const T& operator*() const {
		checkPtr();
		return **ptr;
	}

	T* operator->() {
		checkPtr();
		return *ptr;
	}

	const T* operator->() const {
		checkPtr();
		return *ptr;
	}

	void free() {
		if(*ptr) {
			delete* ptr;
			*ptr = nullptr;
			if(*check != (long long int)ptr) {
				*((void**)check) = nullptr;
			}
		}
	}

	template<typename newT>
	SpPtr<newT> cast() {
		return SpPtr<>(*this).cast<newT>();
	}

	template<typename otherT>
	bool operator==(otherT* other) {
		return (void*)*ptr == (void*)other;
	}

	template<typename otherT>
	bool operator==(SpPtr<otherT> other) {
		return (void*)*ptr == (void*)(other.operator->());
	}

	bool operator==(std::nullptr_t) {
		return *ptr == nullptr;
	}
private:
	T** ptr;
	int* references;
	long long int* check;
	int offset;

	SpPtr(bool, bool) { }

	friend class SpPtr<>;

	void checkPtr() const {
		if((*ptr == nullptr && *check != (long long int)nullptr) && (*ptr != nullptr && *check != (long long int)ptr - offset))
			const_cast<SpPtr*>(this)->update();
	}

	void update() {
		if(*check == 0) *ptr = nullptr; // nullptr = 0
		else *ptr = (T*)(*check + offset);
	}
};

template<>
class SpPtr<void> {
public:
	SpPtr(void* ptr = nullptr) : offset(0) {
		this->ptr = new void*();
		*(this->ptr) = ptr;
		references = new int(1);
	}

	template<typename T>
	SpPtr(const SpPtr<T>& other) : references(other.references), offset(0) {
		ptr = (void**)other.check;
		(*references)++;

	}

	template<typename T>
	SpPtr& operator=(SpPtr<T>& other) {
		this->~SpPtr();
		ptr = (void**)other.check;
		references = other.references;
		(*references)++;
		offset = 0;
		return *this;
	}

	~SpPtr() {
		if(!(--(*references))) {
			delete references;
			if(*ptr) delete* ptr;
			delete ptr;
		}
	}

	void free() {
		if(*ptr) {
			delete* ptr;
			*ptr = nullptr;
		}
	}

	template<typename newT>
	SpPtr<newT> cast() {
		SpPtr<newT> aux(false, false);
		aux.ptr = new newT*();
		*aux.ptr = dynamic_cast<newT*>(*ptr);
		aux.references = references;
		(*references)++;
		aux.check = (long long int*)ptr;
		aux.offset = *aux.ptr - *ptr;
		return aux;
	}

	template<typename otherT>
	bool operator==(otherT* other) {
		return *ptr == (void*)other;
	}

	template<typename otherT>
	bool operator==(SpPtr<otherT> other) {
		return *ptr == (void*)*(other.ptr);
	}

	bool operator==(std::nullptr_t) {
		return *ptr == nullptr;
	}
private:
	void** ptr;
	int* references;
	int offset;
};