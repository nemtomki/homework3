/*
 * testeditor.cpp
 *
 *  Created on: 2018. nov. 28.
 *      Author: prajczer
 */
#include <iostream>
#include <vector>
#include <string>

class TextEditor{
private:
	//valtozoi
public:
	unsigned int TextEditor::length() const;
	void TextEditor::insert(string input);
	void TextEditor::stepLeft();
	void TextEditor::stepRight();
	void TextEditor::moveCursor(const unsigned int);
	void TextEditor::select(const unsigned int);
	std::string TextEditor::report() const;
	void TextEditor::remove();
	void TextEditor::ctrlC();
	void TextEditor::ctrlV();
	void TextEditor::ctrlX();
	void TextEditor::ctrlA();
	void TextEditor::ctrlD();
	std::vector<unsigned int> TextEditor::ctrlF(const std::string);

};



