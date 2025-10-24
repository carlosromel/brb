/**
 * Copyleft (c) 2025 Carlos Romel Pereira da Silva, carlos.romel@gmail.com
 */
#ifndef _BRB_H
#define _BRB_H          1

char elementos[][3] = {
    "Ac", "Ag", "Al", "Am", "Ar", "As", "At", "Au", "B",  "Ba", "Be", "Bh", "Bi"
  , "Bk", "Br", "C",  "Ca", "Cd", "Ce", "Cf", "Cl", "Cm", "Cn", "Co", "Cr", "Cs"
  , "Cu", "Db", "Ds", "Dy", "Er", "Es", "Eu", "F",  "Fe", "Fl", "Fm", "Fr", "Ga"
  , "Gd", "Ge", "Hf", "Hg", "Ho", "Hs", "I",  "In", "Ir", "K",  "Kr", "La", "Li"
  , "Lr", "Lu", "Lv", "Mc", "Md", "Mg", "Mn", "Mo", "Mt", "N",  "Na", "Nb", "Nd"
  , "Ne", "Nh", "Ni", "No", "Np", "O",  "Og", "Os", "P",  "Pa", "Pb", "Pd", "Pm"
  , "Po", "Pr", "Pt", "Pu", "Ra", "Rb", "Re", "Rf", "Rg", "Rh", "Rn", "Ru", "S"
  , "Sb", "Sc", "Se", "Sg", "Si", "Sm", "Sn", "Sr", "Ta", "Tb", "Tc", "Te", "Th"
  , "Ti", "Tl", "Tm", "Ts", "U",  "V",  "W",  "Xe", "Y",  "Yb", "Zn", "Zr" };

char *brb(char c[], int debug);
#endif

