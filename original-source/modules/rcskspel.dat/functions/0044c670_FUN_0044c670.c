/*
 * FUN_0044c670 at 0044c670
 * undefined FUN_0044c670(void)
 * Address ranges: 0044c670-0044c93b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044c6cd) */
/* WARNING: Removing unreachable block (ram,0x0044c792) */

undefined4 * __thiscall FUN_0044c670(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  *(undefined1 *)(param_1 + 7) = *(undefined1 *)(param_2 + 7);
  FUN_00412870(param_2 + 8,0,0xffffffff);
  uVar2 = param_2[0xe];
  if (param_1 + 0xc == param_2 + 0xc) {
    FUN_004478a0(uVar2,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar2 != 0) {
      puVar8 = (undefined1 *)param_2[0xd];
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_004d2404;
      }
      if ((byte)puVar8[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar8 = (undefined1 *)param_2[0xd];
        if (puVar8 == (undefined1 *)0x0) {
          puVar8 = &DAT_004d2404;
        }
        param_1[0xd] = puVar8;
        param_1[0xe] = param_2[0xe];
        param_1[0xf] = param_2[0xf];
        puVar8[-1] = puVar8[-1] + '\x01';
        goto LAB_0044c77e;
      }
    }
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 != '\0') {
      puVar9 = (undefined4 *)param_2[0xd];
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)&DAT_004d2404;
      }
      puVar10 = (undefined4 *)param_1[0xd];
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      FUN_0040b5e0(uVar2);
    }
  }
LAB_0044c77e:
  uVar2 = param_2[0x12];
  if (param_1 + 0x10 == param_2 + 0x10) {
    FUN_004478a0(uVar2,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar2 != 0) {
      puVar8 = (undefined1 *)param_2[0x11];
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_004d2404;
      }
      if ((byte)puVar8[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar8 = (undefined1 *)param_2[0x11];
        if (puVar8 == (undefined1 *)0x0) {
          puVar8 = &DAT_004d2404;
        }
        param_1[0x11] = puVar8;
        param_1[0x12] = param_2[0x12];
        param_1[0x13] = param_2[0x13];
        puVar8[-1] = puVar8[-1] + '\x01';
        goto LAB_0044c843;
      }
    }
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 != '\0') {
      puVar9 = (undefined4 *)param_2[0x11];
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)&DAT_004d2404;
      }
      puVar10 = (undefined4 *)param_1[0x11];
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      FUN_0040b5e0(uVar2);
    }
  }
LAB_0044c843:
  if (param_1 + 0x14 == param_2 + 0x14) {
    return param_1;
  }
  uVar2 = FUN_0044ca80();
  uVar3 = FUN_0044ca80();
  if (uVar2 < uVar3) {
    uVar2 = FUN_00477770();
    uVar3 = FUN_0044ca80();
    if (uVar2 < uVar3) {
      FUN_0048b600(param_1[0x15],param_1[0x16]);
      FUN_004bc150(param_1[0x15]);
      iVar6 = FUN_0044ca80();
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      pvVar7 = operator_new(iVar6 * 4);
      param_1[0x15] = pvVar7;
      uVar4 = FUN_00476950(param_2[0x15],param_2[0x16],pvVar7);
      param_1[0x16] = uVar4;
      param_1[0x17] = uVar4;
      return param_1;
    }
    iVar6 = param_2[0x15];
    iVar5 = FUN_0044ca80();
    iVar6 = iVar6 + iVar5 * 4;
    FUN_0043afb0(param_2[0x15],iVar6,param_1[0x15]);
    FUN_00476950(iVar6,param_2[0x16],param_1[0x16]);
  }
  else {
    uVar4 = FUN_0043afb0(param_2[0x15],param_2[0x16],param_1[0x15]);
    FUN_0048b600(uVar4,param_1[0x16]);
  }
  iVar6 = FUN_0044ca80();
  param_1[0x16] = param_1[0x15] + iVar6 * 4;
  return param_1;
}

