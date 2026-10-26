/*
 * FUN_00442500 at 00442500
 * undefined __register FUN_00442500(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 00442500-004425d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442500(int *param_1,int *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  FUN_00403088(param_2,param_1,param_3);
  FUN_004405f0((int)param_1,0xb02c,param_2,1);
  FUN_0044246c((int)param_1,param_2);
  if ((*(byte *)(param_2 + 0x11) & 8) == 0) {
    FUN_004405f0((int)param_2,0xb009,0,0);
    FUN_004405f0((int)param_2,0xb008,0,0);
    FUN_004405f0((int)param_2,0xb023,0,0);
    FUN_004405f0((int)param_2,0xb03d,0,0);
    uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_0043be00);
    if ((char)uVar2 == '\0') {
      bVar1 = FUN_00445a20((int)param_1);
      if (bVar1) {
        (**(code **)(*param_2 + 0x74))();
      }
    }
    else {
      FUN_004405f0((int)param_2,0xb011,0,0);
      FUN_00442e24(param_1);
    }
    FUN_00442160(param_1,param_2);
  }
  FUN_004405f0((int)param_1,0xb036,param_2,1);
  return;
}

