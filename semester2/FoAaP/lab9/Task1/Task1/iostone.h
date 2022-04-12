#pragma once
#include "Stone.h"

istream& operator >> (istream& in, PreciousStone& Stone);

istream& operator >> (istream& in, SemipreciousStone& Stone);

ostream& operator << (ostream& out, StoneGroup Group);