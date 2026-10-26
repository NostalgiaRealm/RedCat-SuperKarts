/*
 * FUN_00453414 at 00453414
 * undefined FUN_00453414(void)
 * Address ranges: 00453414-0045344f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453414(int param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00453370(param_1,param_2);
  (**(code **)(*piVar1 + 8))(piVar1,param_3);
  if (param_2 == 5) {
    FUN_004534f4(param_1,0x4401);
  }
  else {
    FUN_004534f4(param_1,0x4400);
  }
  return;
}

