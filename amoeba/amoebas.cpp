#include <iostream>
#include "amoebas.h"

using namespace std;

Amoeba::Amoeba (string s) {	// an amoeba is born, named s
	myName = s;
	myParent = 0;
	myOlderSibling = 0;
	myOldestChild = 0;
	myYoungestChild = 0;
}

// Access functions
string Amoeba::Name () {
	return myName;
}

Amoeba* Amoeba::Parent () {
	return myParent;
}

void Amoeba::AddChild (Amoeba* newChild) {
	// make child point to parent
	newChild->myParent = this;

	// check for parent having other children
	Amoeba* otherSibling = myYoungestChild;
	if (!otherSibling) {	// the new amoeba is an only child
		myYoungestChild = newChild;	// make the parent's child
		myOldestChild = newChild;		// ptrs point to the new one
		newChild->myOlderSibling = 0;	// no older sibling
	} else {	// there are other kids; make this one the youngest
		myYoungestChild = newChild;	// no younger siblings,
		newChild->myOlderSibling = otherSibling;	// but new kid now
	}					// has older siblings.
}

void Amoeba::PrintChildren(){
    cout << "Here are my children: " << endl;
    Amoeba* child = myYoungestChild;
    while (child){
        cout << "Hello, I'm " << child->Name() << endl;
        child = child->myOlderSibling;
    }
}

void Amoeba::PrintGrandChildren(){
    cout << "Here are my grandChildren: " <<endl;
    Amoeba* child = myYoungestChild;
    while (child){
        child->PrintChildren();
        child = child->myOlderSibling;
    }
}

void Amoeba::PrintDescendants(string indent){
    cout << indent << this->Name() << endl;
    Amoeba* child = myYoungestChild;
    while(child){
        child->PrintDescendants(indent + "    ");
        child = child->myOlderSibling;
    }
}





