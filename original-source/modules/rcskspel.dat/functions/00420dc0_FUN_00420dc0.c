/*
 * FUN_00420dc0 at 00420dc0
 * undefined FUN_00420dc0(void)
 * Address ranges: 00420dc0-00420ef8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00420dc0(void)

{
  void **ppvVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int local_20;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccfe8;
  pvStack_c = ExceptionList;
  iVar7 = 0;
  local_20 = 0;
  ExceptionList = &pvStack_c;
  ppvVar1 = &pvStack_c;
  if (0 < DAT_00508610 + 1) {
    do {
      uVar5 = 0xffffffff;
      pcVar8 = s_CHEER_004e4078;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5 - 1;
      local_18 = (char *)0x0;
      local_14 = 0;
      local_10 = 0;
      cVar2 = FUN_0040b600(uVar5,1);
      if (cVar2 != '\0') {
        pcVar8 = s_CHEER_004e4078;
        pcVar9 = local_18;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
        local_18[uVar5] = '\0';
        local_14 = uVar5;
      }
      local_4 = 0;
      piVar4 = (int *)FUN_0044a700(local_20);
      (**(code **)(*piVar4 + 0xc))(local_1c,0,0);
      local_4 = 0xffffffff;
      if (local_18 != (char *)0x0) {
        cVar2 = local_18[-1];
        if ((cVar2 == '\0') || (cVar2 == -1)) {
          FUN_004bc150(local_18 + -1);
        }
        else {
          local_18[-1] = cVar2 + -1;
        }
      }
      local_20 = local_20 + 1;
      local_18 = (char *)0x0;
      local_14 = 0;
      local_10 = 0;
      ppvVar1 = ExceptionList;
    } while (local_20 < DAT_00508610 + 1);
  }
  ExceptionList = ppvVar1;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    do {
      FUN_0044a6c0(iVar7);
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_00508610 + 1);
  }
  uVar3 = FUN_00469680();
  ExceptionList = pvStack_c;
  return uVar3;
}

