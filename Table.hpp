#ifndef TABLE_HPP
#define TABLE_HPP

#include "widgets.hpp"
#include "application.hpp"
#include "Cell.hpp" ///meghívom a cellámat

class Table : public Widget // gomb vezérlõje
{
public:
    Cell* cells[7][6];  /// létrehozom a 7x6os mátrixom amiben az adatokat fogom tárolni
    int x, y, sx, sy;   /// pozíció és méret változói
    bool plyr=true;     /// játékos eldöntésére létrehozott változó
    int free=7*6;       /// a szabad helyek eldöntésére létrehozott változó (döntetlen eldöntésére :D )
    bool p1win=false;   /// az első számú játékos győzelére létrehozott változó
    bool p2win=false;   /// az második számú játékos győzelére létrehozott változó

    Table(int x, int y, int sx, int sy);
    void draw();
    void handle(genv::event ev); // eseménykezelés



protected:
    virtual void action() {} // akciókezelés, ez lehet rejtett
    void reset();               ///reseteléshez.
};


#endif // TABLE_ppH

