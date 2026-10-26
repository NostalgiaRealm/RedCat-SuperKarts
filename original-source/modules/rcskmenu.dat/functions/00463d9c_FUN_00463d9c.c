/*
 * FUN_00463d9c at 00463d9c
 * undefined FUN_00463d9c(void)
 * Address ranges: 00463d9c-00463dab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463d9c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x3c);
  return;
}

