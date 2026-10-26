/*
 * FUN_0043cfb4 at 0043cfb4
 * undefined FUN_0043cfb4(void)
 * Address ranges: 0043cfb4-0043cfd1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cfb4(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x48))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x48))();
    FUN_00447010(iVar1);
  }
  return;
}

