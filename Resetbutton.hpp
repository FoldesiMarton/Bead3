#ifndef RESTARTBUTTON_HPP
#define RESTARTBUTTON_HPP

#include "Table.hpp"
#include "button.hpp"
#include "application.hpp"

class ResetButton : public Button // c�mkefelirat m�dos�t� gomb
{
public:
    ResetButton(int px, int py, int sx, int sy, std::string text)
        : Button(px, py, sx, sy, text)
    {
        _app = NULL;
    }
    void setApplication(Application* app)
    {
        _app = app;    // alkalmaz�s be�ll�t�sa
    }
    Application* application() const
    {
        return _app;    // alkalmaz�s lek�rdez�se
    }

protected:
    void action() // fel�ldefini�ljuk az akci�f�ggv�nyt
    {
        if (_app) // ha a mutat� nem nulla
        _app->reset();
    }

    Application* _app;
};
#endif // RESTARTBUTTON_HPP
