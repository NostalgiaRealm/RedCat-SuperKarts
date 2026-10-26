/*
 * FUN_0045dca0 at 0045dca0
 * undefined FUN_0045dca0(void)
 * Address ranges: 0045dca0-0045ddd6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045dca0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined **ppuVar8;
  float10 fVar9;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce9ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = FUN_00461870(param_1);
  local_1c[0] = (undefined1)param_1;
  uVar3 = 0xffffffff;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  pcVar5 = s_DISTANCE_004f2d34;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_DISTANCE_004f2d34;
    pcVar7 = local_18;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    local_18[uVar3] = '\0';
    local_14 = uVar3;
  }
  iVar6 = 0;
  local_4 = 0;
  fVar9 = (float10)FUN_00463fb0(param_1,local_1c);
  FUN_0045b120((float)fVar9);
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
  if (0 < DAT_004f2cac) {
    ppuVar8 = &PTR_DAT_004d2a00;
    do {
      FUN_0045dde0(uVar2,ppuVar8);
      iVar6 = iVar6 + 1;
      ppuVar8 = ppuVar8 + 2;
    } while (iVar6 < DAT_004f2cac);
  }
  FUN_0045df00(uVar2);
  FUN_0045b140();
  ExceptionList = local_c;
  return;
}

