/*
 * FUN_00427d1c at 00427d1c
 * DWORD __cdecl FUN_00427d1c(uint param_1)
 * Address ranges: 00427d1c-00427d93
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_00427d1c(uint param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    DVar1 = FUN_00422935(param_1,0,1);
    DVar2 = 0xffffffff;
    if (DVar1 != 0xffffffff) {
      DVar2 = FUN_00422935(param_1,0,2);
      if (DVar1 != DVar2) {
        FUN_00422935(param_1,DVar1,0);
      }
    }
    return DVar2;
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}

