DFILES := $(shell find . -type f -name "*.df")
HFILES := $(shell find . -type f -name "*.h")
OBJ    := $(DFILES:.df=.o) $(SFILES:.s=.o)

DC      =  ../../../sdk/dragonc.sh
AS      = ../../../sdk/asm.sh
OBJTOOL = ../../../sdk/link.sh
LD      =  $(OBJTOOL) link
SYSTOOL = ../../../sdk/gensyscalls.sh

SYSBINDIR  = ../SystemBin

DCFLAGS = incdir=./include/:../HAL/include

all: $(SYSBINDIR)/OSKernel.exe

$(SYSBINDIR)/OSKernel.exe: $(OBJ) ./Executive/limn2600/OSCallTrampolines.o
	$(LD) $(SYSBINDIR)/OSKernel.exe $(OBJ) ./Executive/limn2600/OSCallTrampolines.o -d HAL.dll:$(SYSBINDIR)/HALLIMNstation.dll $(SYSBINDIR)/Dragonfruit.dll
	$(OBJTOOL) move $(SYSBINDIR)/OSKernel.exe text=0x80001000,data=text+text_size+align,bss=data+data_size+align

Executive/limn2600/OSCallTrampolines.s: ../OSDLL/headers/OSCalls.h 
	$(SYSTOOL) ../OSDLL/headers/OSCalls.h NO ./Executive/limn2600/OSCallTrampolines.s

%.o: %.df $(HFILES) ../HAL/include/*.h
	$(DC) $(DCFLAGS) $< $@

%.o: %.s
	$(AS) $< $@

cleanup:
	rm -f ${OBJ} *.a3x *.LOFF $(SYSBINDIR)/OSKernel.exe
