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
	void ctrlA();
	void ctrlD();
	std::vector<unsigned int> ctrlF(const std::string);

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
		std::string teljes= szoveg->report(0, (szoveg->length())-1) + befele;
		szoveg->~Rope();
		szoveg = new Rope(teljes);
	}

	void stepLeft(){
		if (actual_pos <= int(szoveg->length())){
			actual_pos ++;
		} else {
			throw UnderFlowException();
		}
	}

	void stepRight(){
		if (actual_pos >= 0){
			actual_pos --;
		} else {
			throw OverFlowException();
		}

	}
	void moveCursor(const unsigned int x){
		actual_pos = x;
	}
	void select(const unsigned int eddig){
		if (eddig >= 0 && eddig <= szoveg->length()){
			selected = eddig;
		} else {
			throw OutOfIndexException();
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
	void remove(){
		if (actual_pos == -1){
			;
		} else {
			if (actual_pos > selected){

			}
		}
	}
};

#endif /* TEXTEDITOR_CPP_ */

