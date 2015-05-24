#ifndef RESTARTBUTTON_HPP
#define RESTARTBUTTON_HPP

#include "Table.hpp"
#include "button.hpp"
#include "application.hpp"

class ResetButton : public Button // címkefelirat módosító gomb
{
public:
    ResetButton(int px, int py, int sx, int sy, std::string text)
        : Button(px, py, sx, sy, text)
    {
        _app = NULL;
    }
    void setApplication(Application* app)
    {
        _app = app;    // alkalmazás beállítása
    }
    Application* application() const
    {
        return _app;    // alkalmazás lekérdezése
    }

protected:
    void action() // felüldefiniáljuk az akciófüggvényt
    {
        if (_app) // ha a mutató nem nulla
        _app->reset();
    }

    Application* _app;
};
#endif // RESTARTBUTTON_HPP
