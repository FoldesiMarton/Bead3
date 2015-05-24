#ifndef EXITBUTTON_HPP
#define EXITBUTTON_HPP

#include "button.hpp"
#include "application.hpp"

class ExitButton : public Button // alkalmazás kilépõ gomb
{
public:
    ExitButton(int px, int py, int sx, int sy, std::string text)
    : Button(px, py, sx, sy, text)
    {
        _app = NULL;
    }
    void setApplication(Application* app) { _app = app; } // alkalmazás beállítása
    Application* application() const { return _app; } // alkalmazás lekérdezése

protected:
    void action() // felüldefiniáljuk az akciófüggvényt
    {
        if (_app) // ha a mutató nem nulla
            _app->shutdown(); // kilépünk a programból
    }

    Application* _app;
};

#endif // EXITBUTTON_HPP
