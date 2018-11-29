/*
 * rope.cpp
 *
 *  Created on: 2018. nov. 28.
 *      Author: prajczer
 */
#include <iostream>
#include <vector>
using namespace std;

class Rope{
	struct Node {
		Node *parent;
		Node *left, *right;
		unsigned int weight;
		char* szoveg;
		bool is_leaf;
		Node(){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			szoveg = new char[3];
			is_leaf = false;
		}
		Node(string be){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			szoveg = new char[3];
			is_leaf = true;
			if (be.size > 3) {
				is_leaf = false;
				string eleje = be.substr(0,(be.length() / 2));
				string vege = be.substr((be.length() / 2), be.length());
				left = new Node(eleje, this);
				right = new Node(vege, this);
			} else {
				for (size_t i = 0; i< be.size(); i++){
					szoveg[i] = be[i];
					weight ++;
				}
			}

		}
		Node(string be, Node *szulo){
			parent = szulo;
			left = nullptr;
			right = nullptr;
			weight = 0;
			szoveg = new char[3];
			is_leaf = true;
			if (be.size > 3) {
				is_leaf = false;
				string eleje = be.substr(0,(be.length() / 2));
				string vege = be.substr((be.length() / 2), be.length());
				left = new Node(eleje, this);
				right = new Node(vege, this);
			} else {
				for (size_t i = 0; i< be.size(); i++){
					szoveg[i] = be[i];
					weight ++;
				}
			}
		}
		~Node();
	};
private:
	unsigned int len;
	Node *root;
public:
	Rope();
	Rope(Node *gyok);
	~Rope();
	void _delete(Node *kezdet);
	unsigned int length();
	char index(const unsigned int) const;
	static Rope concat (Rope& r1, Rope& r2);
	static std::pair<Rope, Rope> split (Rope&, const unsigned int);
	std::string report(unsigned int, unsigned int) const;
};

Rope::Rope(){
	len = 0;
	root = nullptr;
}

Rope::Rope(Node *gyok){
	len = 0;
	root = gyok;
}

Rope::~Rope(){
	Rope::_delete(root);
}

void Rope::_delete(Node *from){
	if (from != nullptr){
		_delete(from->left);
		_delete(from->right);
		delete from;
	}
}

unsigned int Rope::length(){
	return len;
}

char Rope::index(const unsigned int x) const{
	return 'x';
}



