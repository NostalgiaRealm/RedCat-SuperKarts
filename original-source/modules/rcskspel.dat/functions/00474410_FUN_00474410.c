/*
 * FUN_00474410 at 00474410
 * undefined FUN_00474410(void)
 * Address ranges: 00474410-004746ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_00474410(undefined4 *param_1,undefined4 param_2,undefined1 *param_3)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_359;
  char local_358 [4];
  uint local_354;
  undefined1 local_350 [4];
  char *local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined1 local_340 [4];
  char *local_33c;
  undefined4 *local_330;
  undefined1 local_32c [16];
  undefined1 local_31c [16];
  char local_30c [256];
  CHAR local_20c [512];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0948;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 2) = local_359;
  local_330 = param_1;
  FUN_0040b4f0(0);
  local_4 = 0;
  *(undefined1 *)(param_1 + 6) = *param_3;
  FUN_0040b4f0(0);
  FUN_00412870(param_3,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[10] = 0;
  param_1[0xb] = 0;
  *param_1 = &PTR_FUN_004d2e44;
  FUN_004afce0(s___Getting_module_file_name_004f77e8);
  GetModuleFileNameA((HMODULE)0x0,local_20c,0x1ff);
  FUN_004afce0(s___Splitting_path_004f7804);
  FUN_004c00b6(local_20c,local_358,local_30c,0,0);
  FUN_004afce0(s___Creating_ini_file_name_004f7818);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar7 = local_30c;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  local_354 = uVar4;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar7 = local_30c;
    pcVar8 = local_33c;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    FUN_0040b5e0(uVar4);
  }
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar7 = local_358;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  local_354 = uVar4;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar7 = local_358;
    pcVar8 = local_34c;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    FUN_0040b5e0(uVar4);
  }
  local_4._0_1_ = 3;
  uVar3 = FUN_00459040(local_31c,local_350,local_340);
  local_4._0_1_ = 4;
  uVar3 = FUN_00459040(local_32c,uVar3,param_2);
  local_4._0_1_ = 5;
  FUN_00412870(uVar3,0,0xffffffff);
  local_4._0_1_ = 4;
  FUN_0040b4f0(1);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_0040b4f0(1);
  if (local_34c != (char *)0x0) {
    cVar1 = local_34c[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_34c + -1);
    }
    else {
      local_34c[-1] = cVar1 + -1;
    }
  }
  local_34c = (char *)0x0;
  local_348 = 0;
  local_344 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (local_33c != (char *)0x0) {
    cVar1 = local_33c[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_33c + -1);
    }
    else {
      local_33c[-1] = cVar1 + -1;
    }
  }
  puVar6 = (undefined1 *)param_1[3];
  if (puVar6 == (undefined1 *)0x0) {
    puVar6 = &DAT_004d2404;
  }
  FUN_004afce0(s___Created_ini_file_name__s_004f7834,puVar6);
  FUN_004afce0(s___Performing_section_read_004f7850);
  uVar2 = FUN_00474760(param_3);
  *(undefined1 *)(param_1 + 1) = uVar2;
  ExceptionList = local_c;
  return param_1;
}

