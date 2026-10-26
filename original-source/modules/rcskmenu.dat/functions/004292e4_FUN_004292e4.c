/*
 * FUN_004292e4 at 004292e4
 * undefined FUN_004292e4(void)
 * Address ranges: 004292e4-00429330
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004292e4(void)

{
  BOOL BVar1;
  undefined4 *puVar2;
  HWND in_stack_00000004;
  
  if (in_stack_00000004 != DAT_0047b6bc) {
    BVar1 = IsWindowVisible(in_stack_00000004);
    if (BVar1 != 0) {
      BVar1 = IsWindowEnabled(in_stack_00000004);
      if (BVar1 != 0) {
        puVar2 = (undefined4 *)FUN_00402714(8);
        *puVar2 = DAT_0047b6c8;
        puVar2[1] = in_stack_00000004;
        DAT_0047b6c8 = puVar2;
        EnableWindow(in_stack_00000004,0);
      }
    }
  }
  return 0xffffffff;
}

