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
	}
	~Rope(){
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
		if (ettol < 0 || ettol >= len || eddig < 0 || eddig >= len ){
			throw OutOfIndexException();
		} else {
			if (ettol > eddig){
				std::swap(ettol, eddig);
				}
			for (int i = int(ettol); i <= int(eddig); i++){
				returned += index(i);
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
		Rope* uj_rope = new Rope(uj_root);
		uj_rope->len = r1_c.length() + r2_c.length();
		std::cout << std::endl << "hossz" << r1.length() << "+" << r2.length() << "=" << uj_rope->len << std::endl;
		return *uj_rope;
	}

	static std::pair<Rope, Rope> split (Rope& rope, const unsigned int inx) {
		std::pair<Rope, Rope> eredmeny;
		std::string eleje = rope.report(0, inx);
		std::string vege = rope.report(inx, rope.length());

		rope.~Rope();
		return eredmeny;
	}

};

#endif /* ROPE_CPP_ */

