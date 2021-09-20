fnptr IOFilesystemMountFunction { mount -- ok }
fnptr IOFilesystemUnmountFunction { mount -- ok }
fnptr IOFilesystemFlushFunction { mount -- ok }
fnptr IOFilesystemUpdateFlagsFunction { newflags oldflags mount -- ok }

struct IOFilesystem
	4 Next
	4 Reserved0 // leave room for a prev link just in case

	4 Name
	4 DispatchTable

	4 MountFunction
	4 UnmountFunction
	4 FlushFunction
	4 UpdateFlagsFunction
	4 Flags

	4 Reserved1
	4 Reserved2
	4 Reserved3
	4 Reserved4
	4 Reserved5
	4 Reserved6
	4 Reserved7
endstruct

struct IOMount
	4 Next
	4 Prev

	4 FSContext
	4 Filesystem
	4 VolumeFile
	4 RootFCB
	4 Flags
	4 BlockSize

	4 Reserved1
	4 Reserved2
	4 Reserved3
	4 Reserved4
	4 Reserved5
	4 Reserved6
	4 Reserved7
endstruct

const IOFSFLAG_NOAUTO 1

extern IOFilesystemRegister { filesystem -- ok }

extern IOFilesystemMount { flags handle fsname -- mount ok }
extern IOMountObject { flags fileobject fsname -- mount ok }

extern IOFilesystemUnmount { handle -- ok }
extern IOUnmountObject { fileobject -- ok }

extern IOFilesystemSyncAll { -- ok }

externptr IOMountListMutex