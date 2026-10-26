/*
 * FUN_004bff99 at 004bff99
 * undefined FUN_004bff99(void)
 * Address ranges: 004bff99-004bffc7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bff99(LPVOID param_1)

{
  int iVar1;
  
  if (param_1 != (LPVOID)0x0) {
    iVar1 = FUN_004c6350(param_1);
    if (iVar1 != 0) {
      FUN_004c637b(iVar1);
      return;
    }
    HeapFree(DAT_006b6da0,0,param_1);
  }
  return;
}

