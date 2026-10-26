/*
 * FUN_00467bf0 at 00467bf0
 * undefined FUN_00467bf0(void)
 * Address ranges: 00467bf0-00467ccb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00467bf0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 local_30 [4];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cfbba;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffa0;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004606c0();
  FUN_00462180(DAT_0053b9f0 != 0);
  local_30[0] = local_15;
  uVar2 = 0xffffffff;
  local_2c = 0;
  pcVar3 = s_overlay_ini_004f4c40;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_28 = 0;
  local_24 = 0;
  FUN_0040b540(s_overlay_ini_004f4c40,~uVar2 - 1);
  local_8._0_1_ = 1;
  FUN_0045b2e0(param_1,local_30);
  local_8._0_1_ = 3;
  if (local_2c != 0) {
    cVar1 = *(char *)(local_2c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_2c + -1));
    }
    else {
      *(char *)(local_2c + -1) = cVar1 + -1;
    }
  }
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  FUN_0045b450();
  FUN_00467e30();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_0040b4f0(1);
  ExceptionList = local_10;
  return;
}

