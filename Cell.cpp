#include "Cell.hpp"
using namespace genv;

Cell::Cell()
: Widget()
{

}

void Cell::draw(int x, int y)               /// kirajzolás
{
    gout<<color(255,255,255)<<move_to(x,y)<<box(100,100);   /// fehér 100x100as box
    gout<<color(0,0,0)<<move_to(x+1,y+1)<<box(98,98);       /// bele egy fekete

    if(s=="x")      /// első játékos színe piros
    {
           gout<<color(255,0,0)<<move_to(x+4,y+4)<<box(92,92);
    }
    if(s=="o")      /// második játékos színe zöld
    {
        gout<<color(0,255,0)<<move_to(x+4,y+4)<<box(92,92);
    }
}

void Cell::handle(event ev)
{
    // ha a gomb fókuszálva van és ENTER-t ütünk, vagy felette bal egérgombbal kattintunk
    if (( inFocus && ev.keycode == key_enter) ||
        (is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left))
    {
        action(); // hajtsuk végre az akciót
    }
}

void Cell::reset() {
}

