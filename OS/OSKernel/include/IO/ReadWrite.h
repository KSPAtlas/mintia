extern IOFileSeek { offset handle mode -- newoffset ok }

extern IOFileRead { timeout flags length buffer filehandle -- bytesread ok }
extern IOFileReadProcess { timeout flags length buffer fileobject process -- bytesread ok }

extern IOFileWrite { flags length buffer filehandle -- byteswritten ok }
extern IOFileWriteProcess { flags length buffer fileobject process -- byteswritten ok }