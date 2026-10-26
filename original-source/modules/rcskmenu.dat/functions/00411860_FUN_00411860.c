/*
 * FUN_00411860 at 00411860
 * undefined FUN_00411860(void)
 * Address ranges: 00411860-00411890
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411860(int *param_1,undefined *param_2)

{
  if (((char)param_1[6] == '\0') && (1 < param_1[4])) {
    (**(code **)(*param_1 + 0x74))();
    FUN_0041175c((int)param_1,0,param_1[4] - 1,param_2);
    (**(code **)(*param_1 + 0x70))();
  }
  return;
}

