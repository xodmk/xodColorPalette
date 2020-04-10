// *===========================================================================* //
//
//  __::((xodColorPalette.h))::__
//
//  ___::((XODMK Programming Industries))::___
//  ___::((XODMK:CGBW:BarutanBreaks:djoto:2020))::___
//
//
//  A Class Template that organizes HTML Hex Colors into C++ friendly datatypes
//
//  Color Palette 2 type T generator
//  converts array of HTML style Hex codes into a 2D array of type T (int)
//  contains pre-defined XODMK color Palettes
//
//  Author: eschei
//  Created: 23 Jan 2020
//
//
// *===========================================================================* //

#ifndef __XODCOLORPALETTE_H__
#define __XODCOLORPALETTE_H__


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <cassert>

#include "xodColorPaletteInit.h"

using namespace std;

//==============================================================================

// *-- Define custom color palettes: arbitrary names and HTML sytle Hex codes--*
// *-- non-generic code -> need to convert to user friendly push/pop function--*

//enum class xodPalette { seijin, gorgulan, subcon, newwave, trilobyte, barong, purpor, mollusk, tiamat, sebek, worm };


template<class T>
class XodColorPaletteAll
{

public:
	XodColorPaletteAll();
	~XodColorPaletteAll() {}
	void hexStringToRGB(const string& s, T rgbArray[3]);
	void hexPaletteToRGB(xodPalette xp, T rbgPalette[][3]);
	void xodColorGetRGB(xodPalette xp, int cIdx, T xodRgb[3]);
	void printPalette(xodPalette xp);
	vector<string> getKeyNames();

private:

	vector<string> keyNames;
	vector<int> keyValues;

};


// constructor - builds keyNames vector
template<class T>
XodColorPaletteAll<T>::XodColorPaletteAll()
{
	// push color palette string names into vector (becomes alphabetical order)
	for(map< string, vector<string> >::iterator it = paletteMap.begin(); it != paletteMap.end(); ++it) {
		keyNames.push_back(it->first);
		cout << it->first<<"  ";
   }
}


//====================================================
// prints the HEX values of a pre-defined color palette
template<class T>
void XodColorPaletteAll<T>::printPalette(xodPalette xp)
{
	vector<string> testVec2 = paletteMap[paletteNameMap[xp]];
    cout <<paletteNameMap[xp]<<" = ((  ";
    for(string str1 : testVec2)
        cout<<str1<<"  ";
    cout<<"))"<<endl<<endl;
}


//==============================================================================


// function converts HTML Hex string to RGB Integer value array
template<class T>
void XodColorPaletteAll<T>::hexStringToRGB(const string& s, T rgbArray[3])
{
	//assert(s.length == 6);
	for (int i = 0; i < 3; i++) {
		rgbArray[i] = static_cast<T>( std::stoul(s.substr(i * 2, 2), nullptr, 16) );
	}
}

//====================================================
// function to generate a single RGB set from an xodPalette
template<class T>
void XodColorPaletteAll<T>::xodColorGetRGB(xodPalette xp, int cIdx, T xodRgb[3])
{
	vector<string> colorHexV = paletteMap[paletteNameMap[xp]];
	assert (cIdx < colorHexV.size());
	hexStringToRGB(colorHexV[cIdx], xodRgb);
}


//====================================================
// function converts HTML Hex string to a RGB palette of type T
template<class T>
void XodColorPaletteAll<T>::hexPaletteToRGB(xodPalette xp, T rbgPalette[][3])
{
	T rgbArray[3];
	vector<string> colorHexV = paletteMap[paletteNameMap[xp]];

	for (int i = 0; i < colorHexV.size(); i++) {
		hexStringToRGB(colorHexV[i], rgbArray);
		for (int j = 0; j < 3; j++) {
			rbgPalette[i][j] = rgbArray[j];
		}
	}
}


//====================================================
// function to generate a single RGB set from an xodPalette
template<class T>
vector<string> XodColorPaletteAll<T>::getKeyNames()
{
	vector<string> kNames = keyNames;
	return kNames;
}


//==============================================================================

template<class T>
class XodColorPalette
{

public:
	XodColorPalette(xodPalette xp);
	~XodColorPalette() {}
	void hexStringToRGB(const string& s, T rgbArray[3]);
	void hexPaletteToRGB(T rbgPalette[][3]);
	void xodColorGetRGB(int cIdx, T xodRgb[3]);
	void printPalette();

private:

	string keyName;
	int keyValue;

};


// constructor - builds keyNames vector
template<class T>
XodColorPalette<T>::XodColorPalette(xodPalette xp)
{
	keyName = paletteNameMap[xp];
	vector<string> colorHexV = paletteMap[paletteNameMap[xp]];
}

//====================================================
// function converts HTML Hex string to RGB Integer value array
template<class T>
void XodColorPalette<T>::hexStringToRGB(const string& s, T rgbArray[3])
{
	//assert(s.length == 6);
	for (int i = 0; i < 3; i++) {
		rgbArray[i] = static_cast<T>( std::stoul(s.substr(i * 2, 2), nullptr, 16) );
	}
}

//====================================================
// function converts HTML Hex string to a RGB palette of type T
template<class T>
void XodColorPalette<T>::hexPaletteToRGB(T rbgPalette[][3])
{
	T rgbArray[3];
	vector<string> colorHexV = paletteMap[keyName];

	for (int i = 0; i < colorHexV.size(); i++) {
		hexStringToRGB(colorHexV[i], rgbArray);
		for (int j = 0; j < 3; j++) {
			rbgPalette[i][j] = rgbArray[j];
		}
	}
}

//====================================================
// function to generate a single RGB set from an xodPalette
template<class T>
void XodColorPalette<T>::xodColorGetRGB(int cIdx, T xodRgb[3])
{
	vector<string> colorHexV = paletteMap[keyName];
	assert (cIdx < colorHexV.size());
	hexStringToRGB(colorHexV[cIdx], xodRgb);
}

//====================================================
// prints the HEX values of a pre-defined color palette
template<class T>
void XodColorPalette<T>::printPalette()
{
	vector<string> testVec2 = paletteMap[keyName];
    cout <<keyName<<" = ((  ";
    for(string str1 : testVec2)
        cout<<str1<<"  ";
    cout<<"))"<<endl<<endl;
}


#endif	// __XODCOLORPALETTE_H__

//==============================================================================
