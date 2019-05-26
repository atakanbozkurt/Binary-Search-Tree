#include <iostream>
#include "map.h"

using namespace std;

void copyConstructorTester( Map mapObject);
//input: object type of Map
//output: none
//side effects: adds elements to the mapObject
//		deletes elements from the mapObject
//		prints the contents of the mapObject to stdout

int main(){
	Map myMapp;
	myMapp.displayAll();
	cout << "Adding elements to map" << endl;
	ElementType element1 = make_pair( 20,new string("$20") );
	myMapp.add(element1);
	ElementType element2 = make_pair( 30,new string("$30") );
	myMapp.add(element2);
	ElementType element3 = make_pair( 40,new string("$40") );
	myMapp.add(element3);
	ElementType element4 = make_pair( 35,new string("$35") );
	myMapp.add(element4);
	ElementType element5 = make_pair( 33,new string("$33") );
	myMapp.add(element5);
	ElementType element6 = make_pair( 38,new string("$38") );
	myMapp.add(element6);
	ElementType element7 = make_pair( 10,new string("$10") );
	myMapp.add(element7);
	ElementType element8 = make_pair( 5,new string("$5") );
	myMapp.add(element8);
	ElementType element9 = make_pair( 8,new string("$8") );
	myMapp.add(element9);
	ElementType element10 = make_pair( 7,new string("$7") );
	myMapp.add(element10);
	ElementType element11 = make_pair( 9,new string("$9") );
	myMapp.add(element11);
	myMapp.displayAll();

	cout << "Removing left child(Key:10) having only left child " << endl;
	myMapp.remove(10);
	myMapp.displayAll();

	cout << "Removing left child(Key:5) having only right child " << endl;
	myMapp.remove(5);
	myMapp.displayAll();

	cout << "Removing right child(Key:30) having only right child " << endl;
	myMapp.remove(30);
	myMapp.displayAll();

	cout << "Removing right child(Key:40) having only left child " << endl;
	myMapp.remove(40);
	myMapp.displayAll();

	cout << "Removing left child(Key:8) having 2 children" << endl;
	myMapp.remove(8);
	myMapp.displayAll();

	cout << "Removing right child(Key:35) having 2 children" << endl;
	myMapp.remove(35);
	myMapp.displayAll();

	cout << "Removing right child(Key:35) having 2 children" << endl;
	myMapp.remove(35);
	myMapp.displayAll();

	cout << "Removing node(Key:20) having 2 children" << endl;
	myMapp.remove(20);
	myMapp.displayAll();

	cout << "Adding Key:35..." << endl;
	ElementType element12 = make_pair( 35 ,new string("$35") );
	myMapp.add(element12);
	myMapp.displayAll();

	cout << "Removing left leaf(Key:7) of left children" << endl;
	myMapp.remove(7);
	myMapp.displayAll();

	cout << "Removing left leaf(Key:35) of right children" << endl;
	myMapp.remove(35);
	myMapp.displayAll();

	cout << "Adding Key:15 and Key:40" << endl;
	ElementType element13 = make_pair( 15 ,new string("$15") );
	myMapp.add(element13);
	ElementType element14 = make_pair( 40 ,new string("$40") );
	myMapp.add(element14);
	myMapp.displayAll();

	cout << "Removing right leaf(Key:15) of left children" << endl;
	myMapp.remove(15);
	myMapp.displayAll();

	cout << "Removing right leaf(Key:40) of right children" << endl;
	myMapp.remove(40);
	myMapp.displayAll();

	cout << "Retrieving Key:9 to change its value from $9 to $99" << endl;
	ValueType adressKey9 = myMapp.retrieve(9);
	*adressKey9 = "$99";
	cout << "Value changed" << endl;
	myMapp.displayAll();

	copyConstructorTester(myMapp);
	cout << "Function Ended, Now Map Contents Are:" << endl;
	myMapp.displayAll();

	cout << "Creating a newMap" << endl;
	Map newMap;
	cout << "Adding elements to the newMap" << endl;
	ElementType element15 = make_pair( 5,new string("$5") );
	newMap.add(element15);
	ElementType element16 = make_pair( 10,new string("$10") );
	newMap.add(element16);
	ElementType element17 = make_pair( 4,new string("$4") );
	newMap.add(element17);
	newMap.displayAll();

	cout << "Now checking the functionality of the copy assignment operator(newMap=myMapp)" << endl;
	newMap = myMapp;
	newMap.displayAll();

	cout << "Now adding key Key:9 which was already in the Map with the new value $-1." << endl;
	ElementType element18 = make_pair( 9,new string("$-1") );
	newMap.add(element18);
	newMap.displayAll();

	cout << "Is the myMapp empty? : ";
	if( myMapp.empty() == true ){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	cout << "Size of the myMapp is: " << myMapp.getSize() << endl;
	cout << "Is Key:33 in the myMapp? : ";
	if( myMapp.find(33) == true ){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	cout << "Is Key:158 in the myMapp? : ";
	if( myMapp.find(158) == true ){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}

void copyConstructorTester( Map mapObject){
	cout << "Entered Function, Now Testing Copy Constructor" <<endl;
	mapObject.displayAll();

	cout << "Adding Key:2 to mapObject" << endl;
	ElementType element1 = make_pair( 2,new string("$2") );
	mapObject.add(element1);
	mapObject.displayAll();
	
	cout << "Adding Key:15 to mapObject" << endl;
	ElementType element2 = make_pair( 15,new string("$15") );
	mapObject.add(element2);
	mapObject.displayAll();	

	cout << "Removing Key:9 " << endl;
	mapObject.remove(9);
	mapObject.displayAll();

	cout << "Removing Key:15 " << endl;
	mapObject.remove(15);
	mapObject.displayAll();

}
