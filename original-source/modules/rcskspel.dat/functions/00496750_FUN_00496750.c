/*
 * FUN_00496750 at 00496750
 * undefined FUN_00496750(void)
 * Address ranges: 00496750-004967b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00496750(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  *(undefined2 *)(*(int *)(param_1 + 0x8e) + *(int *)(param_1 + 0x96) * 2) = param_2;
  iVar1 = *(int *)(param_1 + 0x96) + 1;
  *(int *)(param_1 + 0x96) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x8e) + iVar1 * 2) = param_3;
  iVar1 = *(int *)(param_1 + 0x96) + 1;
  *(int *)(param_1 + 0x96) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x8e) + iVar1 * 2) = param_4;
  *(int *)(param_1 + 0x96) = *(int *)(param_1 + 0x96) + 1;
  return;
}

