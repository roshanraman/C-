#include "stdafx.h"

template <typename T>
class rsh_unique_ptr {
	T* ptr;

	//Copy constructor
	rsh_unique_ptr(const rsh_unique_ptr& obj) = delete;
	T& operator=(const rsh_unique_ptr& obj) = delete;

public:
	rsh_unique_ptr() :ptr(nullptr) {
		cout << "Unique pointer default constructor" << endl;
	}

	rsh_unique_ptr(T* ptr) : ptr(ptr) {
		cout << "Unique pointer constructor" << endl;
	}

	~rsh_unique_ptr() {
		cout << "Unique pointer destructor" << endl;
		if (nullptr != ptr) {
			cout << "Deleting memory of unique pointer" << endl;
			delete ptr;
		}
	}

	//Move constructor
	rsh_unique_ptr(rsh_unique_ptr&& dyingObj) {
		cout << "Uniqur pointer move constructor" << endl;
		this->ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr;
	}

	//Move assignment
	void operator= (rsh_unique_ptr && dyingObj){
		cout << "Uniqur pointer move assignment" << endl;
		this->ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr;
	}
};