/*
 * FUN_00464530 at 00464530
 * undefined FUN_00464530(void)
 * Address ranges: 00464530-004645f2;004645f4-00464602
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464530(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf68e;
  local_c = ExceptionList;
  if (param_1 == 0) {
    ExceptionList = &local_c;
    uVar1 = FUN_00463d20(local_78,param_4);
    local_4 = 0;
    uVar2 = FUN_0041b630(local_68,param_2,s___Invalid_NULL_pointer_in_004f40f8);
    local_4._0_1_ = 1;
    uVar2 = FUN_00459040(local_58,uVar2,param_3);
    local_4._0_1_ = 2;
    uVar2 = FUN_0041b630(local_48,uVar2,&DAT_004f40f4);
    local_4._0_1_ = 3;
    uVar1 = FUN_00459040(local_38,uVar2,uVar1);
    local_4 = CONCAT31(local_4._1_3_,4);
    FUN_00459dc0(uVar1);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_004d6580);
  }
  return;
}

