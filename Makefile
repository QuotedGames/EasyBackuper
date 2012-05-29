#############################################################################
# Makefile for building: EasyBackuper.app/Contents/MacOS/EasyBackuper
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue May 29 14:40:41 2012
# Project:  EasyBackuper.pro
# Template: app
# Command: /Users/gershengoren/Downloads/qt-everywhere-opensource-src-4.8.1/bin/qmake -spec /usr/local/Trolltech/Qt-4.8.1/mkspecs/macx-g++ CONFIG+=declarative_debug -o Makefile EasyBackuper.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.8.1/mkspecs/macx-g++ -I. -I/usr/local/Trolltech/Qt-4.8.1/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.8.1/include/QtCore -I/usr/local/Trolltech/Qt-4.8.1/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.8.1/include/QtGui -I/usr/local/Trolltech/Qt-4.8.1/include -I. -I. -F/usr/local/Trolltech/Qt-4.8.1/lib
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/usr/local/Trolltech/Qt-4.8.1/lib -L/usr/local/Trolltech/Qt-4.8.1/lib -framework QtGui -L/usr/local/Trolltech/Qt-4.8.1/lib -F/usr/local/Trolltech/Qt-4.8.1/lib -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /Users/gershengoren/Downloads/qt-everywhere-opensource-src-4.8.1/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		profilewidget.cpp \
		ebprofile.cpp \
		ebdialogprofile.cpp moc_mainwindow.cpp \
		moc_profilewidget.cpp \
		moc_ebprofile.cpp \
		moc_ebdialogprofile.cpp \
		qrc_Icons.cpp
OBJECTS       = main.o \
		mainwindow.o \
		profilewidget.o \
		ebprofile.o \
		ebdialogprofile.o \
		moc_mainwindow.o \
		moc_profilewidget.o \
		moc_ebprofile.o \
		moc_ebdialogprofile.o \
		qrc_Icons.o
DIST          = /usr/local/Trolltech/Qt-4.8.1/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/mac.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/g++-macx.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/x86_64.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/objective_c.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/declarative_debug.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/rez.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/sdk.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/include_source_dir.prf \
		EasyBackuper.pro
QMAKE_TARGET  = EasyBackuper
DESTDIR       = 
TARGET        = EasyBackuper.app/Contents/MacOS/EasyBackuper

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile EasyBackuper.app/Contents/PkgInfo EasyBackuper.app/Contents/Resources/empty.lproj EasyBackuper.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_mainwindow.h ui_profilewidget.h ui_ebdialogprofile.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) EasyBackuper.app/Contents/MacOS/ || $(MKDIR) EasyBackuper.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: EasyBackuper.pro  /usr/local/Trolltech/Qt-4.8.1/mkspecs/macx-g++/qmake.conf /usr/local/Trolltech/Qt-4.8.1/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/mac.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/g++-macx.conf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/x86_64.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/objective_c.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/declarative_debug.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/rez.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/sdk.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/Qt-4.8.1/lib/QtGui.framework/QtGui.prl \
		/usr/local/Trolltech/Qt-4.8.1/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.1/mkspecs/macx-g++ CONFIG+=declarative_debug -o Makefile EasyBackuper.pro
/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/mac.conf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/gcc-base.conf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/gcc-base-macx.conf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/g++-base.conf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/common/g++-macx.conf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/default_pre.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/dwarf2.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/debug.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/default_post.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/x86_64.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/objective_c.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/declarative_debug.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/rez.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/mac/sdk.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.8.1/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/Qt-4.8.1/lib/QtGui.framework/QtGui.prl:
/usr/local/Trolltech/Qt-4.8.1/lib/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.1/mkspecs/macx-g++ CONFIG+=declarative_debug -o Makefile EasyBackuper.pro

EasyBackuper.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) EasyBackuper.app/Contents || $(MKDIR) EasyBackuper.app/Contents 
	@$(DEL_FILE) EasyBackuper.app/Contents/PkgInfo
	@echo "APPL????" >EasyBackuper.app/Contents/PkgInfo
EasyBackuper.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) EasyBackuper.app/Contents/Resources || $(MKDIR) EasyBackuper.app/Contents/Resources 
	@touch EasyBackuper.app/Contents/Resources/empty.lproj
	
