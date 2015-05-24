#include "application.hpp"
#include "Table.hpp"
#include "Cell.hpp"
#include "button.hpp"
#include "exitbutton.hpp"
#include "Resetbutton.hpp"

int main()
{
    Application app(830,620, "Amoba");

    Table* t=new Table(0,0,700,600);
    ExitButton* eb = new ExitButton(717, 150, 100, 25, "Exit");
    ResetButton* rs =new ResetButton(717,100,100,25,"Reset");


    eb->setApplication(&app);
    rs->setApplication(&app);

    app.addWidget(t);                   ///létrehhozzuk a widgetet
    app.addWidget(eb);
    app.addWidget(rs);
    app.run();                          /// futtatjuk az alkalmazást

    return 0;
}
