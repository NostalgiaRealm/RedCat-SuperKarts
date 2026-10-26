/*
 * FUN_0044fa70 at 0044fa70
 * undefined FUN_0044fa70(void)
 * Address ranges: 0044fa70-0044fae5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044fa70(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdb38;
  local_c = ExceptionList;
  if (param_2 == 0) {
    ExceptionList = &local_c;
    uVar1 = FUN_004314a0(local_1c,0);
    local_4 = 0;
    FUN_00412710(local_2c,s_CBonusPoint__SetState_Setting_il_004f0f38,uVar1);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_2c,&DAT_004d5da0);
  }
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_0044ff10(param_2);
  ExceptionList = local_c;
  return;
}

