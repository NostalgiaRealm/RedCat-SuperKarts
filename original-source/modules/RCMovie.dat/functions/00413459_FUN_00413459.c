/*
 * FUN_00413459 at 00413459
 * undefined4 __cdecl FUN_00413459(uint param_1, uint param_2)
 * Address ranges: 00413459-004134fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00413459(uint param_1,uint param_2)

{
  SHORT SVar1;
  int iVar2;
  
  if (((int)param_2 < 0) || (3 < (int)param_2)) {
    FUN_0040187a((byte *)s__keyispressed__illegal_device_re_00434c20);
  }
  if (((param_2 & 2) != 0) && (iVar2 = FUN_004191a1(param_1), iVar2 != 0)) {
    return 0xffffffff;
  }
  if ((param_2 & 1) != 0) {
    if ((param_1 & 0x100) == 0) {
      SVar1 = GetAsyncKeyState(0x10);
      if ((-1 < SVar1) && (SVar1 = GetAsyncKeyState(param_1), SVar1 < 0)) {
        return 0xffffffff;
      }
    }
    else {
      SVar1 = GetAsyncKeyState(0x10);
      if ((SVar1 < 0) && (SVar1 = GetAsyncKeyState(param_1), SVar1 < 0)) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}

