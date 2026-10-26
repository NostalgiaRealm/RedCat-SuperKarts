/*
 * FUN_0045d010 at 0045d010
 * undefined FUN_0045d010(void)
 * Address ranges: 0045d010-0045d153
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d010(undefined1 param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  float *pfVar7;
  float *pfVar8;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  char *local_18;
  float local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce740;
  local_c = ExceptionList;
  local_1c = (float)CONCAT31(local_1c._1_3_,param_1);
  uVar3 = 0xffffffff;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  local_18 = (char *)0x0;
  local_14 = 0.0;
  local_10 = 0;
  pcVar5 = s_Rotation_004f2d00;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  ExceptionList = &local_c;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Rotation_004f2d00;
    pcVar6 = local_18;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    local_18[uVar3] = '\0';
    local_14 = (float)uVar3;
  }
  pfVar8 = &local_28;
  pfVar7 = &local_1c;
  local_4 = 0;
  uVar2 = FUN_004583c0(pfVar7,pfVar8);
  FUN_0045d470(uVar2,pfVar7,pfVar8);
  local_4 = 0xffffffff;
  if (local_18 != (char *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_18 + -1);
    }
    else {
      local_18[-1] = cVar1 + -1;
    }
  }
  local_28 = _DAT_00544abc * local_28;
  local_24 = local_24 * _DAT_00544abc;
  local_20 = local_20 * _DAT_00544abc;
  local_1c = local_28;
  local_18 = (char *)local_24;
  local_14 = local_20;
  FUN_00458440(&local_28);
  ExceptionList = local_c;
  return;
}

