/*
 * FUN_0040d610 at 0040d610
 * undefined FUN_0040d610(void)
 * Address ranges: 0040d610-0040d716
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d610(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  float10 fVar7;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccd04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  fVar7 = (float10)FUN_0048f4d0();
  *(float *)(&DAT_00504004 + param_1 * 0x11c) = (float)fVar7;
  if ((&DAT_00503ef4)[param_1 * 0x47] != 9) {
    local_1c[0] = (undefined1)param_1;
    uVar3 = 0xffffffff;
    pcVar5 = s_CHEER_004defcc;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    local_18 = (char *)0x0;
    local_14 = 0;
    local_10 = 0;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = s_CHEER_004defcc;
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
    local_4 = 0;
    puVar2 = (undefined4 *)FUN_0044a700(param_1);
    (**(code **)*puVar2)(local_1c);
    if (local_18 != (char *)0x0) {
      cVar1 = local_18[-1];
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        local_18[-1] = cVar1 + -1;
        ExceptionList = local_c;
        return;
      }
      FUN_004bc150(local_18 + -1);
    }
  }
  ExceptionList = local_c;
  return;
}

