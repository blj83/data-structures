#include "list.h"
#include "node.h"

#include <iostream>
using namespace std;

/*
 * The Constructor for the DLL class
 */

template <typename T>
DLL<T>::DLL(){
	head = NULL;
	tail = NULL;
	length = 0;
}

/*
 * The deconstructor for the DLL class
 */

template <typename T>
DLL<T>::~DLL(){
	while(head){
		Node<T> *current;
		current = this->head;
		this->head = this->head->next;
		delete current;
	}	
}

/*
 * Checks the length and returns 1 if the length 
 * is 0 and 0 if not.
 */

template <typename T>
int DLL<T>::IsEmpty() const{
	if (length == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*
 * Returns the length
 */

template <typename T>
int DLL<T>::Length() const{
	return length;
}

/*
 * Pushes a node on the front of the list with the value indicated
 * by the valus X. Does the appropriate handling if the list is 
 * empty. Also increments the length.
 */

template <typename T>
void DLL<T>::Push_front(const T &X){
	Node<T> *newNode;
	newNode = new Node<T>(X);
	if (IsEmpty()){
		this->head = newNode;
		this->tail = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;	
	}
	else {
		this->head->prev = newNode;
		newNode->prev = NULL;
		newNode->next = this->head;
		this->head = newNode;
	}
	length++;
}

/*
 * Pushes a node on the back of the list with the value indicated
 * by X. Does the appropriate handling if the list is empty. 
 * Increments length.
 */

template <typename T>
void DLL<T>::Push_back(const T &X){
	Node<T> *newNode;
	newNode = new Node<T>(X);
	if (IsEmpty()){
		this->head = newNode;
		this->tail = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
	}
	else{
		this->tail->next = newNode;
		newNode->prev = this->tail;
		newNode->next = NULL;
		this->tail = newNode;
	}
	length++;
}

/*
 * Removes an item off the front. Has the appropriate handling
 * if it is the last item.
 */

template <typename T>
void DLL<T>::Pop_front(){
	if (this->head == this->tail){
		this->head = NULL;
		this->tail = NULL;
	}
	else{
		this->head = this->head->next;
		this->head->prev = NULL;
	}
	length--;	
}

/*
 * Removes the node off the back. Has the appropriate handling if it
 * is the last node.
 */

template <typename T>
void DLL<T>::Pop_back(){
	if(this->tail == this->head){
		this->tail = NULL;
		this->head = NULL;
	}
	else{
		this->tail = this->tail->prev;
		this->tail->next = NULL;
	}
	length--;
}

/*
 * Returns the value of the rirst node
 */

template <typename T>
const T DLL<T>::Front() const{
	return head->value;
}

/*
 * Returns the value of the last node
 */

template <typename T>
const T DLL<T>::Back() const{
	return tail->value;
}

/*
 * Iterates throught the list and prints the value from
 * the front to the back.
 */

template <typename T>
void DLL<T>::Print() const{
	Node<T> *current;
	current = this->head;
	while (current != NULL){
		cout << current->value << " ";
		current = current->next;
	}
}

/*
 * Iterates through the list backwards from the tail and
 * prints the value of the list from back to front.
 */

template <typename T>
void DLL<T>::PrintBack() const{
	Node<T> *current;
	current = this->tail;
	while(current != NULL){
		cout << current->value <<  " ";
		current = current->prev;
	}
}

/*
 * Points to a function and applies the function to the value
 * of all the items in the list.
 */

template <typename T>
void DLL<T>::Iterate(void (*p)(T &)){
	Node<T> *current;
	current = this->head;
	while(current != NULL){
		p(current->value);
		current = current->next;
	}
}

/*
 * Reverses the list by switching the next and prev pointers
 * of each node.
 */

template <typename T>
void DLL<T>::Reverse(){

	Node<T> *current;
	Node<T> *temp;
	
	temp = NULL;
	current = this->head;

	while (current != NULL){
		temp = current->prev;
       		current->prev = current->next;
       		current->next = temp;
       		current = current->prev;
	}
	current = this->tail;
	this->tail = this->head;
	this->head = current;
}

