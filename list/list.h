#ifndef LIST1_H
#define LIST1_H

#include <new>
#include "node.h"

template <typename T> 
class DLL
{
 	friend class Node <T>;
	
	public:
		DLL();
		~DLL();
		int IsEmpty() const;
		int Length() const;
		void Push_front(const T &);
		void Push_back(const T &);
		void Pop_front();
		void Pop_back();
		const T Front() const;
		const T Back() const;
		void Print() const;
		void PrintBack() const;
		void Iterate(void (*)(T &));
		void Reverse();
		
	private:
		Node <T> *head;
		Node <T> *tail;
		int length;
};

//#include "list1.cc"
#endif
