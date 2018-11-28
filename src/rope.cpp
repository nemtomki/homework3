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
		vector<char> szoveg;
		Node(){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			szoveg = {};
		}
		Node(string be){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			weight = 0;
			for (size_t i = 0; i< be.size(); i++){
				szoveg.push_back(be[i]);
			}
		}
		~Node();
	};
private:
	unsigned int len;
public:
	Rope();
	~Rope();
	unsigned int Rope::length();
	char Rope::index(const unsigned int) const;
	static Rope Rope::concat (Rope& r1, Rope& r2);
	static std::pair<Rope, Rope> Rope::split (Rope&, const unsigned int);
	std::string Rope::report(unsigned int, unsigned int) const;
};

unsigned int Rope::length(){
	return len;
}

char Rope::index(const unsigned int x) const{
	return 'x';
}



