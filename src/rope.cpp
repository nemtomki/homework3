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
using namespace std;

class Rope{
	struct Node {
		Node *parent;
		Node *left, *right;
		unsigned int weight;
		char szoveg[3];
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
					std::cout << szoveg[i];
					weight ++;
				}
				std::cout << std::endl;
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
	static Rope concat (Rope& r1, Rope& r2);
	static std::pair<Rope, Rope> split (Rope&, const unsigned int);
	std::string report(unsigned int, unsigned int) const;

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

	char index(const unsigned int x) const{
		int current = 0;
		Node *act = root;

		return 'x';
	}
	std::ostream& _print(Node *i, std::ostream& o){
		o << i->szoveg;
		if (i->left != nullptr) {
			_print(i->left, o);
		}
		if (i->right != nullptr) {
			_print(i->right, o);
		}
		return o;
	}
};

#endif /* ROPE_CPP_ */

