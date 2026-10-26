/*
 * FUN_0041a810 at 0041a810
 * undefined FUN_0041a810(void)
 * Address ranges: 0041a810-0041a8d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a810(void)

{
  int iVar1;
  
  FUN_00419260();
  FUN_004b1850(0,0,0,s_Select_Racer_004e2244);
  FUN_004b1850(0,0,0x28,s_Current_racer___d_004e2254,DAT_00508618);
  iVar1 = FUN_004b3830(0x1b);
  while (iVar1 == 0) {
    iVar1 = FUN_004b3830(0x6b);
    if (iVar1 != 0) {
      if (DAT_00508618 < 0x13) {
        DAT_00508618 = DAT_00508618 + 1;
      }
      FUN_004b1850(0,0,0x28,s_Current_racer___d_004e2268,DAT_00508618);
      FUN_00419230(0x6b);
    }
    iVar1 = FUN_004b3830(0x6d);
    if (iVar1 != 0) {
      if (0 < DAT_00508618) {
        DAT_00508618 = DAT_00508618 + -1;
      }
      FUN_004b1850(0,0,0x28,s_Current_racer___d_004e2280,DAT_00508618);
      FUN_00419230(0x6d);
    }
    iVar1 = FUN_004b3830(0x1b);
  }
  FUN_00419230(0x1b);
  return;
}

