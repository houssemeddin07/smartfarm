## Process this file with automake to produce Makefile.in
##
##             \
##	ajout.h\
##	annulerajout.h\
##	modifier.h\
##	annulermodifier.h\
##	supprimer.h\
##	annulersupprimer.h\
##	afficher.h\
##
INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project4

project4_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	animaux.c animaux.h


project4_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

