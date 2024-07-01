CORE_DIR := src
TARGET_NAME := mame2003_midway

ifeq ($(platform),)
platform = unix
ifeq ($(shell uname -a),)
   platform = win
else ifneq ($(findstring MINGW,$(shell uname -a)),)
   platform = win
else ifneq ($(findstring Darwin,$(shell uname -a)),)
   platform = osx
else ifneq ($(findstring win,$(shell uname -a)),)
   platform = win
endif
endif

# system platform
system_platform = unix
ifeq ($(shell uname -a),)
	EXE_EXT = .exe
	system_platform = win
else ifneq ($(findstring Darwin,$(shell uname -a)),)
	system_platform = osx
ifeq ($(shell uname -p),powerpc)
	arch = ppc
else
	arch = intel
endif
else ifneq ($(findstring MINGW,$(shell uname -a)),)
	system_platform = win
endif


LIBM := -lm

ifeq ($(platform), unix)
   TARGET = $(TARGET_NAME)_libretro.so
   fpic = -fPIC

   CFLAGS += $(fpic)
   PLATCFLAGS += -Dstricmp=strcasecmp
   LDFLAGS += $(fpic) -shared -Wl,--version-script=link.T

else ifeq ($(platform), linux-portable)
   TARGET = $(TARGET_NAME)_libretro.so
   fpic = -fPIC -nostdlib

   CFLAGS += $(fpic)
   PLATCFLAGS += -Dstricmp=strcasecmp
	LIBM :=
   LDFLAGS += $(fpic) -shared -Wl,--version-script=link.T

else ifeq ($(platform), osx)
   TARGET = $(TARGET_NAME)_libretro.dylib
   fpic = -fPIC
ifeq ($(arch),ppc)
   BIGENDIAN = 1
   PLATCFLAGS += -D__ppc__ -D__POWERPC__
endif
   CFLAGS += $(fpic) -Dstricmp=strcasecmp
   LDFLAGS += $(fpic) -dynamiclib
OSXVER = `sw_vers -productVersion | cut -c 4`
	fpic += -mmacosx-version-min=10.1

# iOS
else ifneq (,$(findstring ios,$(platform)))

   TARGET = $(TARGET_NAME)_libretro_ios.dylib
   fpic = -fPIC
   CFLAGS += $(fpic) -Dstricmp=strcasecmp
   LDFLAGS += $(fpic) -dynamiclib
   PLATCFLAGS += -D__IOS__

ifeq ($(IOSSDK),)
   IOSSDK := $(shell xcodebuild -version -sdk iphoneos Path)
endif

   CC = cc -arch armv7 -isysroot $(IOSSDK)
   LD = cc -arch armv7 -isysroot $(IOSSDK)
ifeq ($(platform),ios9)
   fpic += -miphoneos-version-min=8.0
   CC += -miphoneos-version-min=8.0
   LD += -miphoneos-version-min=8.0
else
   fpic += -miphoneos-version-min=5.0
   CC += -miphoneos-version-min=5.0
   LD += -miphoneos-version-min=5.0
endif

else ifeq ($(platform), ctr)
   TARGET = $(TARGET_NAME)_libretro_$(platform).a
   CC = $(DEVKITARM)/bin/arm-none-eabi-gcc$(EXE_EXT)
   CXX = $(DEVKITARM)/bin/arm-none-eabi-g++$(EXE_EXT)
   AR = $(DEVKITARM)/bin/arm-none-eabi-ar$(EXE_EXT)
   PLATCFLAGS += -DARM11 -D_3DS
   PLATCFLAGS += -march=armv6k -mtune=mpcore -mfloat-abi=hard -mfpu=vfp
   PLATCFLAGS += -Wall -mword-relocations
   PLATCFLAGS += -fomit-frame-pointer -ffast-math
   CXXFLAGS = $(CFLAGS) -fno-rtti -fno-exceptions -std=gnu++11
   CPU_ARCH := arm
   STATIC_LINKING = 1
else ifeq ($(platform), rpi2)
   TARGET = $(TARGET_NAME)_libretro.so
   fpic = -fPIC
   CFLAGS += $(fpic)
   LDFLAGS += $(fpic) -shared -Wl,--version-script=link.T
   PLATCFLAGS += -Dstricmp=strcasecmp
   PLATCFLAGS += -marm -mcpu=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard
   PLATCFLAGS += -fomit-frame-pointer -ffast-math
   CXXFLAGS = $(CFLAGS) -fno-rtti -fno-exceptions
   CPU_ARCH := arm
   ARM = 1
