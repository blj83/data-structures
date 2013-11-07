#include "list1.h"
#include "node.h"

#include <iostream>


#ifndef LIST1_H
#define LIST1_H

#include <new>
#include "node.h"

template <class T> class DLL
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
		Node <T> *header;
		int length;
};

#include "list1.cc"
#endif


#ifndef NODE_H
#define NODE_H

template <class T> class Node
{
  friend class DLL <T>;

  public:

    Node(const T &v): prev(NULL), value(v), next(NULL) { }
   ~Node() { }

  private:
    Node <T> *prev;
    Node <T> *next;
    T value;
};

#endif

DLL::DLL(){
	header = NULL;
	tail = NULL;
	length = 0;
}

int DLL::IsEmpty() const{
	if (length == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int DLL::Length() const{
	return length;
}

void DLL::Push_front(const T &X){
	Node *newNode;
	newNode = new Node(X);
	if (IsEmpty()){
		this->header = newNode;
		this->tail = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;	
	}
	else {
		newNode->prev = NULL
		newNode->next = head;
		this->header = newNode;
	}
	length++;
}

void DLL::Push_back(const T &X){
	Node *newNode;
	newNode = new Node(X);
	if (IsEmpty()){
		this->header = newNode;
		this->tail = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
	}
	else{
		newNode->prev = tail;
		newNode->next = NULL;
		this->tail = newNode;
	}
	length++;
}

void DLL::Pop_front(){
	this->head = this->head->next;
	length--;	
}

void DLL::Pop_back(){
	this->tail = this->tail->prev;
	length--;
}

const T DLL::Front() const{
	return head->value;
}

const T DLL::Back() const{
	return tail->value;
}

void DLL::Print() const{
	Node *current;
	current = this->head;
	while (current != NULL){
		cout << current->value << " ";
		current = current->next;
	}
}

void DLL::PrintBack() const{
	Node *current;
	current = this->tail;
	while(current != NULL){
		cout << current->value << " ";
		current = current->prev;
	}
}

void DLL::Iterate(void (*)(T &)){

}

void DLL::Reverse(){
	//prev is = to the next 
	//next is = to prev
}
