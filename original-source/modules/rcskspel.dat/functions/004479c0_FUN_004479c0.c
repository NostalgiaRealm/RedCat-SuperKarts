/*
 * FUN_004479c0 at 004479c0
 * undefined FUN_004479c0(void)
 * Address ranges: 004479c0-004479e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004479c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return (*(int *)(*(int *)(param_1 + 4) + 8) - iVar1) / 0x2c;
}

