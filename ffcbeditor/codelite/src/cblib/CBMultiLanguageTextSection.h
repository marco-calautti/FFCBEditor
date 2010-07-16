//Copyright (C) 2010 Phoenix. 

//This program is free software: you can redistribute it and/or modify 
//it under the terms of the GNU General Public License as published by 
//the Free Software Foundation, version 2.0. 

//This program is distributed in the hope that it will be useful, 
//but WITHOUT ANY WARRANTY; without even the implied warranty of 
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
//GNU General Public License 2.0 for more details. 

//A copy of the GPL 2.0 should have been included with the program. 
//If not, see http://www.gnu.org/licenses/ 

//Official SVN repository and contact information can be found at 
//http://code.google.com/p/ffcbeditor/


#ifndef __CB_MULTI_LANGUAGE_TEXT_SECTION__
#define __CB_MULTI_LANGUAGE_TEXT_SECTION__

#include "CBTextSection.h"

//Languages used by FFCB
enum LanguageType{
		ALL_LANGUAGES=-1,
		JAPANESE_LANGUAGE=0,
		ENGLISH_LANGUAGE=1,
		GERMAN_LANGUAGE=3,
		FRENCH_LANGUAGE=4,
		SPANISH_LANGUAGE=5
};

//Max number of supported languages in FFCB
#define SUPPORTED_LANGUAGES 8

//A text section wich supports multilanguage text blocks. As for now, there is only
//one type of multilanguage text section (contained in EEVB files). So, we can assume
//only languages in enum LanguageType are used, but this type of section can store 
//up to 8 different languages.

class CBMultiLanguageTextSection : public CBTextSection
{
public:
	
	//Sets the language to be used by this text section. If set to ALL_LANGUAGES,
	//this text section behaves like any other text section (you can access to all text blocks),
	//otherwise, the GetText, SetText and Size methods will change their behaviour:
	//Size(void) returns the number of text blocks of the selected language.
	//GetText(void) returns the first text block of the selected language.
	//SetText(wxString&) sets the first text block of the selected language.
	//GetText(size_t idx) returns the idx-th text block of the selected language.
	//SetText(size_t idx,wxString&) sets the idx-th text block of the selected language.
	virtual void SetLanguage(LanguageType lng)=0;
	virtual LanguageType GetLanguage()=0;
	virtual ~CBMultiLanguageTextSection(){}
};
#endif
