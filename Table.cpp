#include "Table.hpp"

using namespace genv;

Table::Table(int x, int y, int sx, int sy)
    : Widget(x, y, sx, sy)
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<6; j++)
        {
            cells[i][j]=new Cell(); /// létrehozom a 7x6-os táblámat
        }
    }
}

void Table::draw()      /// kirajzolás
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<6; j++)
        {
            cells[i][j]->draw(i*100,j*100); /// kirajzolom a 7x6-os táblázatom (a 100-as szorzás a cellám mérete)
        }
    }
    gout<<move_to(708,196)<<color(175,175,175)<<box(114,26);
    gout<<move_to(708,198)<<color(100,100,100)<<box(112,22);
    gout<<move_to(744,220)<<color(100,100,100)<<box(42,23);
    gout<<move_to(744,220)<<color(175,175,175)<<box(42,22);

    gout<<move_to(745,220)<<color(255,255,255)<<box(40,20)<<move_to(749,235)<<color(0,0,0)<<text("turn");
    if (plyr)       /// kirajzolom, éppen ki van soron
    {
        gout<<move_to(710,200)<<color(255,255,255)<<box(110,20)<<move_to(715,215)<<color(0,0,0)<<text(" I. Player's");
    }
    else
    {
        gout<<move_to(710,200)<<color(255,255,255)<<box(110,20)<<move_to(715,215)<<color(0,0,0)<<text("II. Player's");
    }

    if(p1win)
    {
        gout<<color(0,255,255)<<move_to(200,280)<<box(110,30)<<color(255,0,0)<<move_to(200,300)<<text("PLAYER 1 WINS!");
    }

    if(p2win)
    {
        gout<<color(255,255,0)<<move_to(200,280)<<box(110,30)<<color(0,0,255)<<move_to(200,300)<<text("PLAYER 2 WINS!");
    }

    if(free==0)
    {
        gout<<color(255,255,255)<<move_to(200,280)<<box(90,30)<<color(0,0,0)<<move_to(200,300)<<text("DÖNTETLEN!");
    }
}

void Table::handle(event ev)
{

    if (( inFocus && ev.keycode == key_enter) ||
            (is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left))
    {
        int x=ev.pos_x/100;
        int y=6;
        int i=1;

        if(plyr)            /// plyr1 köre ///
        {
            while(i<7)
            {
                if(cells[x][y-i]->s=="" && p1win == false)
                {
                    cells[x][y-i]->s="x";
                    plyr=!plyr;
                    i=7;
                    free--;
                }
                i++;
            }
            for(int j=0; j<7; j++)
            {
                for(int k=0; k<6; k++)
                {
                    if(k<3 && j<4)          /// dél-keleti értékelés
                    {
                        if(cells[j][k]->s=="x" && cells[j+1][k+1]->s=="x" && cells[j+2][k+2]->s=="x" && cells[j+3][k+3]->s=="x")
                        {
                            p1win=true;
                        }
                    }
                    if(k>2 && j<4)          /// észak-keleti értékelés
                    {
                        if(cells[j][k]->s=="x"&&cells[j+1][k-1]->s=="x"&&cells[j+2][k-2]->s=="x"&&cells[j+3][k-3]->s=="x")
                        {
                            p1win=true;
                        }
                    }
                    if(j<4)                 /// horizontális értékelés
                    {
                        if(cells[j][k]->s=="x"&&cells[j+1][k]->s=="x"&&cells[j+2][k]->s=="x"&&cells[j+3][k]->s=="x")
                        {
                            p1win=true;
                        }
                    }
                    if(k>3)                 /// vertikális értékelés
                    {
                        if(cells[j][k]->s=="x"&&cells[j][k-1]->s=="x"&&cells[j][k-2]->s=="x"&&cells[j][k-3]->s=="x")
                        {
                            p1win=true;
                        }
                    }
                }
            }

            if (p1win)          /// ha a plyr1 nyer, beakasztom a gamet
            {
                plyr=true;
            }

        }
        else                /// plyr2 köre ///
        {
            while(i<7)
            {
                if(cells[x][y-i]->s=="" && p2win==false)
                {
                    cells[x][y-i]->s="o";
                    plyr=!plyr;
                    i=7;
                    free--;
                }
                i++;
            }
            for(int j=0; j<7; j++)
            {
                for(int k=0; k<6; k++)
                {
                    if(k<3 && j<4)          /// dél-keleti értékelés
                    {
                        if(cells[j][k]->s=="o" && cells[j+1][k+1]->s=="o" && cells[j+2][k+2]->s=="o" && cells[j+3][k+3]->s=="o")
                        {
                            p2win=true;
                        }
                    }
                    if(k>2 && j<4)          /// észak-keleti értékelés
                    {
                        if(cells[j][k]->s=="o"&&cells[j+1][k-1]->s=="o"&&cells[j+2][k-2]->s=="o"&&cells[j+3][k-3]->s=="o")
                        {
                            p2win=true;
                        }
                    }
                    if(j<4)                 /// horizontális értékelés
                    {
                        if(cells[j][k]->s=="o"&&cells[j+1][k]->s=="o"&&cells[j+2][k]->s=="o"&&cells[j+3][k]->s=="o")
                        {
                            p2win=true;
                        }
                    }
                    if(k>3)                 /// vertikális értékelés
                    {
                        if(cells[j][k]->s=="o"&&cells[j][k-1]->s=="o"&&cells[j][k-2]->s=="o"&&cells[j][k-3]->s=="o")
                        {
                            p2win=true;
                        }
                    }
                }
            }
            if (p2win)          /// ha a plyr2 nyer, beakasztom a gamet
            {
                plyr=false;
            }
        }
    }
}

void Table::reset()                 ///kezdeti értékek visszaállítása
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<6; j++)
        {
            cells[i][j]=new Cell();
        }
    }

    p1win=false;
    p2win=false;
    free=6*7;
    plyr=true;

}

