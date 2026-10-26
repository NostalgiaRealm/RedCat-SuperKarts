/*
 * FUN_0043cf94 at 0043cf94
 * undefined FUN_0043cf94(void)
 * Address ranges: 0043cf94-0043cfb1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cf94(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x48))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x48))();
    FUN_00447028(iVar1);
  }
  return;
}

