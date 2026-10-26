/*
 * FUN_004c62d6 at 004c62d6
 * undefined FUN_004c62d6(void)
 * Address ranges: 004c62d6-004c6311
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c62d6(int param_1)

{
  int iVar1;
  
  DAT_006b6da0 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_006b6da0 != (HANDLE)0x0) {
    iVar1 = FUN_004c6312();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_006b6da0);
  }
  return 0;
}

