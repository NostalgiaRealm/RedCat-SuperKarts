/*
 * FUN_00486640 at 00486640
 * undefined FUN_00486640(void)
 * Address ranges: 00486640-00486665
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00486640(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return (*(int *)(*(int *)(param_1 + 4) + 8) - iVar1) / 0x288;
}

