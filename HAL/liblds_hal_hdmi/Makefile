########################################################################
# Get Linux Build Enviornment:
include ../../Platform.env

TOPDIR   	:= $(OUTPUT_HAL_ROOT_PREFIX)

Q = @
export Q

LIBSDIR	 	:= $(TOPDIR)/
LIB_INSTALL	:= $(LIBSDIR)/HAL/lib
INC_INSTALL	:= $(LIBSDIR)/HAL/include
OBJ_INSTALL := $(LIBSDIR)/HAL/obj

# Build options
INCLUDE += -I./ -I$(INC_INSTALL)
INCLUDE += -I../
LIBRARY += -L$(LIB_INSTALL)

######################################################################
# Target
$(warning $(SYSTEM) )
$(warning $(PLATFORM) )
##########    Files    ##########
ifeq ($(SYSTEM), LINUX)
COBJS  	:= 
COBJS  	+= linux/liblds_hal_hdmi_linux.o
CPPOBJS	:=  
else
COBJS  	:= 
COBJS  	+= linux/liblds_hal_hdmi_rtos.o
CPPOBJS	:=
endif

CFLAGS	+= -g -O2 -fpic $(INCLUDE) -D$(SYSTEM) -D$(PLATFORM)

TARGET	:= liblds_hal_hdmi
INC_FILE := liblds_hal_hdmi_base

######################################################################
# Build
OBJS	:= $(COBJS) $(CPPOBJS)

all: $(TARGET)

$(TARGET): depend $(OBJS)
	$(Q)$(AR) $(ARFLAGS) $(TARGET).a $(OBJS)
	$(Q)$(CC) -shared -o $(TARGET).so $(OBJS)
	install -m 755 -d $(LIB_INSTALL)
	#install -m 644 $(TARGET).a $(LIB_INSTALL)
	install -m 644 $(TARGET).so $(LIB_INSTALL)
	install -m 644 $(INC_FILE).h $(INC_INSTALL)
	install -m 644 $(COBJS) $(CPPOBJS) $(OBJ_INSTALL)

clean:
	rm -f linux/*.o rtos/*.o *.so *.a *.bak .depend

distclean: clean
	rm -f $(LIB_INSTALL)/$(TARGET).a
	rm -f $(INC_INSTALL)/$(INC_FILE).h

#########################################################################
# Dependency
ifeq (.depend,$(wildcard .depend))
include .depend
endif

SRCS := $(COBJS:.o=.c) $(CPPOBJS:.o=.cpp) $(APPOBJS:.o=.c)
INCS := $(INCLUDE)
depend dep:
	$(Q)$(CC)  -M  $(CFLAGS)   $(INCS) $(SRCS) > .depend

