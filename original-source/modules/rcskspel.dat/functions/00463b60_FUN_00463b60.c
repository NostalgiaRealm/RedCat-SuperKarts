/*
 * FUN_00463b60 at 00463b60
 * undefined FUN_00463b60(void)
 * Address ranges: 00463b60-00463b7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00463b60(int *param_1,int param_2)

{
  if (param_1[0x24] != param_2) {
    param_1[0x24] = param_2;
    (**(code **)(*param_1 + 0x44))();
  }
  return;
}

