/*
 * FUN_00480dd0 at 00480dd0
 * undefined FUN_00480dd0(void)
 * Address ranges: 00480dd0-00480f1d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00480e21) */

void FUN_00480dd0(undefined1 *param_1,undefined1 *param_2)

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
  
  puStack_8 = &LAB_004d1311;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 == (undefined1 *)0x0) {
    return;
  }
  uVar1 = *param_2;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = uVar1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar2 = *(uint *)(param_2 + 8);
  if (param_1 == param_2) {
    if (uVar2 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar4 = *(int *)(param_1 + 8) - uVar2;
    iVar7 = -1;
    if (iVar4 != -1) {
      iVar7 = iVar4;
    }
    if (iVar7 != 0) {
      FUN_004bef90(uVar2 + *(int *)(param_1 + 4),uVar2 + *(int *)(param_1 + 4) + iVar7,iVar4 - iVar7
                  );
      iVar4 = *(int *)(param_1 + 8);
      cVar3 = FUN_0040b600(iVar4 - iVar7,0);
      if (cVar3 != '\0') {
        FUN_0040b5e0(iVar4 - iVar7);
      }
    }
    FUN_00412a80();
  }
  else {
    if (uVar2 != 0) {
      puVar5 = *(undefined1 **)(param_2 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      if ((byte)puVar5[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar5 = *(undefined1 **)(param_2 + 4);
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 4) = puVar5;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        puVar5[-1] = puVar5[-1] + '\x01';
        goto LAB_00480f05;
      }
    }
    cVar3 = FUN_0040b600(uVar2,1);
    if (cVar3 != '\0') {
      puVar8 = *(undefined4 **)(param_2 + 4);
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)&DAT_004d2404;
      }
      puVar9 = *(undefined4 **)(param_1 + 4);
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
      *(uint *)(param_1 + 8) = uVar2;
      *(undefined1 *)(*(int *)(param_1 + 4) + uVar2) = 0;
    }
  }
LAB_00480f05:
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  ExceptionList = local_c;
  return;
}

