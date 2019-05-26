//map.h
#ifndef map_
#define map_
#include "mapInterface.h"
using namespace std;

class Map : MapInterface{
public:
	Map();
	~Map();
	Map(const Map & mapToCopy);

	//interface methods

	bool empty() const;
	//input: none
	//output: returns true if the Map is empty; else false
	//side effects: none

	int getSize() const;
	//input: none
	//output: returns the number of elements in the Map
	//side effects: none

	bool add(ElementType element);
	//input: an element (key and its associated value)
	//output: returns true if the key-value pair was 	
	//        added; else false(the key was found)
	//side effects: Map has one more element (if addition 
       //              done)

	bool find(KeyType key) const;
	//input: a key
	//output: return true is an element with this key was 
	//        found; else false
	//side effects: none

	ValueType retrieve(KeyType key) const;
	//input: a key
	//output: returns the value associated with key (a 
	//        null pointer if the key was not found)
	//side effects: none

	bool remove(KeyType key);
	//input: a key
	//output: returns true if item is removed;
	//        else false (key not found)
	//side effects: Map has one less element (if remove 
	//              done)

	void displayAll() const;
	//input: none
	//output: none
	//side effects: write contents of the Map in ascending order of key to cout with calling displayHelper() method
	//		prints the height of the BST with calling height();


	Map& operator=(const Map & mapToCopy);
	//input: object of type Map
	//output: returns the Map variable which is on the left side when assignment done
	//side effects: copies right side map variable to left side map variable
	//	     if left side map variable has contents, deletes the previous info

	int height() const;
	//input: none
	//output: returns the height of the binary tree
	
private:
	class Node{
		public:
		ElementType data;
		Node* left;
		Node* right;
	};
	Node* root;
	int size;

	//recursive helper methods

	void displayHelper(Node* tmpNode) const;
	//input: Node pointer
	//output: none
	//side effects: traverse tree by inorder and writes the content into the cout

	void destructorHelper(Node* tmpNode);
	//input: take a Node pointer as input, in this case root to help deleting nodes
	//output: none
	//side effects: traverse tree by postorder and deletes all the nodes recursively

	void copyConstructorHelper(Node* tmpNode);
	//input: Node pointer
	//output: none
	//side effects: traverse tree by preorder and makes a deep copy of
	//		binary search tree

	int heightHelper(Node* tmpNode) const;
	//input: Node pointer
	//output: returns the height of the left and right subtrees recursively
};
#endif


