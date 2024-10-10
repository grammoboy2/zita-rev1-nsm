// ----------------------------------------------------------------------------
//
//  Copyright (C) 2009-2017 Fons Adriaensen <fons@linuxaudio.org>
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


#include "styles.h"
#include "png2img.h"


XftColor  *XftColors [NXFTCOLORS];

XImage    *revsect_img;
XImage    *eq1sect_img;
XImage    *eq2sect_img;
XImage    *mixsect_img;
XImage    *ambsect_img;
XImage    *redzita_img;
XImage    *sm_img;


RotaryGeom  r_delay;
RotaryGeom  r_xover;
RotaryGeom  r_rtlow;
RotaryGeom  r_rtmid;
RotaryGeom  r_fdamp;
RotaryGeom  r_parfr;
RotaryGeom  r_pargn;
RotaryGeom  r_opmix;
RotaryGeom  r_rgxyz;


void styles_init (X_display *disp, X_resman *xrm)
{
    XftColors [C_MAIN_BG] = disp->alloc_xftcolor (0.25f, 0.25f, 0.25f, 1.0f);
    XftColors [C_MAIN_FG] = disp->alloc_xftcolor (1.0f, 1.0f, 1.0f, 1.0f);

    revsect_img = png2img (SHARED"/revsect.png", disp, XftColors [C_MAIN_BG]);
    eq1sect_img = png2img (SHARED"/eq1sect.png", disp, XftColors [C_MAIN_BG]);
    eq2sect_img = png2img (SHARED"/eq2sect.png", disp, XftColors [C_MAIN_BG]);
    mixsect_img = png2img (SHARED"/mixsect.png", disp, XftColors [C_MAIN_BG]);
    ambsect_img = png2img (SHARED"/ambsect.png", disp, XftColors [C_MAIN_BG]);
    redzita_img = png2img (SHARED"/redzita.png", disp, XftColors [C_MAIN_BG]);
    sm_img      = png2img (SHARED"/sm.png",      disp, XftColors [C_MAIN_BG]);

    if (!revsect_img || !mixsect_img || !ambsect_img
        || !eq1sect_img || !eq2sect_img || !redzita_img || !sm_img)
    {
        fprintf (stderr, "Can't load images from '%s'.\n", SHARED);
        exit (1);
    }

    r_delay._backg = XftColors [C_MAIN_BG];
    r_delay._image [0] = revsect_img;
    r_delay._lncol [0] = 0;
    r_delay._x0 = 30;
    r_delay._y0 = 32;
    r_delay._dx = 23;
    r_delay._dy = 23;
    r_delay._xref = 11.5;
    r_delay._yref = 11.5;
    r_delay._rad = 11;

    r_xover._backg = XftColors [C_MAIN_BG];
    r_xover._image [0] = revsect_img;
    r_xover._lncol [0] = 0;
    r_xover._x0 = 92;
    r_xover._y0 = 17;
    r_xover._dx = 23;
    r_xover._dy = 23;
    r_xover._xref = 11.5;
    r_xover._yref = 11.5;
    r_xover._rad = 11;

    r_rtlow._backg = XftColors [C_MAIN_BG];
    r_rtlow._image [0] = revsect_img;
    r_rtlow._lncol [0] = 0;
    r_rtlow._x0 = 147;
    r_rtlow._y0 = 17;
    r_rtlow._dx = 23;
    r_rtlow._dy = 23;
    r_rtlow._xref = 11.5;
    r_rtlow._yref = 11.5;
    r_rtlow._rad = 11;

    r_rtmid._backg = XftColors [C_MAIN_BG];
    r_rtmid._image [0] = revsect_img;
    r_rtmid._lncol [0] = 0;
    r_rtmid._x0 = 207;
    r_rtmid._y0 = 17;
    r_rtmid._dx = 23;
    r_rtmid._dy = 23;
    r_rtmid._xref = 11.5;
    r_rtmid._yref = 11.5;
    r_rtmid._rad = 11;

    r_fdamp._backg = XftColors [C_MAIN_BG];
    r_fdamp._image [0] = revsect_img;
    r_fdamp._lncol [0] = 0;
    r_fdamp._x0 = 267;
    r_fdamp._y0 = 17;
    r_fdamp._dx = 23;
    r_fdamp._dy = 23;
    r_fdamp._xref = 11.5;
    r_fdamp._yref = 11.5;
    r_fdamp._rad = 11;

    r_parfr._backg = XftColors [C_MAIN_BG];
    r_parfr._image [0] = eq1sect_img;
    r_parfr._lncol [0] = 0;
    r_parfr._x0 = 19;
    r_parfr._y0 = 32;
    r_parfr._dx = 23;
    r_parfr._dy = 23;
    r_parfr._xref = 11.5;
    r_parfr._yref = 11.5;
    r_parfr._rad = 11;

    r_pargn._backg = XftColors [C_MAIN_BG];
    r_pargn._image [0] = eq1sect_img;
    r_pargn._lncol [0] = 1;
    r_pargn._x0 = 68;
    r_pargn._y0 = 17;
    r_pargn._dx = 23;
    r_pargn._dy = 23;
    r_pargn._xref = 11.5;
    r_pargn._yref = 11.5;
    r_pargn._rad = 11;

    r_opmix._backg = XftColors [C_MAIN_BG];
    r_opmix._image [0] = mixsect_img;
    r_opmix._lncol [0] = 0;
    r_opmix._x0 = 23;
    r_opmix._y0 = 32;
    r_opmix._dx = 23;
    r_opmix._dy = 23;
    r_opmix._xref = 11.5;
    r_opmix._yref = 11.5;
    r_opmix._rad = 11;

    r_rgxyz._backg = XftColors [C_MAIN_BG];
    r_rgxyz._image [0] = ambsect_img;
    r_rgxyz._lncol [0] = 0;
    r_rgxyz._x0 = 23;
    r_rgxyz._y0 = 32;
    r_rgxyz._dx = 23;
    r_rgxyz._dy = 23;
    r_rgxyz._xref = 11.5;
    r_rgxyz._yref = 11.5;
    r_rgxyz._rad = 11;
}


void styles_fini (X_display *disp)
{
    revsect_img->data = 0;
    mixsect_img->data = 0;
    ambsect_img->data = 0;
    eq1sect_img->data = 0;
    eq2sect_img->data = 0;
    redzita_img->data = 0;
    XDestroyImage (revsect_img);
    XDestroyImage (mixsect_img);
    XDestroyImage (ambsect_img);
    XDestroyImage (eq1sect_img);
    XDestroyImage (eq2sect_img);
    XDestroyImage (redzita_img);
    XDestroyImage (sm_img);
}
