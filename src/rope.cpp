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

class Rope{
	struct Node {
		Node *parent;
		Node *left, *right;
		unsigned int weight;
		char szoveg[4] = {'\n','\n','\n','\0'};

		bool is_leaf;
		Node(){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			is_leaf = true;
		}
		Node(string be){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			is_leaf = true;
			if (be.length() > 3) {
				is_leaf = false;
				string eleje = be.substr(0,(be.length() / 2));
				string vege = be.substr((be.length() / 2), be.length());
				left = new Node(eleje, this);
				weight += left->weight;
				right = new Node(vege, this);
			} else {
				for (size_t i = 0; i< be.size(); i++){
					szoveg[i] = be[i];
					std::cout << be[i];
					weight ++;
				}
				std::cout << std::endl;
			}

		}
		Node(string be, Node *szulo){
			parent = szulo;
			left = nullptr;
			right = nullptr;
			weight = 0;
			is_leaf = true;
			if (be.length() > 3) {
				is_leaf = false;
				string eleje = be.substr(0,(be.length() / 2));
				string vege = be.substr((be.length() / 2), be.length());
				left = new Node(eleje, this);
				right = new Node(vege, this);
			} else {
				for (size_t i = 0; i< be.size(); i++){
					szoveg[i] = be[i];
					//std::cout << szoveg[i];
					weight ++;
				}
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
	}
	Rope(string input){
		len = input.length();
		root = new Node(input);
		std::cout << "The rope: " << std::endl;
		_print(root, std::cout);
		std::cout << std::endl;
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
	Rope operator&(Rope & r){
			if (&r != this){
				len = 0;
				delete root;
				std::string teljese = r.report(0, r.length());
				root = new Node(teljese);
				len = teljese.length();
			}
			return *this;
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

	char index(const unsigned int x) const{
		char returning;
		int* hol = new int(x);
		int kezdet = 0;
		if (x <= len && x >= 0){
			kereso(root, kezdet, hol, returning);
			return returning;
		} else {
			throw OutOfIndexException();
			return ' ';
		}
	}
	std::ostream& _print(Node *i, std::ostream& o){
		char* str = i->szoveg;
		for (size_t i = 0; i < 3; i++){
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

	char kereso(Node *i, int& akt_hely, int* hely, char &returned) const{
		char* str = i->szoveg;
		for (size_t i =0; i < 3; i++){
			if (0 != isprint(str[i]) && str[i] != '\n'){
				if (*hely == akt_hely){
					returned = str[i];
				}
				akt_hely ++;
			}
		}
		if (i->left != nullptr) {
			kereso(i->left, akt_hely, hely, returned);
		}
		if (i->right != nullptr) {
			kereso(i->right, akt_hely, hely, returned);
		}
		return returned;
	}
	std::string report(unsigned int ettol, unsigned int eddig){
		std::string returned;
		if (ettol <= 0 || ettol >= len || eddig <= 0 || eddig >= len ){
			//throw OutOfIndexException();
		} else {
			if (ettol > eddig){
				std::swap(ettol, eddig);
				}
			for (int i = int(ettol); i <= int(eddig); i++){
				returned += char(index(i));
				}
		}

	return returned;
	}

	static Rope concat (Rope& r1, Rope& r2) {
		Node* uj_root = new Node();
		Rope r1_c = r1;
		Rope r2_c = r2;
		uj_root->left = r1_c.root;
		uj_root->right = r2_c.root;
		uj_root->right->parent  = uj_root->left->parent = uj_root;
		Rope* uj_rope = new Rope(uj_root);
		uj_rope->len = r1_c.length() + r2_c.length();
		//std::cout << std::endl << "hossz" << r1.length() << "+" << r2.length() << "=" << uj_rope->len << std::endl;
		r1.~Rope();
		r2.~Rope();
		/*std::string eleje = r1.report(0, r1.length());
		std::string vege = r2.report(0, r2.length());
		Node* bal = new Node(eleje);
		Node* jobb = new Node(vege);
		r1._delete(r1.root);
		r2._delete(r2.root);
		Node* uj_root = new Node();
		uj_root->weight = eleje.length();
		uj_root->left = bal;
		uj_root->right = jobb;
		uj_root->right->parent  = uj_root->left->parent = uj_root;
		Rope* uj_rope = new Rope(uj_root);
		uj_rope->len = eleje.length() + vege.length();
		std::cout<< eleje.length() << vege.length();
		std::cout << uj_rope->length();*/
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
		std::cout << *eleje << *vege;
		std::cout << std::endl << first->length() << "  a masodik  " << second->length() << std::endl;
		rope.~Rope();
		return eredmeny;
	}

};

#endif /* ROPE_CPP_ */

