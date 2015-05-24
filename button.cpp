#include "button.hpp"
using namespace genv;

Button::Button(int px, int py, int sx, int sy, std::string text)
    : Widget(px, py, sx, sy)
{
    _text = text;
}

void Button::draw()
{
    gout << move_to(x, y) << color(255,255,255) << box(size_x-1, size_y-1);

    if( inFocus)
    {
        gout << color(135,135,135);
    }
    else
    {
        gout << color(175,175,175);
    }
    gout << move_to( x + 1, y + 1) << box( size_x - 2, size_y - 2);

    gout << color(0,0,0)<< move_to( x +  size_x / 2 - gout.twidth(_text) / 2, y + size_y / 2 + 6)<< text(_text);
}

void Button::handle(event ev)
{
    // ha a gomb f�kusz�lva van �s ENTER-t �t�nk, vagy felette bal eg�rgombbal kattintunk
    if (( inFocus && ev.keycode == key_enter) ||
            (is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left))
    {
        action(); // hajtsuk v�gre az akci�t
        inFocus=!inFocus;
    }

}

void Button::reset()            ///�res reset, nem csin�l semmit
{
}

