/*
 * FUN_004472d0 at 004472d0
 * undefined FUN_004472d0(void)
 * Address ranges: 004472d0-00447436
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044732e) */

undefined4 * __thiscall FUN_004472d0(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 *local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd728;
  local_c = ExceptionList;
  local_14 = &DAT_005437b0;
  ExceptionList = &local_c;
  local_10 = param_1;
  FUN_004bfdaf(&local_14);
  uVar1 = *(undefined1 *)param_2;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 3) = uVar1;
  param_1[5] = 0;
  param_1[6] = 0;
  uVar2 = param_2[2];
  local_4 = 0;
  if (param_1 + 3 == param_2) {
    if (uVar2 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar4 = param_1[5] - uVar2;
    iVar7 = -1;
    if (iVar4 != -1) {
      iVar7 = iVar4;
    }
    if (iVar7 != 0) {
      FUN_004bef90(uVar2 + param_1[4],uVar2 + param_1[4] + iVar7,iVar4 - iVar7);
      iVar4 = param_1[5];
      cVar3 = FUN_0040b600(iVar4 - iVar7,0);
      if (cVar3 != '\0') {
        FUN_0040b5e0(iVar4 - iVar7);
      }
    }
    FUN_00412a80();
  }
  else {
    if (uVar2 != 0) {
      puVar5 = (undefined1 *)param_2[1];
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      if ((byte)puVar5[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar5 = (undefined1 *)param_2[1];
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_004d2404;
        }
        param_1[4] = puVar5;
        param_1[5] = param_2[2];
        param_1[6] = param_2[3];
        puVar5[-1] = puVar5[-1] + '\x01';
        goto LAB_0044738c;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar8 = (undefined4 *)param_2[1];
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)&DAT_004d2404;
      }
      puVar9 = (undefined4 *)param_1[4];
      for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      param_1[5] = uVar2;
      *(undefined1 *)(uVar2 + param_1[4]) = 0;
      *local_10 = &PTR_FUN_004d34f4;
      ExceptionList = local_c;
      return local_10;
    }
  }
LAB_0044738c:
  *param_1 = &PTR_FUN_004d34f4;
  ExceptionList = local_c;
  return param_1;
}

