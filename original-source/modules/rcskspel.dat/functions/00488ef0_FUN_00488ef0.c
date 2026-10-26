/*
 * FUN_00488ef0 at 00488ef0
 * undefined FUN_00488ef0(void)
 * Address ranges: 00488ef0-00488f17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00488ef0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return (*(int *)(*(int *)(param_1 + 4) + 8) - iVar1) / 0x17c;
}

