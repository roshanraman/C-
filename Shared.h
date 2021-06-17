#include "stdafx.h"

template <typename T>
class rsh_shared_ptr {
	int* ref_count;
	T* ptr = nullptr;
public:
	rsh_shared_ptr() : ref_count(new int(0)), ptr(nullptr) {
		cout << "Shared pointer default constructor" << endl;
	}

	rsh_shared_ptr(T* ptr) : ref_count(new int(1)), ptr(ptr) {
		cout << "Shared pointer constructor" << endl;
	}

	~rsh_shared_ptr() {
		cout << "Shared pointer destructor" << endl;
		(*ref_count)--;
		if (*ref_count == 0) {
			cout << "Shared pointer : ref count is 0" << endl;
			if (ptr) {
				cout << "Shared pointer : deleting memory" << endl;
				delete ptr;
			}
			delete ref_count;
		}
	}

	//Copy constructor
	rsh_shared_ptr(const rsh_shared_ptr& obj)
	{
		this->ref_count = obj.ref_count;
		this->ptr = obj.ptr;
		if (nullptr != obj.ptr) {
			(*this->ref_count)++;
		}
	}

	//Operator overloading
	T& operator=(const rsh_shared_ptr& obj)
	{
		delete this->ptr;
		if (nullptr != obj.ptr) {
			this->ref_count = obj.ref_count;
			this->ptr = obj.ptr;
			(*this->ref_count)++;
		}
		return *this;
	}

	int get_count() const
	{
		return *ref_count;
	}

	T* get() {
		return this->ptr;
	}

	T* operator->() {
		return this->ptr();
	}

	T& operator*() {
		return this->ptr;
	}
};
