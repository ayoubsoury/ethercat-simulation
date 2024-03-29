#
# OMNeT++/OMNEST Makefile for EtherCat
#
# This file was generated with the command:
#  opp_makemake -f --deep
#

# Name of target to be created (-o option)
TARGET = EtherCat$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = -I. -Iapplicationlayer -Idatalinklayer -Iphysicallayer -Iresults

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/applicationlayer/MasterApplication.o \
    $O/applicationlayer/SlaveApplication.o \
    $O/datalinklayer/EtherCatMACMaster.o \
    $O/datalinklayer/EtherCatMACSlave.o \
    $O/applicationlayer/EtherCatFrame_m.o \
    $O/datalinklayer/EthernetFrame_m.o

# Message files
MSGFILES = \
    applicationlayer/EtherCatFrame.msg \
    datalinklayer/EthernetFrame.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f EtherCat EtherCat.exe libEtherCat.so libEtherCat.a libEtherCat.dll libEtherCat.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f applicationlayer/*_m.cc applicationlayer/*_m.h
	-rm -f datalinklayer/*_m.cc datalinklayer/*_m.h
	-rm -f physicallayer/*_m.cc physicallayer/*_m.h
	-rm -f results/*_m.cc results/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc applicationlayer/*.cc datalinklayer/*.cc physicallayer/*.cc results/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/applicationlayer/EtherCatFrame_m.o: applicationlayer/EtherCatFrame_m.cc \
	applicationlayer/EtherCatFrame_m.h
$O/applicationlayer/MasterApplication.o: applicationlayer/MasterApplication.cc \
	applicationlayer/EtherCatFrame_m.h \
	applicationlayer/MasterApplication.h
$O/applicationlayer/SlaveApplication.o: applicationlayer/SlaveApplication.cc \
	applicationlayer/EtherCatFrame_m.h \
	applicationlayer/SlaveApplication.h
$O/datalinklayer/EtherCatMACMaster.o: datalinklayer/EtherCatMACMaster.cc \
	datalinklayer/EtherCatMACMaster.h \
	datalinklayer/EthernetFrame_m.h
$O/datalinklayer/EtherCatMACSlave.o: datalinklayer/EtherCatMACSlave.cc \
	datalinklayer/EtherCatMACSlave.h \
	datalinklayer/EthernetFrame_m.h
$O/datalinklayer/EthernetFrame_m.o: datalinklayer/EthernetFrame_m.cc \
	datalinklayer/EthernetFrame_m.h

