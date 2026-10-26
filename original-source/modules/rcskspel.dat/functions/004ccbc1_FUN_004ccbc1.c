/*
 * FUN_004ccbc1 at 004ccbc1
 * undefined FUN_004ccbc1(void)
 * Address ranges: 004ccbc1-004ccc04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ccbc1(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    FUN_004c6e51(DVar1);
  }
  else {
    if (((DVar1 & 1) == 0) || ((param_2 & 2) == 0)) {
      return 0;
    }
    _DAT_006b66e8 = 0xd;
    DAT_006b66ec = 5;
  }
  return 0xffffffff;
}

