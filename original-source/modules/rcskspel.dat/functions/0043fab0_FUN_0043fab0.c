/*
 * FUN_0043fab0 at 0043fab0
 * undefined FUN_0043fab0(void)
 * Address ranges: 0043fab0-0043fd72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043fab0(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iStack_8;
  
  uVar2 = param_1;
  FUN_0043ff30(param_1);
  uVar4 = __ftol();
  iVar6 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
  _DAT_0053c220 = iVar6;
  uVar4 = __ftol();
  _DAT_0053c21c = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
  if (_DAT_0053c21c + iVar6 < 0x2c) {
    uVar5 = FUN_0044d730(param_1);
    FUN_0044d4b0(uVar5);
    _DAT_0053c218 = FUN_0044f500();
    uVar5 = FUN_0044d730(param_1,_DAT_0053c218);
    FUN_0044d4b0(uVar5);
    _DAT_0053c214 = FUN_0044f0f0();
    if ((_DAT_0053c214 < 3) || (0x26 < _DAT_0053c214)) {
      uVar5 = DAT_0053be28;
      FUN_0048e210(DAT_0053be28);
      FUN_0048e780(uVar5);
    }
  }
  if (0 < DAT_00508610) {
    param_1 = &DAT_0050822c;
    iStack_8 = 1;
    do {
      FUN_00417e90(iStack_8);
      uVar4 = __ftol();
      _DAT_0053c220 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
      FUN_00417e90(iStack_8);
      uVar4 = __ftol();
      _DAT_0053c21c = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
      if (_DAT_0053c21c + _DAT_0053c220 < 0x2c) {
        uVar5 = FUN_0044d730(uVar2);
        FUN_0044d4b0(uVar5);
        _DAT_0053c218 = FUN_0044f500();
        uVar5 = FUN_0044d730(uVar2,_DAT_0053c218);
        FUN_0044d4b0(uVar5);
        _DAT_0053c214 = FUN_0044f0f0();
        if ((_DAT_0053c214 < 3) || (0x26 < _DAT_0053c214)) {
          cVar3 = FUN_00417e90(iStack_8);
          if (cVar3 == '\0') {
            uVar5 = *param_1;
            FUN_0048e210(uVar5);
            FUN_0048e780(uVar5);
          }
          else {
            uVar5 = DAT_0053be28;
            FUN_0048e210(DAT_0053be28);
            FUN_0048e780(uVar5);
          }
        }
      }
      param_1 = param_1 + 0x1c;
      bVar1 = iStack_8 < DAT_00508610;
      iStack_8 = iStack_8 + 1;
    } while (bVar1);
  }
  return 1;
}

