/*
 * FUN_00453b00 at 00453b00
 * undefined FUN_00453b00(void)
 * Address ranges: 00453b00-00453d4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00453b00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int local_78;
  undefined1 local_6c [4];
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdd4a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  local_4 = 0;
  switch(param_2) {
  case 1:
    uVar2 = FUN_004314a0(local_2c,param_3);
    local_4._0_1_ = 4;
    FUN_00412710(param_1,s_FIRE_ROCKET_004f1d04,uVar2);
    local_4 = (uint)local_4._1_3_ << 8;
    break;
  case 2:
    uVar2 = FUN_004314a0(local_1c,param_3);
    local_4._0_1_ = 5;
    FUN_00412710(param_1,s_FIRE_SOAP_004f1d10,uVar2);
    local_4 = (uint)local_4._1_3_ << 8;
    break;
  case 3:
    uVar2 = FUN_004314a0(local_4c,param_3);
    local_4._0_1_ = 2;
    FUN_00412710(param_1,s_FIRE_OIL_004f1cec,uVar2);
    local_4 = (uint)local_4._1_3_ << 8;
    break;
  case 4:
    uVar2 = FUN_004314a0(local_3c,param_3);
    local_4._0_1_ = 3;
    FUN_00412710(param_1,s_FIRE_GUM_004f1cf8,uVar2);
    local_4 = (uint)local_4._1_3_ << 8;
    break;
  case 5:
    uVar2 = FUN_004314a0(local_5c,param_3);
    local_4._0_1_ = 1;
    FUN_00412710(param_1,s_FIRE_TURBO_004f1ce0,uVar2);
    local_4 = (uint)local_4._1_3_ << 8;
    break;
  default:
    uVar2 = FUN_004314a0(local_6c,param_3);
    local_4 = CONCAT31(local_4._1_3_,6);
    FUN_00412710(param_1,s_FIRE_OIL_004f1d1c,uVar2);
    if (local_68 != 0) {
      cVar1 = *(char *)(local_68 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_68 + -1));
      }
      else {
        *(char *)(local_68 + -1) = cVar1 + -1;
      }
    }
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    if (local_78 == 0) {
      ExceptionList = local_c;
      return param_1;
    }
    cVar1 = *(char *)(local_78 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_78 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return param_1;
    }
    FUN_004bc150(local_78 + -1);
    ExceptionList = local_c;
    return param_1;
  }
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  ExceptionList = local_c;
  return param_1;
}

