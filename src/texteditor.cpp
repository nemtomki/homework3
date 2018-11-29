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

class TextEditor{
private:
	//valtozoi
public:
	TextEditor();
	TextEditor(std::string input);
	unsigned int length() const;
	void insert(std::string input);
	void stepLeft();
	void stepRight();
	void moveCursor(const unsigned int);
	void select(const unsigned int);
	std::string report() const;
	void remove();
	void ctrlC();
	void ctrlV();
	void ctrlX();
	void ctrlA();
	void ctrlD();
	std::vector<unsigned int> ctrlF(const std::string);

};

#endif /* TEXTEDITOR_CPP_ */

