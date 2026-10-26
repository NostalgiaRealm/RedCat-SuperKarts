/*
 * FUN_00419290 at 00419290
 * undefined FUN_00419290(void)
 * Address ranges: 00419290-00419360
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419290(float *param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  FUN_00419230(0x20);
  FUN_00419260();
  FUN_004b1850(0,0,0,&DAT_004e1870,param_4);
  iVar1 = FUN_004b3830(0x1b);
  while (iVar1 == 0) {
    FUN_004b1850(0,0,0x28,s__s___f_004e1874,param_5,(double)*param_1);
    iVar1 = FUN_004b3830(0x6b);
    if (iVar1 != 0) {
      *param_1 = param_2 + *param_1;
      FUN_00419230();
    }
    iVar1 = FUN_004b3830();
    if (iVar1 != 0) {
      *param_1 = *param_1 - param_3;
      FUN_00419230();
    }
    iVar1 = FUN_004b3830();
    if (iVar1 != 0) {
      *param_1 = 0.0;
      FUN_00419230();
    }
    iVar1 = FUN_004b3830();
  }
  FUN_00419230(0x1b);
  return;
}