else ifeq ($(platform), rpi3)
   TARGET = $(TARGET_NAME)_libretro.so
   fpic = -fPIC
   CFLAGS += $(fpic)
   LDFLAGS += $(fpic) -shared -Wl,--version-script=link.T
   PLATCFLAGS += -Dstricmp=strcasecmp
   PLATCFLAGS += -marm -mcpu=cortex-a53 -mfpu=neon-fp-armv8 -mfloat-abi=hard
   PLATCFLAGS += -fomit-frame-pointer -ffast-math
   CXXFLAGS = $(CFLAGS) -fno-rtti -fno-exceptions
   CPU_ARCH := arm
   ARM = 1
else ifeq ($(platform), android-armv7)
   TARGET = $(TARGET_NAME)_libretro_android.so

   CFLAGS += -fPIC 
   PLATCFLAGS += -march=armv7-a -mfloat-abi=softfp -Dstricmp=strcasecmp
   LDFLAGS += -fPIC -shared -Wl,--version-script=link.T

   CC = arm-linux-androideabi-gcc
   AR = arm-linux-androideabi-ar
   LD = arm-linux-androideabi-gcc
else ifeq ($(platform), qnx)
   TARGET = $(TARGET_NAME)_libretro_$(platform).so

   CFLAGS += -fPIC 
   PLATCFLAGS += -march=armv7-a -Dstricmp=strcasecmp
   LDFLAGS += -fPIC -shared -Wl,--version-script=link.T

   CC = qcc -Vgcc_ntoarmv7le
   AR = qcc -Vgcc_ntoarmv7le
   LD = QCC -Vgcc_ntoarmv7le

else ifeq ($(platform), wii)
   TARGET = $(TARGET_NAME)_libretro_$(platform).a
   BIGENDIAN = 1
    
   CC = $(DEVKITPPC)/bin/powerpc-eabi-gcc$(EXE_EXT)
   AR = $(DEVKITPPC)/bin/powerpc-eabi-ar$(EXE_EXT)
   PLATCFLAGS += -DGEKKO -mrvl -mcpu=750 -meabi -mhard-float -D__ppc__ -D__POWERPC__ -Dstricmp=strcasecmp
   PLATCFLAGS += -U__INT32_TYPE__ -U __UINT32_TYPE__ -D__INT32_TYPE__=int
   STATIC_LINKING = 1

else ifeq ($(platform), wiiu)
   TARGET = $(TARGET_NAME)_libretro_$(platform).a
   BIGENDIAN = 1
    
   CC = $(DEVKITPPC)/bin/powerpc-eabi-gcc$(EXE_EXT)
   AR = $(DEVKITPPC)/bin/powerpc-eabi-ar$(EXE_EXT)
   PLATCFLAGS += -DGEKKO -DWIIU -D__wiiu__ -DHW_WUP -ffunction-sections -fdata-sections
   PLATCFLAGS += -mcpu=750 -meabi -mhard-float -D__ppc__ -D__POWERPC__ -Dstricmp=strcasecmp
   PLATCFLAGS += -U__INT32_TYPE__ -U __UINT32_TYPE__ -D__INT32_TYPE__=int
   STATIC_LINKING = 1

else ifneq (,$(filter $(platform), ps3 psl1ght))
   TARGET = $(TARGET_NAME)_libretro_$(platform).a
   BIGENDIAN = 1
    
   CC = $(PS3DEV)/ppu/bin/ppu-$(COMMONLV)gcc$(EXE_EXT)
   AR = $(PS3DEV)/ppu/bin/ppu-$(COMMONLV)ar$(EXE_EXT)
   PLATCFLAGS += -D__PS3__ -D__ppc__ -D__POWERPC__ -Dstricmp=strcasecmp
   STATIC_LINKING = 1
   ifeq ($(platform), psl1ght)
        PLATCFLAGS += -D__PSL1GHT__
   endif
else ifeq ($(platform), psp1)
	TARGET = $(TARGET_NAME)_libretro_$(platform).a

	CC = psp-gcc$(EXE_EXT)
	AR = psp-ar$(EXE_EXT)
	PLATCFLAGS += -DPSP -Dstricmp=strcasecmp
	CFLAGS += -G0
   STATIC_LINKING = 1

else ifeq ($(platform), vita)
	TARGET = $(TARGET_NAME)_libretro_$(platform).a

	CC = arm-vita-eabi-gcc$(EXE_EXT)
	AR = arm-vita-eabi-ar$(EXE_EXT)
	PLATCFLAGS += -DVITA -Dstricmp=strcasecmp
	CFLAGS += -mthumb -mfloat-abi=hard -fsingle-precision-constant
	CFLAGS += -Wall -mword-relocations
	CFLAGS += -fomit-frame-pointer -ffast-math
	CFLAGS += -fno-unwind-tables -fno-asynchronous-unwind-tables 
	CFLAGS +=  -fno-optimize-sibling-calls
	CFLAGS += -ftree-vectorize -funroll-loops -fno-short-enums
	CXXFLAGS = $(CFLAGS) -fno-rtti -fno-exceptions
	HAVE_RZLIB := 1
	ARM = 1
	STATIC_LINKING := 1
	SYMBOLS = 0
		
