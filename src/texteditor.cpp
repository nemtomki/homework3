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
	void remove();
	void ctrlC();
	void ctrlV();
	void ctrlX();
	void ctrlA();
	void ctrlD();
	std::vector<unsigned int> ctrlF(const std::string);

	TextEditor(){
		actual_pos = 0;
		szoveg = new Rope();
		selected = 0;
	}

	TextEditor(std::string input){
		actual_pos = 0;
		szoveg = new Rope(input);
		selected = 0;
	}
	~TextEditor(){
		delete szoveg;
	}
	unsigned int length() const{
		//std::cout << szoveg->length();
		return szoveg->length();
	}
	void insert(std::string befele){
		std::string teljes= szoveg->report(0, (szoveg->length())-1) + befele;
		szoveg->~Rope();
		szoveg = new Rope(teljes);
	}

	void stepLeft(){
		if (actual_pos <= int(szoveg->length())){
			actual_pos ++;
		} else {
			std::cout << "A szoveg vegere ertunk!" << std::endl;
		}
	}

	void stepRight(){
		if (actual_pos >= 0){
			actual_pos --;
		} else {
			std::cout << "A szoveg elejere ertunk" << std::endl;
		}

	}
	void moveCursor(const unsigned int x){
		actual_pos = x;
	}
	void select(const unsigned int eddig){
		if (eddig >= 0 && eddig <= szoveg->length()){
			selected = eddig;
		} else {
			std::cout << "Hibas ertek" << std::endl;
		}
	}

	std::string report() {
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
		}
		return "";
	}
};

#endif /* TEXTEDITOR_CPP_ */

