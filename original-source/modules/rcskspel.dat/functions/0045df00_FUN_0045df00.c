/*
 * FUN_0045df00 at 0045df00
 * undefined FUN_0045df00(void)
 * Address ranges: 0045df00-0045e02b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045df00(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce9e7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0041b630(local_1c,param_1 + 0x808,s__ASCII_004f3410);
  iVar3 = 0;
  local_4 = 0;
  do {
    uVar2 = FUN_00463d20(local_2c,iVar3);
    local_4._0_1_ = 1;
    FUN_00464150(local_3c,local_1c,uVar2);
    local_4 = CONCAT31(local_4._1_3_,3);
    if (local_28 != 0) {
      cVar1 = *(char *)(local_28 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_28 + -1));
      }
      else {
        *(char *)(local_28 + -1) = cVar1 + -1;
      }
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    if (local_34 != 0) {
      FUN_0045e030(local_3c,iVar3,param_1);
    }
    local_4 = local_4 & 0xffffff00;
    if (local_38 != 0) {
      cVar1 = *(char *)(local_38 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_38 + -1);
      }
      else {
        *(char *)(local_38 + -1) = cVar1 + -1;
      }
    }
    iVar3 = iVar3 + 1;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
  } while (iVar3 < 0x100);
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_18 + -1);
    }
    else {
      *(char *)(local_18 + -1) = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return;
}