else ifneq (,$(findstring armv,$(platform)))
   TARGET = $(TARGET_NAME)_libretro.so

   CFLAGS += -fPIC
   PLATCFLAGS += -Dstricmp=strcasecmp
   LDFLAGS += -fPIC -shared -Wl,--version-script=link.T

# GCW0
else ifeq ($(platform), gcw0)
	TARGET := $(TARGET_NAME)_libretro.so
	CC = /opt/gcw0-toolchain/usr/bin/mipsel-linux-gcc-4.9.1
	CXX = /opt/gcw0-toolchain/usr/bin/mipsel-linux-g++
	AR = /opt/gcw0-toolchain/usr/bin/mipsel-linux-ar
	LDFLAGS += -shared -Wl,--version-script=link.T -Wl,-no-undefined
	PLATCFLAGS += -Dstricmp=strcasecmp
	LIBS := -lc -lgcc
	fpic := -fPIC -nostdlib
	LIBM :=
	CFLAGS += -lm -march=mips32 -mtune=mips32r2 -mhard-float

else ifeq ($(platform), emscripten)
	TARGET := $(TARGET_NAME)_libretro_$(platform).bc
	HAVE_RZLIB := 1
	STATIC_LINKING := 1
   PLATCFLAGS += -Dstricmp=strcasecmp

# Windows
else
   TARGET := $(TARGET_NAME)_libretro.dll
   CC ?= gcc
   LDFLAGS += -shared -static-libgcc -static-libstdc++ -s -Wl,--version-script=link.T
   CFLAGS += -D__WIN32__ -D__WIN32_LIBRETRO__ -Wno-missing-field-initializers
endif

ifeq ($(BIGENDIAN), 1)
	PLATCFLAGS += -DMSB_FIRST
endif

# use -fsigned-char on ARM to solve potential problems with code written/tested on x86
# eg on mame2003 audio on rtype leo is wrong without it.
ifeq ($(ARM), 1)
   PLATCFLAGS += -fsigned-char
endif

PLATCFLAGS += $(fpic)

CFLAGS += -D__LIBRETRO__ -DPI=3.1415927
LDFLAGS += $(LIBM)

# uncomment next line to include the debugger
# DEBUG = 1

# uncomment next line to include the symbols for symify
# SYMBOLS = 1

# uncomment next line to use Assembler 68000 engine
# X86_ASM_68000 = 1

# uncomment next line to use Assembler 68020 engine
# X86_ASM_68020 = 1

# uncomment next line to use DRC MIPS3 engine
# X86_MIPS3_DRC = 1



# build the targets in different object dirs, since mess changes
# some structures and thus they can't be linked against each other.
DEFS = -Dasm=__asm__

RETRO_PROFILE = 0
CFLAGS += -DRETRO_PROFILE=$(RETRO_PROFILE)

ifneq ($(platform), sncps3)
CFLAGS += -Wall -Wno-sign-compare -Wunused \
	-Wpointer-arith -Wbad-function-cast -Wcast-align -Waggregate-return \
	-Wshadow -Wstrict-prototypes \
	-Wformat-security -Wwrite-strings \
	-Wdisabled-optimization
endif

ifdef SYMBOLS
   CFLAGS += -O0 -Wall -Wno-unused -g

# O3 optimisation causes issues on ARM
else ifeq ($(ARM), 1)
   CFLAGS += -DNDEBUG -O2 -fomit-frame-pointer -fstrict-aliasing

else
   CFLAGS += -DNDEBUG -O3 -fomit-frame-pointer -fstrict-aliasing
endif

# extra options needed *only* for the osd files
CFLAGSOSDEPEND = $(CFLAGS)

# the windows osd code at least cannot be compiled with -pedantic
CFLAGSPEDANTIC = $(CFLAGS) -pedantic

# include the various .mak files
include Makefile.common

CFLAGS += $(INCFLAGS)

# combine the various definitions to one
CDEFS = $(DEFS) $(COREDEFS) $(CPUDEFS) $(SOUNDDEFS) $(ASMDEFS) $(DBGDEFS)

OBJECTS := $(SOURCES_C:.c=.o)

all:	$(TARGET)
$(TARGET): $(OBJECTS)
ifeq ($(STATIC_LINKING),1)
	$(AR) rcs $@ $(foreach OBJECTS,$(OBJECTS),&& $(AR) q $@ $(OBJECTS))
else
	$(CC) $(CDEFS) $(CFLAGSOSDEPEND) $(PLATCFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBS)
endif

%.o: %.c
	$(CC) $(CDEFS) $(CFLAGS) $(PLATCFLAGS) -c -o $@ $<

$(OBJ)/%.a:
	$(RM) $@

clean:
	rm -f $(OBJECTS) $(TARGET)
