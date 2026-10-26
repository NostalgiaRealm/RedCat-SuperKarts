/*
 * FUN_00496620 at 00496620
 * undefined FUN_00496620(void)
 * Address ranges: 00496620-00496664
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00496620(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  *(undefined2 *)(*(int *)(param_1 + 0x6e) + *(int *)(param_1 + 0x76) * 2) = param_2;
  iVar1 = *(int *)(param_1 + 0x76) + 1;
  *(int *)(param_1 + 0x76) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x6e) + iVar1 * 2) = param_3;
  iVar1 = *(int *)(param_1 + 0x76) + 1;
  *(int *)(param_1 + 0x76) = iVar1;
  *(undefined2 *)(*(int *)(param_1 + 0x6e) + iVar1 * 2) = param_4;
  *(int *)(param_1 + 0x76) = *(int *)(param_1 + 0x76) + 1;
  return;
}

