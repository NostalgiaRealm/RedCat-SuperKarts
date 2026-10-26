/*
 * FUN_00469990 at 00469990
 * undefined FUN_00469990(void)
 * Address ranges: 00469990-00469b01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x004699f6) */

undefined4 * __thiscall FUN_00469990(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cfe88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00466e40(param_2,1);
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0xffffffff;
  local_4 = 0;
  *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)param_3;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  uVar1 = param_3[2];
  if (param_1 + 0x10 == param_3) {
    if (uVar1 != 0) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = param_1[0x12] - uVar1;
    iVar6 = -1;
    if (iVar3 != -1) {
      iVar6 = iVar3;
    }
    if (iVar6 != 0) {
      FUN_004bef90(uVar1 + param_1[0x11],uVar1 + param_1[0x11] + iVar6,iVar3 - iVar6);
      iVar3 = param_1[0x12];
      cVar2 = FUN_0040b600(iVar3 - iVar6,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar3 - iVar6);
      }
    }
    FUN_00412a80();
  }
  else {
    if (uVar1 != 0) {
      puVar4 = (undefined1 *)param_3[1];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = (undefined1 *)param_3[1];
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        param_1[0x11] = puVar4;
        param_1[0x12] = param_3[2];
        param_1[0x13] = param_3[3];
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_00469adc;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar7 = (undefined4 *)param_3[1];
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)&DAT_004d2404;
      }
      puVar8 = (undefined4 *)param_1[0x11];
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
      param_1[0x12] = uVar1;
      *(undefined1 *)(uVar1 + param_1[0x11]) = 0;
    }
  }
LAB_00469adc:
  *param_1 = &PTR_FUN_004d2d0c;
  param_1[10] = 0x43c80000;
  ExceptionList = local_c;
  return param_1;
}

