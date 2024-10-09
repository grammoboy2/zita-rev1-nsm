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


#ifndef __STYLES_H
#define __STYLES_H

#include <clxclient.h>
#include "rotary.h"


enum
{
    C_MAIN_BG, C_MAIN_FG,
    NXFTCOLORS
};

enum
{
    NXFTFONTS
};


extern void styles_init (X_display *disp, X_resman *xrm);
extern void styles_fini (X_display *disp);

extern XftColor  *XftColors [NXFTCOLORS];
//extern XftFont   *XftFonts [NXFTFONTS];

extern X_textln_style tstyle1;

extern XImage    *revsect_img;
extern XImage    *eq1sect_img;
extern XImage    *eq2sect_img;
extern XImage    *mixsect_img;
extern XImage    *ambsect_img;
extern XImage    *redzita_img;
extern XImage    *sm_img;


extern RotaryGeom  r_delay;
extern RotaryGeom  r_xover;
extern RotaryGeom  r_rtlow;
extern RotaryGeom  r_rtmid;
extern RotaryGeom  r_fdamp;
extern RotaryGeom  r_parfr;
extern RotaryGeom  r_pargn;
extern RotaryGeom  r_opmix;
extern RotaryGeom  r_rgxyz;


#endif
