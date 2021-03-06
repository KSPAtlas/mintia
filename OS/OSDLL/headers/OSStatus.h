const STATUS_SUCCESS                0
const STATUS_ROLE_ALREADY_HELD     -1
const STATUS_NO_MEMORY             -2
const STATUS_QUOTA_EXCEEDED        -3
const STATUS_KERNEL_APC            -4
const STATUS_USER_APC              -5
const STATUS_WAIT_TIMEOUT          -6
const STATUS_INVALID_HANDLE        -7
const STATUS_DEADLOCK_POSSIBLE     -8
const STATUS_INVALID_ARGUMENT      -9
const STATUS_INVALID_OBJECT_TYPE   -10
const STATUS_NO_SUCH_USER          -11
const STATUS_PERMISSION_DENIED     -12
const STATUS_SIGNALLED             -13
const STATUS_KILLED                -14
const STATUS_FORBIDDEN_OPERATION   -15
const STATUS_NAME_TOO_LONG         -16
const STATUS_NOT_A_DIRECTORY       -17
const STATUS_NOT_FOUND             -18
const STATUS_IO_NOT_SUPPORTED      -19
const STATUS_BUFFER_MAXIMUM        -20
const STATUS_IO_NOT_AVAILABLE      -21
const STATUS_IS_A_DIRECTORY        -22
const STATUS_IO_END_OF_DISK        -23
const STATUS_IO_END_OF_FILE        -24
const STATUS_IO_TRY_AGAIN_LATER    -25
const STATUS_IO_DEVICE_BUSY        -26
const STATUS_IO_BAD_FILESYSTEM     -27
const STATUS_IO_NO_SUCH_FILESYSTEM -28
const STATUS_READONLY_FILESYSTEM   -29
const STATUS_UNAVAILABLE_ADDRESS   -30
const STATUS_OVERFLOW              -31
const STATUS_BAD_ADDRESS           -32
const STATUS_FAULT                 -33
const STATUS_NOT_IMPLEMENTED       -34
const STATUS_NOT_CORRECT_FILETYPE  -35
const STATUS_IO_UNALIGNED          -36
const STATUS_VM_QUOTA_EXCEEDED     -37
const STATUS_BAD_EXECUTABLE        -38
const STATUS_EXEC_NOT_FOR_ARCH     -39
const STATUS_NO_SYMBOL             -40
const STATUS_SWAP_TOO_SMALL        -41
const STATUS_NO_SWAP               -42

extern OSStatusGetName { status -- name }