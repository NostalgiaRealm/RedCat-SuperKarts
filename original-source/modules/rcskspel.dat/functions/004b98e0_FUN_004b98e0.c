/*
 * FUN_004b98e0 at 004b98e0
 * undefined FUN_004b98e0(void)
 * Address ranges: 004b98e0-004b996a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b98e0(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_006ab944 == 0) || (DAT_006ab948 == 1)) {
    iVar3 = FUN_004bf445(param_1,&DAT_005012c0);
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    iVar3 = 0;
    if (0 < _DAT_006ab938) {
      iVar2 = 0;
      do {
        iVar1 = __strcmpi((char *)(iVar2 + DAT_006ab93c),param_1);
        if (iVar1 == 0) {
          return 1;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x1c;
      } while (iVar3 < _DAT_006ab938);
    }
    iVar3 = FUN_004bf445(param_1,&DAT_005012c0);
    if (iVar3 == 0) {
      return 0;
    }
  }
  FUN_004bf2c5(iVar3);
  return 1;
}

