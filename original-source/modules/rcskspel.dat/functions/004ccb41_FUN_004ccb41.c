/*
 * FUN_004ccb41 at 004ccb41
 * undefined FUN_004ccb41(void)
 * Address ranges: 004ccb41-004ccbb8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004ccb41(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 < DAT_006b6b60) &&
     ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    iVar1 = FUN_004c736a(param_1,0,1);
    iVar2 = -1;
    if (iVar1 != -1) {
      iVar2 = FUN_004c736a(param_1,0,2);
      if (iVar1 != iVar2) {
        FUN_004c736a(param_1,iVar1,0);
      }
    }
    return iVar2;
  }
  DAT_006b66ec = 0;
  _DAT_006b66e8 = 9;
  return -1;
}

