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
			is_leaf = false;
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
	//nsigned int length();

	//char index(const unsigned int) const;
	//static Rope concat (Rope& r1, Rope& r2);
	static std::pair<Rope, Rope> split (Rope&, const unsigned int);
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
		_print(root, std::cout);
		std::cout << "mi a fasz:" << index(50);
	}
	~Rope(){
		Rope::_delete(root);
	}

	void _delete(Node *from){
		if (from != nullptr){
			_delete(from->left);
			_delete(from->right);
			delete from;
		}
	}

	unsigned int length(){
		return len;
	}

	char index(const unsigned int x) {
		char returning;
		int hol = x;
		int kezdet = 0;
		kereso(root, kezdet, hol, returning);
		return returning;
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

	char& kereso(Node *i, int& akt_hely, int hely, char &returned){
		char* str = i->szoveg;
		for (size_t i =0; i < 3; i++){
			if (0 != isprint(str[i]) && str[i] != '\n'){
				if (hely == akt_hely){
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
	std::string report(int ettol, int eddig){
		std::string returned;
		for (int i = ettol; i <= eddig; i++){
			returned += index(i);
		}
	return returned;
	}

	static Rope concat (Rope& r1, Rope& r2) {
		Node* uj_root = new Node();
		uj_root->left = r1.root;
		uj_root->right = r2.root;
		Rope* uj_rope = new Rope(uj_root);
		uj_rope->len = r1.len + r2.len;
		return *uj_rope;
	}
};

#endif /* ROPE_CPP_ */

