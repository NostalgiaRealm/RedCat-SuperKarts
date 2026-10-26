/*
 * FUN_0047fce0 at 0047fce0
 * undefined FUN_0047fce0(void)
 * Address ranges: 0047fce0-0047fe32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0047fd01) */

void __thiscall FUN_0047fce0(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined1 local_c [4];
  int local_8;
  undefined1 local_4 [4];
  
  uVar1 = *(uint *)(param_2 + 8);
  local_8 = param_1;
  if (param_1 + 0x34 == param_2) {
    if (*(uint *)(param_1 + 0x3c) < uVar1) {
      FUN_004bc243();
    }
    FUN_00412a80();
    iVar3 = *(int *)(param_1 + 0x3c) - uVar1;
    iVar8 = -1;
    if (iVar3 != -1) {
      iVar8 = iVar3;
    }
    if (iVar8 != 0) {
      iVar5 = *(int *)(param_1 + 0x38) + uVar1;
      FUN_004bef90(iVar5,iVar5 + iVar8,iVar3 - iVar8);
      iVar8 = *(int *)(param_1 + 0x3c) - iVar8;
      cVar2 = FUN_0040b600(iVar8,0);
      if (cVar2 != '\0') {
        FUN_0040b5e0(iVar8);
      }
    }
    FUN_004478a0(0,0);
  }
  else {
    if (uVar1 != 0) {
      puVar10 = *(undefined1 **)(param_2 + 4);
      if (puVar10 == (undefined1 *)0x0) {
        puVar10 = &DAT_004d2404;
      }
      if ((byte)puVar10[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar10 = *(undefined1 **)(param_2 + 4);
        if (puVar10 == (undefined1 *)0x0) {
          puVar10 = &DAT_004d2404;
        }
        *(undefined1 **)(param_1 + 0x38) = puVar10;
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0xc);
        puVar10[-1] = puVar10[-1] + '\x01';
        goto LAB_0047fdee;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar7 = (undefined4 *)&DAT_004d2404;
      if (*(undefined4 **)(param_2 + 4) != (undefined4 *)0x0) {
        puVar7 = *(undefined4 **)(param_2 + 4);
      }
      puVar9 = *(undefined4 **)(param_1 + 0x38);
      for (uVar6 = uVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_0040b5e0(uVar1);
    }
  }
LAB_0047fdee:
  puVar10 = *(undefined1 **)(param_2 + 4);
  if (puVar10 == (undefined1 *)0x0) {
    puVar10 = &DAT_004d2404;
  }
  FUN_004b27f0(puVar10,local_c,local_4);
  uVar4 = __ftol();
  iVar8 = local_8;
  *(undefined4 *)(local_8 + 0x44) = uVar4;
  uVar4 = __ftol();
  *(undefined4 *)(iVar8 + 0x48) = uVar4;
  return;
}

