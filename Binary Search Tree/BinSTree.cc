#include "stack1.h"
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class BinSTree;

//header file for the TrrNode class
template <class T>
class TreeNode
{
   private:
        TreeNode *left;
        TreeNode *right;
   public:
        T data;
        TreeNode(const T& item,TreeNode<T> *lptr=NULL,TreeNode<T> *rptr=NULL);
        TreeNode<T> *Left()const;
        TreeNode<T> *Right()const;
        friend class BinSTree<T>;
};

//constructor which allows left or right or both to be Null
template <class T>
TreeNode<T>::TreeNode(const T& item,TreeNode<T> *lptr,TreeNode<T> *rptr)
            :data(item),left(lptr),right(rptr)
{}

//returns the left
template <class T>
TreeNode<T>* TreeNode<T>::Left() const
{
      return left;
}

//returns the right
template <class T>
TreeNode<T>* TreeNode<T>::Right() const
{
      return right;
}



//header file for the BinSTree class
template <class T>
class BinSTree{
	public:
		BinSTree(void);
		BinSTree(const BinSTree<T>& tree);
		~BinSTree(void);
		BinSTree<T>& operator= (const BinSTree<T>& rhs);
        void IndentBlanks(int level);
        void PrintTree(TreeNode<T> *t, int level);
		void PrintVTree(TreeNode<T> *t, int dataWidth, int screenWidth);
		void CountLeaf(TreeNode<T> *t, int &count);
		int Depth(TreeNode<T> *t);
		int Find(const T& item);
		void Insert(const T& item);
		void Delete(const T& item);
		void ClearTree(void);
		int TreeEmpty(void) const;
		int TreeSize(void) const;
		void Update(const T& item);
		TreeNode<T> *GetRoot(void) const;
        void visit(T item);
        void InOrderVisit(TreeNode<T> *t, void (*f)(T &item));
        void PreOrderVisit(TreeNode<T> *t, void (*f)(T &item));
        void PostOrderVisit(TreeNode<T> *t, void (*f)(T &item));
        void LevelScan(TreeNode<T> *t, void (*f)(T &item));
        TreeNode<T>* BuildExpTree(char* exp);

	protected:
		TreeNode<T> *root;
		TreeNode<T> *current;
		int size;
		TreeNode<T> *GetTreeNode(T item, TreeNode<T> *lptr = NULL, TreeNode<T> *rptr = NULL);
		void FreeTreeNode(TreeNode<T> *t);
		TreeNode<T> *CopyTree(TreeNode<T> *t);
		void DeleteTree (TreeNode<T> *t);
		TreeNode<T> *FindNode(const T& item, TreeNode<T>* &parent)const;		
};

//Default BinSTree constructor. Initializes everything to o or NULL
template <class T>
BinSTree<T>::BinSTree(void):root(NULL),current(NULL),size(0)
{}          


//Copy constructor which copies the tree from the root passed as a parameter
template <class T>
BinSTree<T>::BinSTree(const BinSTree<T> &tree){
    root=CopyTree(tree.GetRoot());
    current=tree.current;
    size=tree.size;
}

//default deconstructor
template <class T>
BinSTree<T>::~BinSTree(){
	DeleteTree(root);	
}

//overload assignment operator function
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs){
	if(this==&rhs){
        	return *this;
      	}
	root=CopyTree(rhs.root);
      	current=root;
      	size=rhs.size;
      	return *this;
}

/*
  This method instatiates a TreeNode and assigns the proper left and right 
  pointers  
 */

template <class T>
TreeNode<T>* BinSTree<T>::GetTreeNode(T item, TreeNode<T> *lptr,TreeNode<T> *rptr){
	TreeNode<T> *p;

	p = new TreeNode<T>(item, lptr, rptr);
	if (p == NULL){
		 cout << "Memory allocation failure!"<<endl;
		 exit(1);
	}
	return p;
}	

/*
 *This method deletes the specified TreeNode
 */

template <class T>
void BinSTree<T>::FreeTreeNode(TreeNode<T> *t){
	delete(t);
}

/*
 * This method takes the parameter of a TreeNode and copies the tree to 
 * a new node which is the new root and is returned by the function
 */

template <class T>
TreeNode<T>* BinSTree<T>::CopyTree(TreeNode<T> *t){
	TreeNode<T> *leftptr, *rightptr, *newNode;
	if (t == NULL){
		return NULL;
	}
	if (t->left != NULL){
		leftptr = CopyTree(t->left);
	}
	else{
		leftptr = NULL;
	}
	if (t->right != NULL){
		rightptr = CopyTree(t->right); 
	}
	else{
		rightptr = NULL;
	}


	newNode = GetTreeNode(t->data, leftptr, rightptr);
	return newNode;
}

/*
 * This is a recursive fuction that calls itself to delet all the tree nodes from the 
*given point 
 */

template <class T>
void BinSTree<T>::DeleteTree (TreeNode<T> *t){
	if (t != NULL){
		DeleteTree(t->left);
		DeleteTree(t->right);
		FreeTreeNode(t);
	}
}

