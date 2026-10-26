/*
 * FUN_0045dde0 at 0045dde0
 * undefined FUN_0045dde0(void)
 * Address ranges: 0045dde0-0045def4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045dde0(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce9c5;
  local_c = ExceptionList;
  local_2c[0] = param_2._0_1_;
  uVar2 = 0xffffffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  pcVar3 = (char *)*param_2;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  FUN_0040b540((char *)*param_2,~uVar2 - 1);
  local_4 = 0;
  FUN_00464150(local_1c,param_1 + 0x808,local_2c);
  local_4 = CONCAT31(local_4._1_3_,2);
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
  if (local_14 == 0) {
    if (local_18 == 0) {
      ExceptionList = local_c;
      return;
    }
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
  }
  else {
    FUN_0045e030(local_1c,*(undefined1 *)(param_2 + 1),param_1);
    if (local_18 == 0) {
      ExceptionList = local_c;
      return;
    }
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
  }
  FUN_004bc150(local_18 + -1);
  ExceptionList = local_c;
  return;
}

