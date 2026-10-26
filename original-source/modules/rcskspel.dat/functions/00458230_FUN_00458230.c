/*
 * FUN_00458230 at 00458230
 * undefined FUN_00458230(void)
 * Address ranges: 00458230-004583ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00458291) */

undefined4 * __thiscall FUN_00458230(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0x3f800000;
  param_1[5] = 0x3f800000;
  param_1[6] = 0x3f800000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0xffffffff;
  *(undefined1 *)(param_1 + 0xb) = param_3;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)param_2;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  uVar1 = param_2[2];
  if (param_1 + 0xd == param_2) {
    if (uVar1 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = param_1[0xf] - uVar1;
    iVar7 = -1;
    if (iVar3 != -1) {
      iVar7 = iVar3;
    }
    if (iVar7 != 0) {
      FUN_004bef90(uVar1 + param_1[0xe],uVar1 + param_1[0xe] + iVar7,iVar3 - iVar7);
      iVar3 = param_1[0xf];
      cVar2 = FUN_0040b600(iVar3 - iVar7,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar3 - iVar7);
      }
    }
    FUN_004478a0(0,0);
    *param_1 = &PTR_FUN_004d2804;
    return param_1;
  }
  if (uVar1 != 0) {
    puVar4 = (undefined1 *)param_2[1];
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    if ((byte)puVar4[-1] < 0xfe) {
      param_1[0xe] = 0;
      param_1[0xf] = 0;
      param_1[0x10] = 0;
      puVar4 = (undefined1 *)param_2[1];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      param_1[0xe] = puVar4;
      param_1[0xf] = param_2[2];
      param_1[0x10] = param_2[3];
      puVar4[-1] = puVar4[-1] + '\x01';
      *param_1 = &PTR_FUN_004d2804;
      return param_1;
    }
  }
  cVar2 = FUN_0040b600(uVar1,1);
  if (cVar2 != '\0') {
    puVar6 = (undefined4 *)&DAT_004d2404;
    if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
      puVar6 = (undefined4 *)param_2[1];
    }
    puVar8 = (undefined4 *)param_1[0xe];
    for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    FUN_0040b5e0(uVar1);
  }
  *param_1 = &PTR_FUN_004d2804;
  return param_1;
}

