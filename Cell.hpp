#ifndef CELL_HPP
#define CELL_HPP

#include "widgets.hpp"
#include <string>
using namespace std;
class Cell : public Widget // gomb vezérlõje
{
public:
    string s="";        /// a mátrixomban tárolt értékeknek létrehozott változó
    int xsize=10;       ///
    int ysize=10;       ///


    Cell();
    void draw(int x, int y);
    void handle(genv::event ev); // eseménykezelés

protected:
    virtual void action() {} // akciókezelés, ez lehet rejtett
    void reset();
};


#endif // CELL_ppH

