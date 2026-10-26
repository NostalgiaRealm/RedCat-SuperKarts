/*
 * FUN_004bce13 at 004bce13
 * undefined FUN_004bce13(void)
 * Address ranges: 004bce13-004bce52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bce13(int param_1,undefined4 param_2,char param_3)

{
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined1 *)(param_1 + 0x30) = 0x20;
  FUN_004be133();
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_004bde02(*(uint *)(param_1 + 4) | 4,0);
  }
  if (param_3 != '\0') {
    FUN_004be0fe();
  }
  return;
}