EasyBackuper.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) EasyBackuper.app/Contents || $(MKDIR) EasyBackuper.app/Contents 
	@$(DEL_FILE) EasyBackuper.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,EasyBackuper,g" -e "s,@TYPEINFO@,????,g" /usr/local/Trolltech/Qt-4.8.1/mkspecs/macx-g++/Info.plist.app >EasyBackuper.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/EasyBackuper1.0.0 || $(MKDIR) .tmp/EasyBackuper1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/EasyBackuper1.0.0/ && $(COPY_FILE) --parents mainwindow.h profilewidget.h ebprofile.h ebdialogprofile.h .tmp/EasyBackuper1.0.0/ && $(COPY_FILE) --parents Icons.qrc .tmp/EasyBackuper1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp profilewidget.cpp ebprofile.cpp ebdialogprofile.cpp .tmp/EasyBackuper1.0.0/ && $(COPY_FILE) --parents mainwindow.ui profilewidget.ui ebdialogprofile.ui .tmp/EasyBackuper1.0.0/ && (cd `dirname .tmp/EasyBackuper1.0.0` && $(TAR) EasyBackuper1.0.0.tar EasyBackuper1.0.0 && $(COMPRESS) EasyBackuper1.0.0.tar) && $(MOVE) `dirname .tmp/EasyBackuper1.0.0`/EasyBackuper1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/EasyBackuper1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r EasyBackuper.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp moc_profilewidget.cpp moc_ebprofile.cpp moc_ebdialogprofile.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_profilewidget.cpp moc_ebprofile.cpp moc_ebdialogprofile.cpp
moc_mainwindow.cpp: profilewidget.h \
		mainwindow.h
	/usr/local/Trolltech/Qt-4.8.1/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

moc_profilewidget.cpp: profilewidget.h
	/usr/local/Trolltech/Qt-4.8.1/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ profilewidget.h -o moc_profilewidget.cpp

moc_ebprofile.cpp: ebprofile.h
	/usr/local/Trolltech/Qt-4.8.1/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ ebprofile.h -o moc_ebprofile.cpp

moc_ebdialogprofile.cpp: ebdialogprofile.h
	/usr/local/Trolltech/Qt-4.8.1/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ ebdialogprofile.h -o moc_ebdialogprofile.cpp

compiler_rcc_make_all: qrc_Icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Icons.cpp
qrc_Icons.cpp: Icons.qrc \
		Resources/stop.png \
		Resources/play.png \
		Resources/pause.png \
		Resources/plus.png
	/usr/local/Trolltech/Qt-4.8.1/bin/rcc -name Icons Icons.qrc -o qrc_Icons.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_profilewidget.h ui_ebdialogprofile.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_profilewidget.h ui_ebdialogprofile.h
ui_mainwindow.h: mainwindow.ui
	/usr/local/Trolltech/Qt-4.8.1/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_profilewidget.h: profilewidget.ui
	/usr/local/Trolltech/Qt-4.8.1/bin/uic profilewidget.ui -o ui_profilewidget.h

ui_ebdialogprofile.h: ebdialogprofile.ui
	/usr/local/Trolltech/Qt-4.8.1/bin/uic ebdialogprofile.ui -o ui_ebdialogprofile.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		profilewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		profilewidget.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

profilewidget.o: profilewidget.cpp profilewidget.h \
		ui_profilewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o profilewidget.o profilewidget.cpp

ebprofile.o: ebprofile.cpp ebprofile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ebprofile.o ebprofile.cpp

ebdialogprofile.o: ebdialogprofile.cpp ebdialogprofile.h \
		ui_ebdialogprofile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ebdialogprofile.o ebdialogprofile.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_profilewidget.o: moc_profilewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_profilewidget.o moc_profilewidget.cpp

moc_ebprofile.o: moc_ebprofile.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ebprofile.o moc_ebprofile.cpp

moc_ebdialogprofile.o: moc_ebdialogprofile.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ebdialogprofile.o moc_ebdialogprofile.cpp

qrc_Icons.o: qrc_Icons.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Icons.o qrc_Icons.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

