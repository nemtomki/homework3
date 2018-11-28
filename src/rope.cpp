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
		Node(){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			szoveg = new char[3];
		}
		Node(string be){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			szoveg = new char[3];
			for (size_t i = 0; i< be.size(); i++){
				szoveg[i] = be[i];
				weight ++;
			}
		}
		~Node();
	};
private:
	unsigned int len;

public:
	Rope();
	~Rope();
	unsigned int length();
	char index(const unsigned int) const;
	static Rope concat (Rope& r1, Rope& r2);
	static std::pair<Rope, Rope> split (Rope&, const unsigned int);
	std::string report(unsigned int, unsigned int) const;
};

Rope::Rope(){
	len = 0;
}
unsigned int Rope::length(){
	return len;
}

char Rope::index(const unsigned int x) const{
	return 'x';
}



