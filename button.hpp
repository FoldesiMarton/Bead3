#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widgets.hpp"
#include <string>

class Button : public Widget    /// gomb vez�rl�je
{
public:
    Button(int px, int py, int sx, int sy, std::string text);
    void draw();
    void handle(genv::event ev);/// esem�nykezel�s
    void setText(std::string text);


    std::string getText() const { return _text; }
protected:
    virtual void action() {}    /// akci�kezel�s, ez lehet rejtett
    void reset();               ///�res reszetel�shez, nem fog semit csin�lni
    std::string _text;
};


#endif // BUTTON_ppH
