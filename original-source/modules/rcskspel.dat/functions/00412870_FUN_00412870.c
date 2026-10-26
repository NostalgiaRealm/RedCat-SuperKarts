/*
 * FUN_00412870 at 00412870
 * undefined FUN_00412870(void)
 * Address ranges: 00412870-00412a6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00412870(int param_1,int param_2,uint param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if (*(uint *)(param_2 + 8) < param_3) {
    FUN_004bc243();
  }
  uVar6 = *(uint *)(param_2 + 8) - param_3;
  if (param_4 < uVar6) {
    uVar6 = param_4;
  }
  if (param_1 == param_2) {
    uVar6 = uVar6 + param_3;
    if (*(uint *)(param_1 + 8) < uVar6) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar2 = *(int *)(param_1 + 8) - uVar6;
    iVar7 = -1;
    if (iVar2 != -1) {
      iVar7 = iVar2;
    }
    if (iVar7 != 0) {
      iVar5 = *(int *)(param_1 + 4) + uVar6;
      FUN_004bef90(iVar5,iVar5 + iVar7,iVar2 - iVar7);
      iVar7 = *(int *)(param_1 + 8) - iVar7;
      cVar1 = FUN_0040b600(iVar7,0);
      if (cVar1 != '\0') {
        *(int *)(param_1 + 8) = iVar7;
        *(undefined1 *)(iVar7 + *(int *)(param_1 + 4)) = 0;
      }
    }
    FUN_00412a80();
    uVar6 = *(uint *)(param_1 + 8);
    if (uVar6 < param_3) {
      param_3 = uVar6;
    }
    if (param_3 == 0) {
      return param_1;
    }
    FUN_004bef90(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + param_3,uVar6 - param_3);
    iVar7 = *(int *)(param_1 + 8) - param_3;
    cVar1 = FUN_0040b600(iVar7,0);
    if (cVar1 == '\0') {
      return param_1;
    }
    FUN_0040b5e0(iVar7);
    return param_1;
  }
  if ((uVar6 != 0) && (uVar6 == *(uint *)(param_2 + 8))) {
    puVar3 = *(undefined1 **)(param_2 + 4);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    if ((byte)puVar3[-1] < 0xfe) {
      iVar7 = *(int *)(param_1 + 4);
      if (iVar7 != 0) {
        cVar1 = *(char *)(iVar7 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(iVar7 + -1));
        }
        else {
          *(char *)(iVar7 + -1) = cVar1 + -1;
        }
      }
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      puVar3 = *(undefined1 **)(param_2 + 4);
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      *(undefined1 **)(param_1 + 4) = puVar3;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
      puVar3[-1] = puVar3[-1] + '\x01';
      return param_1;
    }
  }
  uVar4 = FUN_00412a70();
  if (uVar4 < uVar6) {
    FUN_004bc15b();
  }
  iVar7 = *(int *)(param_1 + 4);
  if (((iVar7 == 0) || (cVar1 = *(char *)(iVar7 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar6 == 0) {
      FUN_0040b4f0(1);
      return param_1;
    }
    if ((*(uint *)(param_1 + 0xc) < 0x20) && (uVar6 <= *(uint *)(param_1 + 0xc))) goto LAB_00412a3c;
    FUN_0040b4f0(1);
  }
  else if (uVar6 == 0) {
    *(char *)(iVar7 + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return param_1;
  }
  FUN_0040b720(uVar6);
LAB_00412a3c:
  puVar3 = *(undefined1 **)(param_2 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  puVar8 = (undefined4 *)(puVar3 + param_3);
  puVar9 = *(undefined4 **)(param_1 + 4);
  for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  *(uint *)(param_1 + 8) = uVar6;
  *(undefined1 *)(uVar6 + *(int *)(param_1 + 4)) = 0;
  return param_1;
}

