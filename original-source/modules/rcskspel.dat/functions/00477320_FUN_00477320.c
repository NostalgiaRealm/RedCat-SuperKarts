/*
 * FUN_00477320 at 00477320
 * undefined FUN_00477320(void)
 * Address ranges: 00477320-004775d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0047737b) */
/* WARNING: Removing unreachable block (ram,0x00477434) */

int __thiscall FUN_00477320(int param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  FUN_00412870(param_2,0,0xffffffff);
  FUN_00412870(param_2 + 0x10,0,0xffffffff);
  FUN_00412870(param_2 + 0x20,0,0xffffffff);
  uVar3 = *(uint *)(param_2 + 0x38);
  if (param_1 + 0x30 == param_2 + 0x30) {
    FUN_004478a0(uVar3,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar3 != 0) {
      puVar2 = *(undefined1 **)(param_2 + 0x34);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      if ((byte)puVar2[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar2 = *(undefined1 **)(param_2 + 0x34);
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 0x34) = puVar2;
        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
        puVar2[-1] = puVar2[-1] + '\x01';
        goto LAB_0047741b;
      }
    }
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      puVar9 = *(undefined4 **)(param_2 + 0x34);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)&DAT_004d2404;
      }
      puVar10 = *(undefined4 **)(param_1 + 0x34);
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      FUN_0040b5e0(uVar3);
    }
  }
LAB_0047741b:
  uVar3 = *(uint *)(param_2 + 0x48);
  if (param_1 + 0x40 == param_2 + 0x40) {
    FUN_004478a0(uVar3,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar3 != 0) {
      puVar2 = *(undefined1 **)(param_2 + 0x44);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      if ((byte)puVar2[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar2 = *(undefined1 **)(param_2 + 0x44);
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 0x44) = puVar2;
        *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
        *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
        puVar2[-1] = puVar2[-1] + '\x01';
        goto LAB_004774cd;
      }
    }
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      puVar9 = *(undefined4 **)(param_2 + 0x44);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)&DAT_004d2404;
      }
      puVar10 = *(undefined4 **)(param_1 + 0x44);
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      FUN_0040b5e0(uVar3);
    }
  }
LAB_004774cd:
  if (param_1 + 0x50 == param_2 + 0x50) {
    return param_1;
  }
  uVar3 = FUN_0044ca80();
  uVar4 = FUN_0044ca80();
  if (uVar4 < uVar3) {
    uVar3 = FUN_0044ca80();
    uVar4 = FUN_00477770();
    if (uVar4 < uVar3) {
      FUN_0048b600(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58));
      FUN_004bc150(*(undefined4 *)(param_1 + 0x54));
      iVar7 = FUN_0044ca80();
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      pvVar8 = operator_new(iVar7 * 4);
      *(void **)(param_1 + 0x54) = pvVar8;
      uVar5 = FUN_00476950(*(undefined4 *)(param_2 + 0x54),*(undefined4 *)(param_2 + 0x58),pvVar8);
      *(undefined4 *)(param_1 + 0x58) = uVar5;
      *(undefined4 *)(param_1 + 0x5c) = uVar5;
      return param_1;
    }
    iVar7 = *(int *)(param_2 + 0x54);
    iVar6 = FUN_0044ca80();
    iVar7 = iVar7 + iVar6 * 4;
    FUN_0043afb0(*(undefined4 *)(param_2 + 0x54),iVar7,*(undefined4 *)(param_1 + 0x54));
    FUN_00476950(iVar7,*(undefined4 *)(param_2 + 0x58),*(undefined4 *)(param_1 + 0x58));
  }
  else {
    uVar5 = FUN_0043afb0(*(undefined4 *)(param_2 + 0x54),*(undefined4 *)(param_2 + 0x58),
                         *(undefined4 *)(param_1 + 0x54));
    FUN_0048b600(uVar5,*(undefined4 *)(param_1 + 0x58));
  }
  iVar7 = FUN_0044ca80();
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x54) + iVar7 * 4;
  return param_1;
}

