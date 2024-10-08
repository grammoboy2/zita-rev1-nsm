// ----------------------------------------------------------------------------
//
//  Copyright (C) 2008-2015 Fons Adriaensen <fons@linuxaudio.org>
//    
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// ----------------------------------------------------------------------------


#ifndef __ROTARY_H
#define        __ROTARY_H


#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <clxclient.h>


class RotaryGeom
{
public:

    XftColor *_backg;
    XImage   *_image [4];
    char      _lncol [4];
    int       _x0;
    int       _y0;
    int       _dx;
    int       _dy;
    double    _xref;
    double    _yref;
    double    _rad;
};



class RotaryCtl : public X_window
{
public:

    RotaryCtl (X_window    *parent,
               X_callback  *cbobj,
	             int          cbind,
               RotaryGeom  *rgeom,
	             int          xp,
               int          yp);

    virtual ~RotaryCtl (void);

    enum { NOP = 200, PRESS, RELSE, DELTA };

    int    cbind (void) { return _cbind; }
    int    state (void) { return _state; }
    double value (void) { return _value; }

    virtual void set_state (int s);
    virtual void set_value (double v) = 0;
    virtual void get_string (char *p, int n) {}

    static void init (X_display *disp);
    static void fini (void);

    static int  _wb_up;
    static int  _wb_dn;

protected:

    X_callback  *_cbobj;
    int          _cbind;
    RotaryGeom  *_rgeom;
    int          _state;
    int          _count;
    int          _range;
    double       _value;
    double       _angle;

    void render (void);
    void callback (int k) { _cbobj->handle_callb (k, this, 0); }

    static int _keymod;
    static int _button;
    static int _rcount;
    static int _rx;
    static int _ry;

private:

    void handle_event (XEvent *E);
    void bpress (XButtonEvent *E);
    void brelse (XButtonEvent *E);
    void motion (XMotionEvent *E);

    virtual int handle_button (void) = 0;
    virtual int handle_motion (int dx, int dy) = 0;
    virtual int handle_mwheel (int dw) = 0;

    static cairo_t          *_cairotype;
    static cairo_surface_t  *_cairosurf;
};


#endif
