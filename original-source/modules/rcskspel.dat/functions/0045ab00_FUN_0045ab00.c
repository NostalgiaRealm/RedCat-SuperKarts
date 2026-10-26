/*
 * FUN_0045ab00 at 0045ab00
 * undefined FUN_0045ab00(void)
 * Address ranges: 0045ab00-0045ac44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0045ab3e) */

undefined4 * __thiscall FUN_0045ab00(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  param_1[0x200] = 0;
  param_1[0x201] = 0;
  *(undefined1 *)(param_1 + 0x202) = *(undefined1 *)param_2;
  param_1[0x203] = 0;
  param_1[0x204] = 0;
  param_1[0x205] = 0;
  uVar1 = param_2[2];
  if (param_1 + 0x202 == param_2) {
    if (uVar1 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = param_1[0x204] - uVar1;
    iVar6 = -1;
    if (iVar3 != -1) {
      iVar6 = iVar3;
    }
    if (iVar6 != 0) {
      FUN_004bef90(uVar1 + param_1[0x203],uVar1 + param_1[0x203] + iVar6,iVar3 - iVar6);
      iVar3 = param_1[0x204];
      cVar2 = FUN_0040b600(iVar3 - iVar6,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar3 - iVar6);
      }
    }
    FUN_00412a80();
  }
  else {
    if (uVar1 != 0) {
      puVar4 = (undefined1 *)param_2[1];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = (undefined1 *)param_2[1];
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        param_1[0x203] = puVar4;
        param_1[0x204] = param_2[2];
        param_1[0x205] = param_2[3];
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_0045ac21;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar7 = (undefined4 *)param_2[1];
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)&DAT_004d2404;
      }
      puVar8 = (undefined4 *)param_1[0x203];
      for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      param_1[0x204] = uVar1;
      *(undefined1 *)(param_1[0x203] + uVar1) = 0;
    }
  }
LAB_0045ac21:
  iVar6 = 0x100;
  puVar7 = param_1;
  do {
    *puVar7 = 0xffffffff;
    puVar7[1] = 0;
    puVar7 = puVar7 + 2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return param_1;
}

