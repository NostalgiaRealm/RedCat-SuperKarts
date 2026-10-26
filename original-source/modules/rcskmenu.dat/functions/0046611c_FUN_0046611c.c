/*
 * FUN_0046611c at 0046611c
 * undefined FUN_0046611c(void)
 * Address ranges: 0046611c-0046619f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046611c(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  FUN_00442914(param_1);
  if (param_1[0x7f] != 0) {
    bVar1 = FUN_00433874(param_1[0x7f]);
    if (bVar1) {
      iVar2 = FUN_004339b0((int *)param_1[0x7f]);
      FUN_004405f0((int)param_1,0x1303,0,iVar2);
    }
  }
  if (param_1[0x85] != 0) {
    FUN_00466718(param_1);
  }
  if (param_1[0x82] != 0) {
    (**(code **)(*(int *)param_1[0x84] + 8))((int *)param_1[0x84],param_1[0x82]);
    FUN_0046655c(param_1,param_1[0x81]);
    FUN_00402eac((int *)param_1[0x82]);
    param_1[0x82] = 0;
  }
  return;
}

