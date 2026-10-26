/*
 * FUN_004605e0 at 004605e0
 * undefined FUN_004605e0(void)
 * Address ranges: 004605e0-00460605
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004605e0(int *param_1,int param_2,undefined4 param_3)

{
  FUN_00442074(param_1,param_2,param_3);
  if (((char)param_1[0x7e] != '\0') && (param_2 != 0)) {
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

