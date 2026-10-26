/*
 * FUN_00487d20 at 00487d20
 * undefined FUN_00487d20(void)
 * Address ranges: 00487d20-00487d47
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00487d20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  return (*(int *)(*(int *)(param_1 + 4) + 8) - iVar1) / 0x794;
}

