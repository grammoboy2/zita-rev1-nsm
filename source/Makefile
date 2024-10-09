# ----------------------------------------------------------------------------
#
#  Copyright (C) 2009-2018 Fons Adriaensen <fons@linuxaudio.org>
#    
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# ----------------------------------------------------------------------------


PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
SHARED ?= $(PREFIX)/share/zita-rev1

VERSION = 0.2.2
CPPFLAGS += -MMD -MP -DVERSION=\"$(VERSION)\" -DSHARED=\"$(SHARED)\"
CXXFLAGS += -O2 -Wall -ffast-math -pthread
CXXFLAGS += -march=native


all:	zita-rev1


ZITA-REV1_O = zita-rev1.o styles.o jclient.o mainwin.o png2img.o guiclass.o rotary.o reverb.o pareq.o nsm.o nsmclient.o
zita-rev1:	CPPFLAGS += $(shell pkgconf --cflags freetype2)
zita-rev1:	LDLIBS += -lclxclient -lclthreads -lpng -lcairo -ljack -lpthread -lXft -lX11 -lrt -llo -lpthread

zita-rev1:	$(ZITA-REV1_O) 
	$(CXX) $(LDFLAGS) -o $@ $(ZITA-REV1_O) $(LDLIBS)
$(ZITA-REV1_O):
-include $(ZITA-REV1_O:%.o=%.d)



install:	all
	install -d $(DESTDIR)$(BINDIR)
	install -d $(DESTDIR)$(SHARED)
	install -m 755 zita-rev1 $(DESTDIR)$(BINDIR)
	ln -s $(DESTDIR)$(BINDIR)/zita-rev1 $(DESTDIR)$(BINDIR)/zita-rev1-amb
	rm -rf $(DESTDIR)$(SHARED)/*
	install -m 644 ../share/* $(DESTDIR)$(SHARED)
	install -Dm644 -t $(PREFIX)/share/applications/ ../zita-rev1.desktop

uninstall:
	rm -f  $(DESTDIR)$(BINDIR)/zita-rev1
	rm -f  $(DESTDIR)$(BINDIR)/zita-rev1-amb
	rm -rf $(DESTDIR)$(SHARED)
	rm -f $(PREFIX)/share/applications/zita-rev1.desktop


clean:
	/bin/rm -f *~ *.o *.a *.d *.so
	/bin/rm -f zita-rev1