/*
 * This function will search for a value down the tree if that value if 
 * found it will return that node and a pointer to the parent node.
 */

template <class T>
TreeNode<T>* BinSTree<T>::FindNode(const T& item, TreeNode<T>* &parent) const{
	TreeNode<T> *p = root;
	parent = NULL;

	while (p != NULL && (p->data != item)){
		parent = p;
		if (p->data > item){
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return p;
}

/*
 * Used in print tree. It will increment the given number of blanks.
 */

template <class T>
void BinSTree<T>::IndentBlanks(int level){
    int i;
    for (i = 0; i < level; i++){
        cout<<" ";
    }
}

/*
 * Goes through the tree and prints the tree with the root at the left side of
 * the screen.
 */

template <class T>
void BinSTree<T>::PrintTree(TreeNode<T> *t, int level){
	if (t != NULL){
		PrintTree(t->right, level + 1);
        if (level != 0){
            IndentBlanks(3*(level-1));
        }
		cout<<t->data<<endl;
		PrintTree(t->left, level +1);
	}
}

/*
 * It will go through the tree and print a verticle representation of the tree.
 */

template <class T>
void BinSTree<T>::PrintVTree(TreeNode<T> *t, int dataWidth, int screenWidth){
	
	queue<TreeNode<T>*> q, real;
	TreeNode<T> *p, *n, *m;
	q.push(t);
    int maxLevel = (Depth(t)-1);
    int total = maxLevel + 1;
    total = (pow(2,total)-1);
	//Uses 2 queues to creat a queue with the infor
	//in the correct order.
	for(int k = 0; k <= total; k++){
        p = q.front();
		q.pop();
		real.push(p);
		if (p->left != NULL){
			q.push(p->left);
		}else{
            m = GetTreeNode(0,NULL,NULL);
            q.push(m);
        }
        if (p->right != NULL){
			q.push(p->right);
		}else{
            m = GetTreeNode(0,NULL,NULL);
            q.push(m);
        }
	}
	
    int num = ((pow(2, maxLevel))* dataWidth);
	if (((pow(2, maxLevel))* dataWidth) > screenWidth){
		cout<<"tree too big"<<endl;
		exit(1);
	}
	for (int i = 0; i <= maxLevel; i++){
		for(int j = 0; j < (pow(2, i)); j++){
            		IndentBlanks((screenWidth/((pow(2,i))+1)));
			n = real.front();
			real.pop();
			if (n->data == 0){
				cout<<" ";
			}else{
				cout<<n->data;
			}
		}
        cout<<endl;
	}
}

/*
 * A recursive method that will call itself to return the correct number of 
 leaves in the tree.
 */

template <class T>
void BinSTree<T>::CountLeaf(TreeNode<T> *t, int &count){
	if(t != NULL){
        CountLeaf(t->left, count);
        CountLeaf(t->right, count);
        if(t->left == NULL && t->right == NULL){
            count++;
        }
    }	
}

/*
 * It will go through the tree and count the depth from the root and return the correct value
 */

template <class T>
int BinSTree<T>::Depth(TreeNode<T> *t){
	if (!t)
		return 0;
	int left_height = Depth(t->left);
	int right_height = Depth(t->right);
	return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

/*
 * Boolean function that returns 1 if the item is in the tree and 0 if not
 */

template <class T>
int BinSTree<T>::Find(const T& item){
	TreeNode<T> *parent;
	current = FindNode(item, parent);

	if (current != NULL){
        return 1;
	}
	else{
		return 0;
	}
}

/*
 * This Function will go through and find the correct place to insert the 
   value on the given tree. If the item is the same then it will not insert
 */

template <class T>
void BinSTree<T>::Insert(const T& item){
	TreeNode<T> *t, *parent, *newNode;
    int val = Find(item);
    if (val){
        return;
    }
    

	t =root;
	parent = NULL;
	while (t != NULL){
		parent = t;
		if (t->data > item){
			t = t->left;
		}
		else {
			t = t->right;
		}
	}

	newNode =GetTreeNode(item, NULL, NULL);

	if(parent == NULL){
		root = newNode;
	}
	else if(parent->data > item){
		parent->left = newNode;
	}
	else{
		parent->right = newNode;
	}
	current = newNode;
	size++;
}

/*
 * This function considers all the possible nodes that could be deleted
  and accounts for each situation. TreeNode pointers are made to keep track of the 
    the replacement node and its left and right pointers. The replacement node is 
  then put in for the deleted node and the tree is rebalanced.
 */

template <class T>
void BinSTree<T>::Delete(const T& item){
	TreeNode<T> *DNodePtr, *PNodePtr, *RNodePtr;
	if ((DNodePtr = FindNode(item, PNodePtr)) == NULL){
		return;
	}
	if (DNodePtr->right == NULL){
		RNodePtr = DNodePtr->left;
	}
	else if(DNodePtr->left == NULL){
		RNodePtr = DNodePtr->right;
	}
	else{
		TreeNode<T> *PofRNodePtr = DNodePtr;
		RNodePtr = DNodePtr->left;

		while(RNodePtr->right != NULL){
			PofRNodePtr = RNodePtr;
			RNodePtr = RNodePtr->right;
		}
		
		if (PofRNodePtr == DNodePtr){
			RNodePtr->right = DNodePtr->right;
		}
        else{
            PofRNodePtr->right = RNodePtr->left;
            RNodePtr->left = DNodePtr->left;
            RNodePtr->right = DNodePtr->right;
        }
    }
    if (PNodePtr == NULL){
        root = RNodePtr;
    }
    else if (PNodePtr->data > DNodePtr->data){
        PNodePtr->left = RNodePtr;
    }
    else{
        PNodePtr->right = RNodePtr;
    }
    FreeTreeNode(DNodePtr);
    size--;
	
}

/*
 * deletes the tree from the current node
 */

template <class T>
void BinSTree<T>::ClearTree(){
	DeleteTree(current);
}

/*
 * boolean function that return 1 if it is empty and 0 if not
 */

template <class T>
int BinSTree<T>::TreeEmpty() const{
	return (this->root == NULL);
}

/*
 * returns the size
 */

template <class T>
int BinSTree<T>::TreeSize() const{
	return size;
}

/*
 * Check to see if value is in the tree if it is then it will do nothing
  if not then it will insert
 */

template <class T>
void BinSTree<T>::Update(const T& item){
	if (current->data == item){
		current->data = item;
	}
	else{
		Insert(item);
	}
}

/*
 * Returns the root of the tree.
 */

template <class T>
TreeNode<T>* BinSTree<T>::GetRoot() const{
	return root;
}

//function called by traversals that will print out the data of the node
template <class T>
void visit(T item){
    cout<<item<<" ";
    cout<<endl;
}

//visits the tree from left to right
template <class T>
void BinSTree<T>::InOrderVisit(TreeNode<T> *t, void (*f)(T &item))
{   
     if(t!=NULL)
     {
          InOrderVisit(t->left, f);
          f(t->data);
          InOrderVisit(t->right,f);
     } 
    
}

//visits from the root down
template <class T>
void BinSTree<T>::PreOrderVisit(TreeNode<T> *t, void (*f)(T &item))
{
     if(t!=NULL)
     {
         f(t->data);
         PreOrderVisit(t->left, f);
         PreOrderVisit(t->right, f);
     }
}

//visits from the bottom to the top
template <class T>
void BinSTree<T>::PostOrderVisit(TreeNode<T> *t, void (*f)(T &item))
{
     if(t!=NULL)
     {
         PostOrderVisit(t->left, f);
         PostOrderVisit(t->right, f);
         f(t->data);
        
     }
}

//visits in order by level
template <class T>
void BinSTree<T>::LevelScan(TreeNode<T> *t, void (*f)(T &item)){
	queue<TreeNode<T>*> q;
    TreeNode<T> *p;
    q.push(t);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        f(p->data);
        if(p->left!=NULL)
            q.push(p->left);
        if(p->Right()!=NULL)
            q.push(p->right);
    }
}


int isOperand(char c){
	if ( ((c >= 'a') && (c <= 'z'))  || ((c >= 'A') && (c <= 'Z')) ){
		return true;
	}
	else{
		return false;
	}	
}

template <class T>
TreeNode<T>* BinSTree<T>::BuildExpTree(char *exp){
   	
	char op1, op2;
   	TreeNode<char> *lc, *rc, *op;
   	Stack<char> s1;
   	Stack<TreeNode<T> *> s2;
   	int count = 0;
	
  	while (exp[count] != '\0'){
        s1.Push(exp[count]);
        count++;
        
   	}
     
    //s1.Pop();
    
  	while (!(s1.Empty())) {
		if (isOperand(s1.Peek(0))){
            s2.Push(GetTreeNode(s1.Pop()));
    }else{
			s2.Push(GetTreeNode(s1.Pop(),s2.Pop(),s2.Pop()));
		}
  	}
    
 	return s2.Pop(); 
}

void PrintInfixExpr(TreeNode<char> *t){
	if (isOperand(t->data))
		cout << t->data ;
	else{
		cout << "(";
		PrintInfixExpr(t->Left());
		cout << t->data;
		PrintInfixExpr(t->Right());
		cout << ")";
	}
}

void PrintChar(char& item){
	cout << item << " ";
}



int main(int argc, char *argv[]){
    BinSTree<char> expTree;
    TreeNode<char> *t;
    char *expression; 
    expression = argv[1];
    
    
    cout<<"input "<<expression<<endl;
                    
    cout<<"Build expression tree"<<endl;
    t = expTree.BuildExpTree(expression);
    
    cout<<"sideways representation"<<endl;
    expTree.PrintTree(t, 5);
    
    cout<<"Vertical Representation"<<endl;
    expTree.PrintVTree(t, 1, 30);
    cout << endl << endl << endl;
    
    //Infix display
	cout << "The Infix representation: " << endl;
	PrintInfixExpr(t);
	cout << endl << endl << endl;
    
	//Postfix display
	cout << "The Postfix representation: " << endl;
	expTree.PostOrderVisit(t, PrintChar);
	cout << endl << endl << endl;
    
}
