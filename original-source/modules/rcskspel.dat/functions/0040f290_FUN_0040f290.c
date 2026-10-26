/*
 * FUN_0040f290 at 0040f290
 * undefined FUN_0040f290(void)
 * Address ranges: 0040f290-0040f2e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f290(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040ec30((&DAT_00503ef0)[param_1 * 0x47],&DAT_00503f70 + param_1 * 0x11c);
  if ((-10 < iVar1) && (iVar1 < 10)) {
    FUN_0040f380(param_1);
    return;
  }
  if (iVar1 < 0) {
    FUN_0040f320();
    return;
  }
  FUN_0040f350(param_1);
  return;
}

