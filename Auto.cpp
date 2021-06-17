#include "stdafx.h"
#include <memory.h>

template <typename datatype>
class Auto_rsh{
public:
	datatype * myDataType;
	Auto_rsh(datatype *ptr){
		cout << "Inside constructor"<<endl;
		myDataType = ptr;
	}
	~Auto_rsh()
	{
		cout << "Inside destructor"<<endl;
		if (!myDataType)
		{
			delete myDataType;
			cout << "memory deleted" << endl;
		}
	}
	Auto_rsh(Auto_rsh &copyMe){
		cout << "\nInside copy constructor";
		myDataType = copyMe.myDataType;
		copyMe.myDataType = NULL;
	}

	datatype* operator()()
	{

	}
	datatype* getValue(){
		return myDataType;
	}
};

