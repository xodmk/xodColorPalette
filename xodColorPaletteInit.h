// *===========================================================================* //
//
//  __::((xodColorPaletteInit.h))::__
//
//  ___::((XODMK Programming Industries))::___
//  ___::((XODMK:CGBW:BarutanBreaks:djoto:2020))::___
//
//
//  Color Palette Initialization Header
//  converts array of HTML style Hex codes into a 2D array of type T (int)
//  contains pre-defined XODMK color Palettes
//
//  Author: eschei
//  Created: 23 Jan 2020
//
//
// *===========================================================================* //

#ifndef __XODCOLORPALETTEINIT_H__
#define __XODCOLORPALETTEINIT_H__


#include <vector>
#include <string>
#include <map>


using namespace std;

//==============================================================================

// *-- Define custom color palettes: arbitrary names and HTML sytle Hex codes--*
// *-- Requirement - enum entries must match map Key names --*

enum class xodPalette { seijin, gorgulan, subcon, newwave, trilobyte, barong, purpor, mollusk, tiamat, sebek, worm };

map< xodPalette, string > paletteNameMap {

    {xodPalette::seijin,    "seijin" },
    {xodPalette::gorgulan,  "gorgulan" },
    {xodPalette::subcon,    "subcon" },
    {xodPalette::newwave,   "newwave" },
    {xodPalette::trilobyte, "trilobyte" },
    {xodPalette::barong,    "barong" },
    {xodPalette::purpor,    "purpor" },
    {xodPalette::mollusk,   "mollusk" },
    {xodPalette::tiamat,    "tiamat" },
    {xodPalette::sebek,     "sebek" },
    {xodPalette::worm,      "worm" }

};


map< string, vector<string> > paletteMap {

    {"seijin",    { "171111", "3d292f", "634457", "83638a", "9689c3", "96b4ff" }},
    {"gorgulan",  { "4f4e4e", "726068", "897590", "8992c0", "69b5ea", "00d9ff" }},
    {"subcon",    { "053d47", "00486d", "334c8c", "7f4292", "bd2976", "de2c41" }},
    {"newwave",   { "1c6ced", "5d5cd8", "794bc2", "8a3aaa", "932791", "961179" }},
    {"trilobyte", { "17160a", "333b0c", "4a6602", "569500", "51c800", "14ff18" }},
    {"barong",    { "2e1111", "551418", "7f131b", "a90d1b", "d40415", "ff0004" }},
    {"purpor",    { "5c163a", "882442", "b23942", "d6573a", "f07c29", "ffa600" }},
    {"mollusk",   { "415559", "355468", "434d74", "65406e", "822e53", "8a2828" }},
    {"tiamat",    { "242c2e", "2e4c53", "356e7a", "3791a4", "32b7d1", "21deff" }},
    {"sebek",     { "171111", "3e1421", "610e42", "791173", "772eb4", "0856ff" }},
    {"worm",      { "7da2ab", "648eaf", "6d74a9", "89538d", "982c58", "8a1616" }}

};

#endif	// end __XODCOLORPALETTEINIT_H__

//==============================================================================

//std::vector<std::string> xodpv(xpArgs, xpArgs + sizeof(xpArgs) / sizeof(xpArgs[0])); //get array size