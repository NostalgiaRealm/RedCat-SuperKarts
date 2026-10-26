/*
 * FUN_004baac0 at 004baac0
 * undefined FUN_004baac0(void)
 * Address ranges: 004baac0-004bab70
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004baac0(void)

{
  MMRESULT MVar1;
  
  if (DAT_006aba1c != 0) {
    _DAT_006ab988 = 0x34;
    _DAT_006ab98c = 0x83;
    MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_006ab988);
    if (MVar1 == 0) {
      FUN_004ba9d0(1,DAT_006ab990,DAT_006ab994,DAT_006ab9a8);
    }
    else {
      FUN_004ba980(1);
    }
  }
  if (DAT_006aba78 != 0) {
    _DAT_006ab988 = 0x34;
    _DAT_006ab98c = 0x83;
    MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_006ab988);
    if (MVar1 != 0) {
      FUN_004ba980(2);
      return;
    }
    FUN_004ba9d0(2,DAT_006ab990,DAT_006ab994,DAT_006ab9a8);
  }
  return;
}

