//map.cpp
#include "map.h"
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

Map::Map(){
	cout << "Constructor called" << endl;
	size = 0;
	root = nullptr;
}

Map::~Map(){
	cout << "Destructor called" << endl;
	destructorHelper(root);
}

void Map::destructorHelper(Node* tmpNode){
	if(tmpNode==nullptr){
		return;
	}
	destructorHelper(tmpNode->left);
	destructorHelper(tmpNode->right);
	delete (tmpNode->data).second;
	delete tmpNode;
	size--;
}


Map::Map(const Map & mapToCopy){
	cout << "Copy Constructor called" << endl;
	//initialize an empty BST
	size = 0;
	root = nullptr;

	Node* tmpNode = mapToCopy.root;
	copyConstructorHelper(tmpNode);	
}

void Map::copyConstructorHelper(Node* tmpNode){
	if(tmpNode == nullptr){
		return;
	}
	ElementType deepCopy = make_pair((tmpNode->data).first,new string(*((tmpNode->data).second)));
	add(deepCopy);
	copyConstructorHelper(tmpNode->left);
	copyConstructorHelper(tmpNode->right);
}

bool Map::empty() const{
	if(size==0){
		return true;
	}
	else{
		return false;
	}
}

int Map::getSize() const{
	return size;
}

bool Map::find(KeyType key) const{
	Node* tmpNode = root;
	while( tmpNode != nullptr ){
		if( key == (tmpNode->data).first){
			return true;
		}
		else{
			if(key < (tmpNode->data).first){
				tmpNode = tmpNode->left;
			}
			else{ //key > (tmpNode->data).first
				tmpNode = tmpNode->right;
			}
		}
	}
	return false;
}

bool Map::add(ElementType element){
	if(root == nullptr){
		Node* newNode = new Node;
		root = newNode;
		root->data = element;
		root->left = nullptr;
		root->right = nullptr;
		size++;
		return true;
	}
	else{ //root != nullptr
		if( find(element.first) ){
			delete element.second;
			return false; //cannot add item if Map has an element with the same key
		}
		else{
			Node* curNode = root;
			Node* newNode = new Node;
			newNode->data = element;
			newNode->left = nullptr;
			newNode->right = nullptr;
			while(curNode != nullptr){
				if((newNode->data).first < (curNode->data).first){
					if(curNode->left == nullptr){
						curNode->left = newNode;
						size++;
						return true;					
					}
					else{
						curNode = curNode->left;	//step down 1 layer
					}
				}
				else{ //(newNode->data).first > (curNode->data).first
					if(curNode->right == nullptr){
						curNode->right = newNode;
						size++;
						return true;
					}
					else{
						curNode = curNode->right;	//step down 1 layer
					}
				}
			}
		}
	}
	return true;
}

ValueType Map::retrieve(KeyType key) const{
		Node* curNode = root;
		while(curNode!=nullptr){
			if((curNode->data).first == key){
				return (curNode->data).second;
			}
			if(key < (curNode->data).first){
				curNode = curNode->left;
			}
			else{
				curNode = curNode->right;
			}
		}
		return nullptr; //nothing to retrieve
}

bool Map::remove(KeyType key){
	assert(size>0);
	Node* parent = nullptr;
	Node* curNode = root;
	while(curNode != nullptr){
		//node found

		if(key == (curNode->data).first){	//NODE FOUND

			if( (curNode->left == nullptr) && (curNode->right == nullptr) ){ //delete
											 //leaf
				if(parent==nullptr){ 	//curNode is root
					delete (curNode->data).second;
					delete curNode;
					root = nullptr;
					size--;
					return true;
				}
				else if(parent->left == curNode){		//delete left leaf
					delete (curNode->data).second;
					delete curNode;
					parent->left = nullptr;
					size--;
					return true;
				}
				else{						//delete right leaf
					delete (curNode->data).second;
					delete curNode;
					parent->right = nullptr;
					size--;
					return true;
				}
			}
			
			else if( (curNode->left != nullptr) && (curNode->right == nullptr) ){
								//delete Node w/ single left child
				if(parent==nullptr){	// curNode is root
					root = curNode->left;
					delete (curNode->data).second;
					delete curNode;
					size--;
					return true;
				}
				else if(parent->left == curNode){ //if it is parent's left child
					parent->left = curNode->left;
					delete (curNode->data).second;
					delete curNode;
					size--;
					return true;
				}
				else{				 //if it is parent's right child
					parent->right = curNode->left;
					delete (curNode->data).second;
					delete curNode;
					size--;
					return true;
				}
			}

			else if( (curNode->left == nullptr) && (curNode->right != nullptr) ){
								//delete Node w/ single right child
				if(parent==nullptr){	// curNode is root
					root = curNode->right;
					delete (curNode->data).second;
					delete curNode;
					size--;
					return true;
				}
				else if(parent->left == curNode){ //if it is parent's left child
					parent->left = curNode->right;
					delete (curNode->data).second;
					delete curNode;
					size--;
					return true;
				}
				else{				 //if it is parent's right child
					parent->right = curNode->right;
					delete (curNode->data).second;
					delete curNode;
					size--;
					return true;
				}
			}

			else{					 //delete node with 2 children
				Node* sucNode = curNode->right;
				Node* sucParent = curNode;
				while(sucNode->left != nullptr){
					sucParent = sucNode;
					sucNode = sucNode->left;
				}
				//copying sucNode information to curNode
				(curNode->data).first = (sucNode->data).first;
				*((curNode->data).second) = *((sucNode->data).second);

				if(sucParent->right == sucNode){
					sucParent->right = nullptr;
					delete (sucNode->data).second;
					delete sucNode;
					size--;
					return true;
				}
				if(sucParent->left == sucNode){	
					sucParent->left = nullptr;
					delete (sucNode->data).second;
					delete sucNode;
					size--;
					return true;
				}				
			}
		}

		else if(key < (curNode->data).first){				//SEARCH LEFT
			parent = curNode;
			curNode = curNode->left;
		}
		else{								//SEARCH RIGHT
			parent = curNode;
			curNode = curNode->right;
		}
	}
	return false;	//KEY NOT FOUND
}

void Map::displayAll() const{
	if(root==nullptr){
		cout << "No elements available" << endl;
		return;
	}
	Node* tmpNode = root;
	displayHelper(tmpNode);
	cout << "Height : " << height() << endl;
	return;
}

void Map::displayHelper(Node* tmpNode) const{
	if(tmpNode == nullptr){
		return;
	}
	displayHelper(tmpNode->left);
	cout << "Key: " << (tmpNode->data).first << " | Value : " << *((tmpNode->data).second) << endl;
	displayHelper(tmpNode->right);	
}

Map& Map::operator=( const Map & mapToCopy){
	cout << "Copy assignment operator called" << endl;
	if(getSize() > 0){	//information inside the map, first delete them all
		Node* rootCopy = root;
		root = nullptr;
		destructorHelper(rootCopy);
	}

	//now copy from mapToCopy
	Node* tmpNode = mapToCopy.root;
	copyConstructorHelper(tmpNode);
	return *this;


}

int Map::height() const{
	Node* tmpNode = root;
	int height;
	height = heightHelper(tmpNode);
	return height;
}

int Map::heightHelper(Node* tmpNode) const{
	if(tmpNode==nullptr){
		return 0;
	}
	else{
		int leftHeight = heightHelper(tmpNode->left);
		int rightHeight = heightHelper(tmpNode->right);
		if(leftHeight>rightHeight){
			return leftHeight+1;
		}
		else{
			return rightHeight+1;
		}
	}

}
