/*
 * FUN_004966f0 at 004966f0
 * undefined FUN_004966f0(void)
 * Address ranges: 004966f0-00496734
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004966f0(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  *(undefined2 *)(*(int *)(param_1 + 0x5e) + *(int *)(param_1 + 0x66) * 2) = param_2;
  iVar1 = *(int *)(param_1 + 0x66) + 1;
  *(int *)(param_1 + 0x66) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x5e) + iVar1 * 2) = param_3;
  iVar1 = *(int *)(param_1 + 0x66) + 1;
  *(int *)(param_1 + 0x66) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x5e) + iVar1 * 2) = param_4;
  *(int *)(param_1 + 0x66) = *(int *)(param_1 + 0x66) + 1;
  return;
}

