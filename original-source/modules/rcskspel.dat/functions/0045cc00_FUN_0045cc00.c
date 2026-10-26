/*
 * FUN_0045cc00 at 0045cc00
 * undefined FUN_0045cc00(void)
 * Address ranges: 0045cc00-0045cd0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045cc00(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce6f4;
  pvStack_c = ExceptionList;
  local_1c[0] = param_1._0_1_;
  uVar3 = 0xffffffff;
  local_28 = 0x3f800000;
  local_24 = 0x3f800000;
  local_20 = 0x3f800000;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = (void *)0x0;
  pcVar5 = s_Scale_004f2cf8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  ExceptionList = &pvStack_c;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_Scale_004f2cf8;
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
    local_14 = uVar3;
  }
  puVar8 = &local_28;
  puVar7 = local_1c;
  local_4 = 0;
  uVar2 = FUN_004583c0(puVar7,puVar8);
  FUN_0045d470(uVar2,puVar7,puVar8);
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
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = (void *)0x0;
  (**(code **)(*param_1 + 0x24))(&local_28);
  ExceptionList = local_10;
  return;
}

