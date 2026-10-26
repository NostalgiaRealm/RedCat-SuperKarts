/*
 * FUN_00496680 at 00496680
 * undefined FUN_00496680(void)
 * Address ranges: 00496680-004966d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00496680(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  *(undefined2 *)(*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x86) * 2) = param_2;
  iVar1 = *(int *)(param_1 + 0x86) + 1;
  *(int *)(param_1 + 0x86) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x7e) + iVar1 * 2) = param_3;
  iVar1 = *(int *)(param_1 + 0x86) + 1;
  *(int *)(param_1 + 0x86) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x7e) + iVar1 * 2) = param_4;
  *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x86) + 1;
  return;
}

