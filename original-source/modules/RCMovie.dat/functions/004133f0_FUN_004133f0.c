/*
 * FUN_004133f0 at 004133f0
 * undefined4 __cdecl FUN_004133f0(uint param_1)
 * Address ranges: 004133f0-00413458
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004133f0(uint param_1)

{
  SHORT SVar1;
  undefined4 uVar2;
  
  if ((param_1 & 0x100) == 0) {
    SVar1 = GetAsyncKeyState(0x10);
    if (SVar1 < 0) {
      uVar2 = 0;
    }
    else {
      SVar1 = GetAsyncKeyState(param_1);
      if (SVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    SVar1 = GetAsyncKeyState(0x10);
    if (SVar1 < 0) {
      SVar1 = GetAsyncKeyState(param_1);
      if (SVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

