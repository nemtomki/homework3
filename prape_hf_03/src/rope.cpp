/*
 * rope.cpp
 *
 *  Created on: 2018. nov. 28.
 *      Author: prajczer
 */
#ifndef ROPE_CPP_
#define ROPE_CPP_

#include <iostream>
#include <vector>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <cstring>
#include "exception.cpp"
using namespace std;
const int global_char_size = 3;

class Rope{
	struct Node {
		Node *parent;
		Node *left, *right;
		unsigned int weight;
		char szoveg[global_char_size];
		bool is_leaf;
		Node(){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			is_leaf = false;
		}
		Node(string be){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			is_leaf = false;
			if (be.length() > global_char_size) {
				string eleje = be.substr(0,(be.length() / 2));
				string vege = be.substr((be.length() / 2), be.length());
				weight = eleje.length();
				left = new Node(eleje, this);
				right = new Node(vege, this);
			} else {
				is_leaf = true;
				weight = be.length();
				for (size_t i = 0; i< be.length(); i++){
					szoveg[i] = be[i];
				}
			}
		}
		Node(string be, Node *szulo){
			parent = szulo;
			left = nullptr;
			right = nullptr;
			weight = 0;
			is_leaf = false;
			if (be.length() > global_char_size) {
				string eleje = be.substr(0,(be.length() / 2));
				string vege = be.substr((be.length() / 2), be.length());
				weight = eleje.length();
				left = new Node(eleje, this);
				right = new Node(vege, this);
			} else {
				is_leaf = true;
				for (size_t i = 0; i< be.length(); i++){
					szoveg[i] = be[i];
					//std::cout << szoveg[i];

				}
				weight = be.size();
				//std::cout << std::endl;
			}
		}
	};
private:
	unsigned int len;
	Node *root;
public:
	//Rope();
	//Rope(Node *gyok);
	//Rope(string input);
	//~Rope();
	//void _delete(Node *kezdet);
	//unsigned int length();

	//char index(const unsigned int) const;
	//static Rope concat (Rope& r1, Rope& r2);
	//static std::pair<Rope, Rope> split (Rope&, const unsigned int);
	Rope(){
		len = 0;
		root = nullptr;
	}

	Rope(Node *gyok){
		len = 0;
		root = gyok;
		updateLength(root, len);

	}
	Rope(string input){
		len = input.length();
		root = new Node(input);
	}
	~Rope(){
		len = 0;
		Rope::_delete(root);
	}
	Rope&  operator =(Rope & r){
		if (&r != this){
			len = 0;
			delete root;
			std::string teljese = r.report(0, r.length());
			root = new Node(teljese);
			len = teljese.length();
		}
		return *this;
	}
	/*Rope operator&(Rope & r){
			if (&r != this){
				len = 0;
				delete root;
				std::string teljese = r.report(0, r.length());
				root = new Node(teljese);
				len = teljese.length();
			}
			return *this;
		}*/
	void updateLength(Node *x, unsigned int hossz){
		if (x != nullptr){
			hossz += x->weight;
			updateLength(x->right, hossz);
		}
	}
	void _delete(Node *from){
		if (from != nullptr){
			_delete(from->left);
			_delete(from->right);
			delete from;
		}
	}

	unsigned int length() const{
		return len;
	}

	char index(const unsigned int x){
		if (x < len && x >= 0){
			return kereso(root, x);
		} else {
			return ' ';
		}
	}
	//elejen hasznaltam csak a printet, most mar nem kell
	std::ostream& _print(Node *i, std::ostream& o){
		char* str = i->szoveg;
		for (size_t i = 0; i < global_char_size; i++){
			if (0 != isprint(str[i]) && str[i] != '\n'){
			o << str[i];
			}
		}
		if (i->left != nullptr) {
			_print(i->left, o);
		}
		if (i->right != nullptr) {
			_print(i->right, o);
		}
		return o;
	}
	char kereso(Node *i, unsigned int hely) const {
		if (i->weight <= hely){
			return kereso (i->right, hely - i->weight);
		}
		if (i->left != nullptr){
			return kereso(i->left, hely);
		}
		return i->szoveg[hely];
	}
	std::string report(unsigned int ettol, unsigned int eddig){
		std::string returned;
		for (unsigned int i = ettol; i<eddig; i++){
			returned += index(i);
		}
	return returned;
	}

	static Rope concat (Rope& r1, Rope& r2) {
		std::string eleje = r1.report(0, r1.length());
		std::string vege = r2.report(0, r2.length());
		Node* bal = new Node(eleje);
		Node* jobb = new Node(vege);
		r1.~Rope();
		r2.~Rope();
		Node* uj_root = new Node();
		uj_root->weight = eleje.length();
		uj_root->left = bal;
		uj_root->right = jobb;
		uj_root->right->parent  = uj_root->left->parent = uj_root;
		Rope* uj_rope = new Rope(uj_root);
		uj_rope->len = eleje.length() + vege.length();
		return *uj_rope;
	}

	static std::pair<Rope, Rope> split (Rope& rope, const unsigned int inx) {
		std::pair<Rope, Rope> eredmeny;
		std::string *eleje = new std::string(rope.report(0, inx));
		std::string *vege = new std::string(rope.report(inx, rope.length()));
		Rope* first = new Rope(*eleje);
		Rope* second = new Rope(*vege);
		eredmeny.first = *first;
		eredmeny.second = *second;
		rope.~Rope();
		return eredmeny;
	}
	bool empty(){
		if (root == nullptr){
			return true;
		} else {
			return false;
		}
	}
};

#endif /* ROPE_CPP_ */

