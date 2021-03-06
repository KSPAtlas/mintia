#include "../LoaderGlobal.h"

extern ArgsInit { argp -- }
extern ArgsValue { arg -- out }
extern ArgsCheck { arg -- present }

extern LoaderPanic { ... fmt -- }

extern ResourceLoadAll { -- ok }

extern AFSInit { -- }
extern AFSExit { -- }
extern AFSMount { dev -- ok }
extern AFSRead { buf len seek ino -- bytes }
extern AFSPath { path -- ino }
extern AFSFreeINode { ino -- }
extern AFSINodeSize { ino -- sz }
extern AFSINodeExecutable { ino -- isexecutable }

extern MemInit { -- }
extern MemAlloc { pages pstart -- astart ok }
extern MemFree { pages pstart -- }
extern MemExit { -- }
extern MemAllocUpper { pages vstart must -- astart ok }
extern MemMapIORange { pages phys -- vaddr ok }

extern LOFFLoad { path loff -- ok }
extern LOFFGetString { loff offset -- str }

extern DriverLoadNode { -- }
extern DriverLoad { name -- dll }
extern DriverLoadAll { -- ok }

struct LOFFHeader
	4 Magic
	4 SymbolTableOffset
	4 SymbolCount
	4 StringTableOffset
	4 StringTableSize
	4 TargetArchitecture
	4 EntrySymbol
	4 Stripped
	4 ImportTableOffset
	4 ImportCount
	4 Timestamp
	4 Fragment
	12 Reserved2
	4 TextHeader
	4 DataHeader
	4 BSSHeader
endstruct

struct LOFFSectionHeader
	4 FixupTableOffset
	4 FixupCount
	4 SectionOffset
	4 SectionSize
	4 LinkedAddress
endstruct

struct LOFFImport
	4 Name
	4 ExpectedText
	4 ExpectedData
	4 ExpectedBSS
	4 Timestamp
endstruct

struct LOFFFixup
	4 SymbolIndex
	4 Offset
	4 Type
endstruct

const LOFFGLOBAL 1
const LOFFEXTERN 3
const LOFFRESOLVED 256

const INITBITMAPSZ 8192

const KERNELSPACE      0x80000000
const KERNELSTRUCTURES 0xA0000000
const POOLSPACE        0xBEF00000
const IDENTITYSPACE    0xC0000000

const IDENTITYSPACEMASK (IDENTITYSPACE ~)

const PFDBBASE (KERNELSTRUCTURES 0x200000 +)
const HEAPBASE (KERNELSTRUCTURES 0x400000 +)

extern DLLLoad { name -- dll ok }
extern DLLResolveAll { -- ok }
extern DLLRelocateAll { -- ok }
extern DLLGetSymbolAddress { dll name -- address }
extern DLLLoadPrefix { prefix name -- dll ok }

externptr LoaderEntrypoint
externptr LoaderTotalRAM
externptr LoaderHALName
externptr LoaderBootDiskName
externptr AFSDevice
externptr MemBitmap
externptr DLLListHead
externptr ArgsBuffer
externptr ResourceListHead
externptr DLLForceRelink
externptr MemPageFrameDB
externptr MemHeap
externptr MemHeapSize
externptr MemPageDirectory

struct AFSSuperblock
	4 Version
	4 Magic
	4 Dirty
	4 NumReservedBlocks
	4 FATStart
	4 FATSize
	4 IStart
	4 ICount
	4 DataStart
	4 DataSize
endstruct

struct AFSDirEnt
	4 INum
	60 Name
endstruct

struct AFSINode
	4 Type
	4 Permissions
	4 UID
	4 Reserved1
	4 Timestamp
	4 StartBlock
	4 Reserved2
	4 Size
endstruct

const PAGESIZE 4096
const PAGEOFFSETMASK (PAGESIZE 1 -)
const PAGENUMBERMASK (PAGEOFFSETMASK ~)
const PAGESHIFT 12