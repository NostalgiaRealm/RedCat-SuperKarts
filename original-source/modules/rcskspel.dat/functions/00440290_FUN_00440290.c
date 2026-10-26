/*
 * FUN_00440290 at 00440290
 * undefined FUN_00440290(void)
 * Address ranges: 00440290-00440462
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00440290(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = __ftol();
  iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
  _DAT_0053c230 = iVar2;
  uVar1 = __ftol();
  _DAT_0053c22c = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
  if (_DAT_0053c22c + iVar2 < 0x20) {
    uVar3 = param_1;
    FUN_0048e210(param_1);
    FUN_0048e780(uVar3);
  }
  iVar2 = 0;
  if (0 < DAT_00508610) {
    do {
      FUN_00417e90(iVar2);
      uVar1 = __ftol();
      _DAT_0053c230 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
      FUN_00417e90(iVar2);
      uVar1 = __ftol();
      _DAT_0053c22c = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
      if (_DAT_0053c22c + _DAT_0053c230 < 0x20) {
        uVar3 = param_1;
        FUN_0048e210(param_1);
        FUN_0048e780(uVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00508610);
  }
  return 1;
}

