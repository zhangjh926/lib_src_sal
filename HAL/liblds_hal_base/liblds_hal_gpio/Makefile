# Get Linux Build Enviornment:
include ../../../Platform.env

ifndef BUILD_VERBOSE
	BUILD_VERBOSE = 0
	Q = @
endif

export BUILD_VERBOSE Q

########################################################
ifndef PROJ_HOME

PROJ_HOME	= `pwd`
TOP		=   $(OUTPUT_HAL_BASE_PREFIX)

CC		=	$(CROSS_TOOL)gcc
LD		=	$(CROSS_TOOL)ld
AR		=	$(CROSS_TOOL)ar cqs
STRIP	=	$(CROSS_TOOL)strip

CP		=	@cp -f
RM		=	@rm -f
LN		=	@ln -sf
ECHO	=	@echo
CTAG	=	@ctags -R


TARGET_DIR = $(TOP)/HAL/lib/

INCPATH   = -I./
INCPATH  += -I$(TOP)/HAL/include
INCPATH  += -I../../

endif
########################################################
########################################################
TARGET	=	liblds_hal_gpio

########################################################
#DEFINES += -DDEBUG

########################################################

CFLAGS  += -pipe -O2 -fPIC $(INCPATH) $(DEFINES) -D$(SYSTEM) -D$(PLATFORM)
#CFLAGS  += -pipe -Wall $(INCPATH) $(DEFINES)
LFLAGS	+= $(LIBDIR) $(LIBS)

########################################################

$(warning $(SYSTEM) )
$(warning $(PLATFORM) )
##########    Files    ##########
ifeq ($(SYSTEM), LINUX)
OBJECTS =	linux/liblds_hal_gpio_linux.o
else
OBJECTS =	rtos/liblds_hal_gpio_rtos.o
endif

HEADERS	=	liblds_hal_gpio_base.h \
			

######### Implicit rules #########
.SUFFIXES: .cpp .cxx .cc .C .c

.c.o:
ifeq ($(BUILD_VERBOSE),0)
	$(ECHO)		"Compiling.....   [$<]"
endif
	$(Q)$(CC)	-c $(CFLAGS) -o $@ $<

########## Build rules ##########
all:    $(TARGET) install

$(TARGET) : $(OBJECTS)
ifeq ($(BUILD_VERBOSE),0)
	$(ECHO)		"Making........   [$@]"
endif
	$(Q)$(AR)	$(LFLAGS) $(TARGET).a $(OBJECTS)
	$(Q)$(CC) 	-shared -o $(TARGET).so $(OBJECTS)

install:	$(TARGET)
	#$(CP)		$(TARGET).a $(TARGET_DIR)
	$(STRIP)	$(TARGET).so
	$(CP)		$(TARGET).so $(TARGET_DIR)
	$(CP)		$(HEADERS) $(TOP)/HAL/include
	$(CP)		$(OBJECTS) $(TOP)/HAL/obj
	@echo 		"Install.......	[OK]"

clean:
	$(RM)		$(OBJECTS) $(TARGET) *~ tags *.so *.a *.dpend
	$(ECHO)		"Cleaning......   [OK]"

