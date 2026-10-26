/*
 * FUN_004bdc5e at 004bdc5e
 * undefined FUN_004bdc5e(void)
 * Address ranges: 004bdc5e-004bdca7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bdc5e(int param_1,undefined4 param_2,char param_3)

{
  undefined2 uVar1;
  
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  uVar1 = FUN_004be556(0x20);
  *(undefined2 *)(param_1 + 0x30) = uVar1;
  FUN_004be133();
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_004bde02(*(uint *)(param_1 + 4) | 4,0);
  }
  if (param_3 != '\0') {
    FUN_004be0fe();
  }
  return;
}

