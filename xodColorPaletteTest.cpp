// *===========================================================================* //
//
//  __::((xodmkColorz_tb.cpp))::__
//
//  ___::((XODMK Programming Industries))::___
//  ___::((XODMK:CGBW:BarutanBreaks:djoto:2020))::___
//
//
//  Color Palette 2 type T generator
//  converts array of HTML style Hex codes into a 2D array of type T (int)
//  contains pre-defined XODMK color Palettes
//
//  Author: eschei
//  Created: 23 Jan 2020
//
//  compile:
//  g++ -std=c++11 -o xodColors xodColorPaletteTest.cpp
//
//
// *===========================================================================* //

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include "xodColorPalette.h"


int main()
{

	/*------------------------------------------------------------------------------------------------*/
	/*---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%---*
	/*------------------------------------------------------------------------------------------------*/

    XodColorPalette<int> CP;


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Intanced XodColorHex2T Class Template.."<<endl<<endl;


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Print Defined Color Palette Names (map keyNames):"<<endl<<endl;

    cout<<"(( ";
    for(auto s : CP.keyNames)
        cout<<s<<" ";
    cout<<"))"<<endl<<endl;


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Print a pre-defined color palette (printPalette(...):"<<endl<<endl;

    CP.printPalette(xodPalette::tiamat);


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Get a specific RGB value (xodColorGetRGB(...):"<<endl<<endl;

    string exampleHexStr {"565656"};
    int gxRGB1[3];
    CP.hexStringToRGB(exampleHexStr, gxRGB1);

    cout <<"exampleHexStr {565656} = (( ";
    for(int x : gxRGB1)
        cout<<x<<"  ";
    cout<<"))"<<endl<<endl;


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Get specific RGB value <int> from ColorPalette Map (xodColorGetRGB(...):"<<endl<<endl;

    int gxRGB2[3];
    CP.xodColorGetRGB(xodPalette::seijin, 5, gxRGB2);

    cout <<"seijin(5) = (( ";
    for(int x : gxRGB2)
        cout<<x<<" ";
    cout<<"))"<<endl<<endl;


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Convert HTML HEX string array to a RGB palette of type T (hexPaletteToRGB(...):"<<endl<<endl;

    int gxRgbPalette[6][3];
    CP.hexPaletteToRGB(xodPalette::sebek, gxRgbPalette);

    cout <<"color palette 'sebek' RGB <int> values:"<<endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            cout<<gxRgbPalette[i][j]<<" ";
        }
        cout<<endl;
    }


    cout <<endl;
    cout <<"// *----------------------------------------------------------------* //"<<endl;
    cout <<"Repeat above for HEX string array of different size:"<<endl<<endl;

    int gxRgbPalette2[4][3];
    CP.hexPaletteToRGB(xodPalette::misc, gxRgbPalette);

    cout <<"color palette 'sebek' RGB <int> values:"<<endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout<<gxRgbPalette[i][j]<<" ";
        }
        cout<<endl;
    }

    /*------------------------------------------------------------------------------------------------*/
    /*---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%---*
    /*------------------------------------------------------------------------------------------------*/


}