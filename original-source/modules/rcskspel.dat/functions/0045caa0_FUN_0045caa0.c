/*
 * FUN_0045caa0 at 0045caa0
 * undefined FUN_0045caa0(void)
 * Address ranges: 0045caa0-0045cbfe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045caa0(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 *puVar8;
  float *pfVar9;
  float local_28;
  float local_24;
  float local_20;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce6e2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0045cd10(param_2);
  local_1c[0] = (undefined1)param_2;
  uVar4 = 0xffffffff;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  pcVar6 = s_Position_004f2cec;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar2 = FUN_0040b600(uVar4,1);
  if (cVar2 != '\0') {
    pcVar6 = s_Position_004f2cec;
    pcVar7 = local_18;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    local_18[uVar4] = '\0';
    local_14 = uVar4;
  }
  pfVar9 = &local_28;
  puVar8 = local_1c;
  local_4 = 0;
  uVar3 = FUN_004583c0(puVar8,pfVar9);
  cVar2 = FUN_0045d470(uVar3,puVar8,pfVar9);
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
  local_10 = 0;
  if (cVar2 != '\0') {
    local_28 = local_28 / *(float *)(param_1 + 0x1c);
    local_28 = (local_28 + local_28) - *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
    local_24 = local_24 / *(float *)(param_1 + 0x1c);
    local_24 = 1.0 - (local_24 + local_24);
    local_20 = local_20 / *(float *)(param_1 + 0x20);
    FUN_00458400(&local_28);
  }
  ExceptionList = local_c;
  return;
}

