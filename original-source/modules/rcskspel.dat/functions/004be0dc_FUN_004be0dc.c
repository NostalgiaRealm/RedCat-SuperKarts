/*
 * FUN_004be0dc at 004be0dc
 * undefined FUN_004be0dc(void)
 * Address ranges: 004be0dc-004be0fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004be0dc(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x1c); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[2])(param_2,param_1,puVar1[1]);
  }
  return;
}

