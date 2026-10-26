/*
 * FUN_00438cd0 at 00438cd0
 * undefined FUN_00438cd0(void)
 * Address ranges: 00438cd0-00438cfa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00438cd0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 == *(int *)(param_1 + 0x18)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x24) + -4) + 0x1000;
  }
  return iVar1 + -4;
}

