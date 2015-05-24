#ifndef EXITBUTTON_HPP
#define EXITBUTTON_HPP

#include "button.hpp"
#include "application.hpp"

class ExitButton : public Button // alkalmaz�s kil�p� gomb
{
public:
    ExitButton(int px, int py, int sx, int sy, std::string text)
    : Button(px, py, sx, sy, text)
    {
        _app = NULL;
    }
    void setApplication(Application* app) { _app = app; } // alkalmaz�s be�ll�t�sa
    Application* application() const { return _app; } // alkalmaz�s lek�rdez�se

protected:
    void action() // fel�ldefini�ljuk az akci�f�ggv�nyt
    {
        if (_app) // ha a mutat� nem nulla
            _app->shutdown(); // kil�p�nk a programb�l
    }

    Application* _app;
};

#endif // EXITBUTTON_HPP
