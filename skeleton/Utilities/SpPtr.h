#pragma once

template<typename T = void>
class SpPtr {
public:
	SpPtr(const T& value) {
		pointer = new T*();
		*pointer = new T(value);
		references = new int(1);
	}

	SpPtr(T* ptr = nullptr) {
		pointer = new T*();
		*pointer = ptr;
		references = new int(1);
	}

	SpPtr(const SpPtr<T>& other) : pointer(other.pointer), references(other.references) {
		(*references)++;
	}

	SpPtr<T>& operator=(SpPtr<T>& other) {
		this->~SpPtr();
		pointer = other.pointer;
		references = other.references;
		(*references)++;
		return *this;
	}

	~SpPtr() {
		if(!(--(*references))) {
			delete references;
			if(*pointer) delete *pointer;
			delete pointer;
		}
	}

	T& operator*() {
		return **pointer;
	}

	const T& operator*() const {
		return **pointer;
	}

	T* operator->() {
		return *pointer;
	}

	const T* operator->() const {
		return *pointer;
	}

	void free() {
		if(*pointer) delete *pointer;
		*pointer = nullptr;
	}

	template<typename newT>
	SpPtr<newT> cast() {
		return SpPtr<>(*this).cast<newT>();
	}

	template<typename otherT>
	bool operator==(otherT* other) {
		return *pointer == other;
	}

	template<typename otherT>
	bool operator==(SpPtr<otherT> other) {
		return pointer == other.pointer;
	}

	bool operator==(std::nullptr_t) {
		return *pointer == nullptr;
	}
private:
	T** pointer;
	int* references;

	SpPtr(bool, bool) { }

	friend class SpPtr<>;
};

template<>
class SpPtr<void> {
public:
	SpPtr(void* ptr = nullptr) {
		pointer = new void*();
		*pointer = ptr;
		references = new int(1);
	}

	template<typename T>
	SpPtr(SpPtr<T>& other) {
		pointer = reinterpret_cast<void**>(other.pointer);
		references = other.references;
		(*references)++;
	}

	template<typename T>
	SpPtr& operator=(SpPtr<T>& other) {
		this->~SpPtr();
		pointer = reinterpret_cast<void**>(other.pointer);
		references = other.references;
		(*references)++;
		return *this;
	}

	~SpPtr() {
		if(!(--(*references))) {
			delete references;
			if(*pointer) delete* pointer;
			delete pointer;
		}
	}

	void free() {
		if(*pointer) delete *pointer;
		*pointer = nullptr;
	}

	template<typename newT>
	SpPtr<newT> cast() {
		SpPtr<newT> aux(false, false);
		aux.pointer = reinterpret_cast<newT**>(pointer);
		aux.references = references;
		(*references)++;
		return aux;
	}

	template<typename otherT>
	bool operator==(otherT* other) {
		return *pointer == other;
	}

	template<typename otherT>
	bool operator==(SpPtr<otherT> other) {
		return pointer == other.pointer;
	}

	bool operator==(std::nullptr_t) {
		return *pointer == nullptr;
	}
private:
	void** pointer;
	int* references;
};