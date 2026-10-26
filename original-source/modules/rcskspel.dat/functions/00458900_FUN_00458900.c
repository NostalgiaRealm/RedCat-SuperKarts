/*
 * FUN_00458900 at 00458900
 * undefined FUN_00458900(void)
 * Address ranges: 00458900-004589be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00458900(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [28];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cdf51;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_2 + 0xc))(param_1 + 0x34);
  if (iVar1 != 0) {
    uVar2 = FUN_004583c0();
    uVar2 = FUN_00412710(&stack0xffffffa4,s_Invalid_Add__Component_004f2824,uVar2);
    puStack_8 = (undefined1 *)0x0;
    uVar2 = FUN_0041b630(auStack_4c,uVar2,s_contains_004f2818);
    puStack_8._0_1_ = 1;
    uVar2 = FUN_00459040(auStack_3c,uVar2,param_1 + 0x34);
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(auStack_2c,&DAT_004d6580);
  }
  FUN_00459170(*(undefined4 *)(*(int *)(param_1 + 0x78) + 8),1,&stack0x00000000);
  ExceptionList = pvStack_10;
  return;
}

