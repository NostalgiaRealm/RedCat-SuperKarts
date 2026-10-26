/*
 * FUN_004299f4 at 004299f4
 * undefined FUN_004299f4(void)
 * Address ranges: 004299f4-00429a42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004299f4(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00426e14);
  if ((char)uVar1 == '\0') {
    FUN_0040fca8(param_1,param_2);
  }
  else {
    FUN_0042a2bc((int)param_1,(char)param_2[7]);
    FUN_0042a29c((int)param_1,param_2[4]);
    FUN_0042a14c((int)param_1,param_2[3]);
    *(short *)(param_1 + 2) = (short)param_2[2];
  }
  return;
}

