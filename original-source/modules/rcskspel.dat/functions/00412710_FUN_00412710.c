/*
 * FUN_00412710 at 00412710
 * undefined FUN_00412710(void)
 * Address ranges: 00412710-0041286c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00412710(undefined1 *param_1,char *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_1c [4];
  char *local_18;
  int local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cce78;
  pvStack_c = ExceptionList;
  local_1c[0] = param_2._0_1_;
  uVar3 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  uVar3 = ~uVar3 - 1;
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  ExceptionList = &pvStack_c;
  cVar2 = FUN_0040b600(uVar3,1);
  if (cVar2 != '\0') {
    pcVar5 = local_18;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar5 = *param_2;
      param_2 = param_2 + 1;
      pcVar5 = pcVar5 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 0;
  uVar3 = 0xffffffff;
  if (*(uint *)(param_3 + 8) != 0xffffffff) {
    uVar3 = *(uint *)(param_3 + 8);
  }
  if (-local_14 - 1U <= uVar3) {
    FUN_004bc15b();
  }
  if (uVar3 != 0) {
    iVar1 = local_14 + uVar3;
    cVar2 = FUN_0040b600(iVar1,0);
    if (cVar2 != '\0') {
      pcVar5 = *(char **)(param_3 + 4);
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "";
      }
      pcVar6 = local_18 + local_14;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
      local_18[iVar1] = '\0';
      local_14 = iVar1;
    }
  }
  *param_1 = local_1c[0];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_00412870(local_1c,0,0xffffffff);
  if (local_18 != (char *)0x0) {
    cVar2 = local_18[-1];
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      local_18[-1] = cVar2 + -1;
      ExceptionList = pvStack_c;
      return param_1;
    }
    FUN_004bc150(local_18 + -1);
  }
  ExceptionList = pvStack_c;
  return param_1;
}

