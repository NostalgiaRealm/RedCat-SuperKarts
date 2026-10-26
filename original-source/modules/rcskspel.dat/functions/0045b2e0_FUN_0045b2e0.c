/*
 * FUN_0045b2e0 at 0045b2e0
 * undefined FUN_0045b2e0(void)
 * Address ranges: 0045b2e0-0045b445
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0045b334) */

void __thiscall FUN_0045b2e0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

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
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce308;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00459f90(param_2);
  uVar1 = *(undefined1 *)param_3;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 2) = uVar1;
  param_1[4] = 0;
  param_1[5] = 0;
  uVar2 = param_3[2];
  local_4 = 0;
  if (param_1 + 2 == param_3) {
    if (uVar2 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar4 = param_1[4] - uVar2;
    iVar7 = -1;
    if (iVar4 != -1) {
      iVar7 = iVar4;
    }
    if (iVar7 != 0) {
      FUN_004bef90(uVar2 + param_1[3],uVar2 + param_1[3] + iVar7,iVar4 - iVar7);
      iVar4 = param_1[4];
      cVar3 = FUN_0040b600(iVar4 - iVar7,0);
      if (cVar3 != '\0') {
        FUN_0040b5e0(iVar4 - iVar7);
      }
    }
    FUN_00412a80();
  }
  else {
    if (uVar2 != 0) {
      puVar5 = (undefined1 *)param_3[1];
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      if ((byte)puVar5[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar5 = (undefined1 *)param_3[1];
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_004d2404;
        }
        param_1[3] = puVar5;
        param_1[4] = param_3[2];
        param_1[5] = param_3[3];
        puVar5[-1] = puVar5[-1] + '\x01';
        goto LAB_0045b412;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar8 = (undefined4 *)param_3[1];
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)&DAT_004d2404;
      }
      puVar9 = (undefined4 *)param_1[3];
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
      param_1[4] = uVar2;
      *(undefined1 *)(uVar2 + param_1[3]) = 0;
    }
  }
LAB_0045b412:
  param_1[6] = 0x44200000;
  param_1[7] = 0x43f00000;
  param_1[8] = 0x447a0000;
  *param_1 = &PTR_FUN_004d2b68;
  ExceptionList = local_c;
  return;
}

