const OSPAGESIZE 4096

const OSPEB     0x7FFE0000
const OSPEBSIZE OSPAGESIZE

const OSDLLHEAD 0x7FEE0000

const USTACKS   0x7FCE0000 // preferred, to keep them out of the way
const USTACKSZ  131072

const PAGEACCESS_EXEC      1
const PAGEACCESS_WRITE     2
const PAGEACCESS_READ      4
const PAGEACCESS_WRITECOPY 8
const PAGEACCESS_NONCACHED 16

const PAGEACCESS_ALL (PAGEACCESS_EXEC PAGEACCESS_WRITE | PAGEACCESS_READ |)

const OSMAPFLAG_FIXEDADDRESS 1