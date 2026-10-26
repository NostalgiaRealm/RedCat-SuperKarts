/*
 * FUN_00464610 at 00464610
 * undefined FUN_00464610(void)
 * Address ranges: 00464610-00464705
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464610(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_98 [28];
  undefined1 local_7c [16];
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf6d0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar1 = FUN_00463d20(local_4c,param_3);
  local_4 = 0;
  uVar2 = FUN_00412710(local_1c,s_Expression___004f4128,param_1);
  local_4._0_1_ = 1;
  uVar2 = FUN_0041b630(local_2c,uVar2,s___failed___004f411c);
  local_4._0_1_ = 2;
  uVar2 = FUN_00459040(local_7c,uVar2,param_2);
  local_4._0_1_ = 3;
  uVar2 = FUN_0041b630(local_6c,uVar2,&DAT_004f4118);
  local_4._0_1_ = 4;
  uVar1 = FUN_00459040(local_5c,uVar2,uVar1);
  local_4._0_1_ = 5;
  uVar1 = FUN_0041b630(local_3c,uVar1,&DAT_004f4114);
  local_4 = CONCAT31(local_4._1_3_,6);
  FUN_00459dc0(uVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_98,&DAT_004d6580);
}

