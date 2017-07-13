AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = xing
xing_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

xing_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(XQN_CPPFLAGS) \
		$(AIR_CPPFLAGS)


xing_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(XQN_LIBADD) \
	$(AIR_LIBADD)


xing_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh \
	Server.hh \
	Log.hh

EXTRA_DIST = env.sh xing.cfg log.cfg

xingdir = $(bindir)
xing_DATA = $(EXTRA_DIST)

