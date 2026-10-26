/*
 * FUN_0047cee0 at 0047cee0
 * undefined FUN_0047cee0(void)
 * Address ranges: 0047cee0-0047cefa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047cee0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x30);
  *(undefined4 *)((int)pvVar1 + 4) = param_1;
  *(undefined4 *)((int)pvVar1 + 0x2c) = param_2;
  return;
}

