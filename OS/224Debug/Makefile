DFILES := $(shell find . -type f -name "*.df")
SFILES := $(shell find . -type f -name "*.s")
OBJ    := $(DFILES:.df=.o) $(SFILES:.s=.o)

DC      =  ../../../sdk/dragonc.sh
AS      = ../../../sdk/asm.sh
OBJTOOL = ../../../sdk/link.sh
LD      =  $(OBJTOOL) link

SYSBINDIR  = ../SystemBin

DCFLAGS = incdir=../HAL/include/:../OSKernel/include/:./include/

all: $(SYSBINDIR)/224Debug.exe

$(SYSBINDIR)/224Debug.exe: $(OBJ)
	$(LD) $(SYSBINDIR)/224Debug.exe $(OBJ) -d $(SYSBINDIR)/OSKernel.exe HAL.dll:$(SYSBINDIR)/HALLIMNstation.dll $(SYSBINDIR)/Dragonfruit.dll
	$(OBJTOOL) move $(SYSBINDIR)/224Debug.exe text=0x80600000,data=text+text_size+align,bss=data+data_size+align

%.o: %.df ../HAL/include/*.h ../OSKernel/include/*.h
	$(DC) $(DCFLAGS) $< $@

%.o: %.s
	$(AS) $< $@

cleanup:
	rm -f ${OBJ} *.a3x *.LOFF $(SYSBINDIR)/224Debug.exe