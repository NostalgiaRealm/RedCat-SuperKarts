/*
 * FUN_00429420 at 00429420
 * undefined4 __register FUN_00429420(void)
 * Address ranges: 00429420-00429480
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00429420(void)

{
  BOOL BVar1;
  uint uVar2;
  HWND in_stack_00000004;
  
  if ((in_stack_00000004 != DAT_0047b6bc) && (in_stack_00000004 != *(HWND *)(DAT_0047d770 + 0x24)))
  {
    BVar1 = IsWindowVisible(in_stack_00000004);
    if (BVar1 != 0) {
      BVar1 = IsWindowEnabled(in_stack_00000004);
      if (BVar1 != 0) {
        uVar2 = GetWindowLongA(in_stack_00000004,-0x14);
        if ((uVar2 & 8) == 0) {
          if (DAT_0047b6c0 == (HWND)0x0) {
            DAT_0047b6c0 = in_stack_00000004;
          }
        }
        else if (DAT_0047b6c4 == (HWND)0x0) {
          DAT_0047b6c4 = in_stack_00000004;
        }
      }
    }
  }
  return 0xffffffff;
}

