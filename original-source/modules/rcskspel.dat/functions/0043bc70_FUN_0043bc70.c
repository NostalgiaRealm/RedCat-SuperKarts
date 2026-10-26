/*
 * FUN_0043bc70 at 0043bc70
 * undefined FUN_0043bc70(void)
 * Address ranges: 0043bc70-0043bf3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043bc70(undefined4 param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  FUN_0043ff30(param_1);
  FUN_0044d730(param_1);
  uVar3 = __ftol();
  iVar5 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
  _DAT_0053c200 = iVar5;
  uVar3 = __ftol();
  _DAT_0053c1fc = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
  if (_DAT_0053c1fc + iVar5 < 0x5f) {
    uVar4 = FUN_0044d730(param_1);
    FUN_0044d4b0(uVar4);
    _DAT_0053c1f8 = FUN_0044f500();
    uVar4 = FUN_0044d730(param_1,_DAT_0053c1f8);
    FUN_0044d4b0(uVar4);
    _DAT_0053c1f4 = FUN_0044f0f0();
    if ((_DAT_0053c1f4 < 0x11) || (0x30 < _DAT_0053c1f4)) {
      uVar4 = DAT_0053be28;
      FUN_0048e210(DAT_0053be28);
      FUN_0048e780(uVar4);
    }
  }
  if (0 < DAT_00508610) {
    puVar6 = &DAT_0050822c;
    iVar5 = 1;
    do {
      FUN_00417e90(iVar5);
      uVar3 = __ftol();
      _DAT_0053c200 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
      FUN_00417e90(iVar5);
      uVar3 = __ftol();
      _DAT_0053c1fc = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
      if (_DAT_0053c1fc + _DAT_0053c200 < 0x5f) {
        uVar4 = FUN_0044d730(param_1);
        FUN_0044d4b0(uVar4);
        _DAT_0053c1f8 = FUN_0044f500();
        uVar4 = FUN_0044d730(param_1,_DAT_0053c1f8);
        FUN_0044d4b0(uVar4);
        _DAT_0053c1f4 = FUN_0044f0f0();
        if ((_DAT_0053c1f4 < 0x11) || (0x30 < _DAT_0053c1f4)) {
          cVar2 = FUN_00417e90(iVar5);
          if (cVar2 == '\0') {
            uVar4 = *puVar6;
            FUN_0048e210(uVar4);
            FUN_0048e780(uVar4);
          }
          else {
            uVar4 = DAT_0053be28;
            FUN_0048e210(DAT_0053be28);
            FUN_0048e780(uVar4);
          }
        }
      }
      puVar6 = puVar6 + 0x1c;
      bVar1 = iVar5 < DAT_00508610;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  return 1;
}

