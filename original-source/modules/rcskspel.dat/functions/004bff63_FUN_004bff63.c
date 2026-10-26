/*
 * FUN_004bff63 at 004bff63
 * undefined FUN_004bff63(void)
 * Address ranges: 004bff63-004bff98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bff63(uint param_1)

{
  int iVar1;
  
  if ((param_1 <= DAT_005031e4) && (iVar1 = FUN_004c66a6(param_1), iVar1 != 0)) {
    return;
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  HeapAlloc(DAT_006b6da0,0,param_1 + 0xf & 0xfffffff0);
  return;
}

