/*
 * FUN_00418c41 at 00418c41
 * undefined __stdcall FUN_00418c41(void)
 * Address ranges: 00418c41-00418d08
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00418c41(void)

{
  MMRESULT MVar1;
  
  if (DAT_0043dd44 != 0) {
    _DAT_0043dcb0 = 0x34;
    _DAT_0043dcb4 = 0x83;
    MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_0043dcb0);
    if (MVar1 == 0) {
      FUN_00418ad8(1,DAT_0043dcb8,DAT_0043dcbc,DAT_0043dcd0);
    }
    else {
      FUN_00418a53(1);
    }
  }
  if (DAT_0043dda0 != 0) {
    _DAT_0043dcb0 = 0x34;
    _DAT_0043dcb4 = 0x83;
    MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_0043dcb0);
    if (MVar1 == 0) {
      FUN_00418ad8(2,DAT_0043dcb8,DAT_0043dcbc,DAT_0043dcd0);
    }
    else {
      FUN_00418a53(2);
    }
  }
  return;
}

