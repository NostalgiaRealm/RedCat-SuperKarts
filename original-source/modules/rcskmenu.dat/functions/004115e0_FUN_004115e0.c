/*
 * FUN_004115e0 at 004115e0
 * undefined FUN_004115e0(void)
 * Address ranges: 004115e0-00411617
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004115e0(int *param_1,undefined *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uStack_c;
  
  uStack_c = param_3;
  if ((char)param_1[6] == '\0') {
    uStack_c = FUN_00410b78(param_1,param_2);
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x78))(param_1,param_2,&uStack_c);
    if (cVar1 == '\0') {
      uStack_c = 0xffffffff;
    }
  }
  return uStack_c;
}

