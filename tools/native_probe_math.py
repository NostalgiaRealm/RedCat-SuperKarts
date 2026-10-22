"""Original math initialization for instruction probes, matching 0x442fc0."""
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import SCRATCH

TRIG = 0x22000000

def initialize_native_trig(probe, count=4096):
    """Run 0x4a1510; only LocalAlloc is replaced with emulator memory slots."""
    probe.uc.mem_map(TRIG, ((count * 8 + 4095) // 4096) * 4096)
    pe = pefile.PE(str(probe.source / 'rcskspel.dat'))
    allocator = next(i.address for library in pe.DIRECTORY_ENTRY_IMPORT for i in library.imports if i.name == b'LocalAlloc')
    previous = bytes(probe.uc.mem_read(allocator, 4))
    probe.u32(allocator, SCRATCH + 0x3000)
    slots = iter([TRIG, TRIG + count * 4])
    def hook(uc, address, size, data):
        if address != SCRATCH + 0x3000:
            return
        stack = uc.reg_read(UC_X86_REG_ESP)
        uc.reg_write(UC_X86_REG_EAX, next(slots))
        uc.reg_write(UC_X86_REG_ESP, stack + 12)
        uc.reg_write(UC_X86_REG_EIP, probe.integer(stack))
    handle = probe.uc.hook_add(UC_HOOK_CODE, hook)
    try:
        probe.run(0x4a1510, [count])
        if probe.uc.reg_read(UC_X86_REG_EIP) != SCRATCH:
            probe.uc.emu_start(probe.uc.reg_read(UC_X86_REG_EIP), SCRATCH, count=1000000)
        assert probe.uc.reg_read(UC_X86_REG_EIP) == SCRATCH, 'Native math initialization did not return'
    finally:
        probe.uc.hook_del(handle)
        probe.uc.mem_write(allocator, previous)
    return TRIG, TRIG + count * 4
