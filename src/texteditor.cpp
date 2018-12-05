/*
 * testeditor.cpp
 *
 *  Created on: 2018. nov. 28.
 *      Author: prajczer
*/
#ifndef TEXtEDITOR_CPP_
#define TEXTEDITOR_CPP_

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "rope.cpp"
#include "exception.cpp"

class TextEditor{
private:
	int actual_pos;
	Rope *szoveg;
	int selected;
public:
	//TextEditor();
	//TextEditor(std::string input);
	//unsigned int length() const;
	//void insert(std::string input);
	//void stepLeft();
	//void stepRight();
	//void moveCursor(const unsigned int);
	//void select(const unsigned int);
	//std::string report() const;
	//void remove();
	void ctrlC();
	void ctrlV();
	void ctrlX();

	void ctrlD();
	//std::vector<unsigned int> ctrlF(const std::string);

	TextEditor(){
		actual_pos = 0;
		szoveg = new Rope();
		selected = -1;
	}

	TextEditor(std::string input){
		actual_pos = 0;
		szoveg = new Rope(input);
		selected = -1;
	}
	~TextEditor(){
		actual_pos = 0;
		selected = -1;
		delete szoveg;
	}
	unsigned int length() const{
		//std::cout << szoveg->length();
		return szoveg->length();
	}
	void insert(const std::string befele){
		std::string teljes= szoveg->report(0, (szoveg->length())) + befele;
		szoveg->~Rope();
		szoveg = new Rope(teljes);
	}

	void stepLeft(){
		if (actual_pos <= int(szoveg->length())){
			actual_pos ++;
			selected = actual_pos;
		} else {
			throw UnderFlowException();
		}
	}

	void stepRight(){
		if (actual_pos >= 0){
			actual_pos --;
			selected = actual_pos;
		} else {
			throw OverFlowException();
		}

	}
	void moveCursor(const unsigned int x){
		if (x >= 0 && x <= szoveg->length()){
			actual_pos = x;
			selected = x;
		} else {
			actual_pos = length();
			selected = length();
		}

	}
	void select(const unsigned int eddig){
		if (eddig >= 0 && eddig <= szoveg->length()){
			selected = eddig;
		} else {
			selected = length();
		}
	}

	std::string report() const{
		int ettol, eddig;
		if (actual_pos > selected){
			eddig = actual_pos;
			ettol = selected;
		} else {
			eddig = selected;
			ettol = actual_pos;
		}
		if (ettol >= 0 && ettol < int(szoveg->length()) && eddig >= 0 && eddig < int(szoveg->length())){
			return szoveg->report(ettol, eddig);
		} else {
			return "";
		}
	}
	std::vector<unsigned int> ctrlF(const std::string wanted){
		std::string teljes = szoveg->report(0, length());
		std::vector<unsigned int> returning;
		int hosszunk = wanted.length();
		for (unsigned int i = 0; i < length(); i++){
			int lett = 1;
			for (int j = 0; j < hosszunk; j++){
				if ( wanted[j] != teljes[i+j]){
					lett = 0;
				}
			}
			if ( lett == 1){
				returning.push_back(i);
			}
		}
		return returning;
	}
	void ctrlA(){
		actual_pos = 0;
		selected = length();
	}

	void remove(){
		if (selected != -1){
			std::pair<Rope, Rope> elsok = szoveg->split(*szoveg, actual_pos);
			std::pair<Rope, Rope> masodikak = szoveg->split(*szoveg, selected);
			std::cout << elsok.first.length() << masodikak.second.length() << actual_pos << selected;
			Rope uj_szoveg = szoveg->concat(elsok.first, masodikak.second);
			szoveg = &uj_szoveg;
		}
	}
};

#endif /* TEXTEDITOR_CPP_ */

