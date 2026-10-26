/*
 * FUN_004cca81 at 004cca81
 * undefined FUN_004cca81(void)
 * Address ranges: 004cca81-004ccab7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004cca81(uint param_1)

{
  char cVar1;
  UINT UVar2;
  
  if (param_1 != 0) {
    cVar1 = (char)param_1;
    param_1 = (uint)CONCAT12(0x5c,CONCAT11(0x3a,cVar1 + '@'));
    UVar2 = GetDriveTypeA((LPCSTR)&param_1);
    if ((UVar2 == 0) || (UVar2 == 1)) {
      return 0;
    }
  }
  return 1;
}

