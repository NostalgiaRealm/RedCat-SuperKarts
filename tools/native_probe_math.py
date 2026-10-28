"""Original math initialization for instruction probes, matching 0x442fc0."""
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import SCRATCH

TRIG = 0x22000000

def initialize_native_trig(probe, count=4096):
    """Run 0x4a1510; only LocalAlloc is replaced with emulator memory slots.

    0x4ac410 builds the table (0x4ac425) before creating the Direct3D device,
    under the CRT's 53-bit precision (0x4c17bc). Run it at 0x027f for every
    case, then restore the caller's control word for the case itself.
    """
    control = probe.uc.reg_read(UC_X86_REG_FPCW)
    probe.uc.reg_write(UC_X86_REG_FPCW, 0x027f)
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
        probe.uc.reg_write(UC_X86_REG_FPCW, control)
    return TRIG, TRIG + count * 4
