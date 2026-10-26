/*
 * FUN_0048bcb0 at 0048bcb0
 * undefined FUN_0048bcb0(void)
 * Address ranges: 0048bcb0-0048bf1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048bcb0(undefined4 *param_1,int param_2)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d1561;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    *param_1 = &PTR_FUN_004d2fc4;
    puVar3 = operator_new(0x10);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(puVar3 + 4) = 0;
      *puVar3 = (undefined1)param_2;
      *(undefined4 *)(puVar3 + 8) = 0;
      *(undefined4 *)(puVar3 + 0xc) = 0;
    }
    param_1[1] = puVar3;
    puVar1 = *(undefined1 **)(param_2 + 4);
    if (puVar3 != puVar1) {
      puVar11 = *(undefined4 **)(puVar1 + 4);
      if (puVar11 == (undefined4 *)0x0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *(int *)(puVar1 + 8) - (int)puVar11 >> 5;
      }
      puVar13 = *(undefined4 **)(puVar3 + 4);
      if (puVar13 == (undefined4 *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(int *)(puVar3 + 8) - (int)puVar13 >> 5;
      }
      if (uVar7 < uVar9) {
        uVar9 = FUN_0048bf20();
        uVar7 = FUN_0048b1b0();
        if (uVar9 < uVar7) {
          FUN_0048b600(*(undefined4 *)(puVar3 + 4),*(undefined4 *)(puVar3 + 8));
          FUN_004bc150(*(undefined4 *)(puVar3 + 4));
          iVar8 = FUN_0048b1b0();
          if (iVar8 < 0) {
            iVar8 = 0;
          }
          pvVar5 = operator_new(iVar8 << 5);
          *(void **)(puVar3 + 4) = pvVar5;
          uVar6 = FUN_0048ba30(*(undefined4 *)(puVar1 + 4),*(undefined4 *)(puVar1 + 8),pvVar5);
          *(undefined4 *)(puVar3 + 8) = uVar6;
          *(undefined4 *)(puVar3 + 0xc) = uVar6;
        }
        else {
          iVar8 = *(int *)(puVar1 + 4);
          iVar4 = FUN_0048b1b0();
          iVar8 = iVar4 * 0x20 + iVar8;
          FUN_0048bf40(*(undefined4 *)(puVar1 + 4),iVar8,*(undefined4 *)(puVar3 + 4));
          FUN_0048ba30(iVar8,*(undefined4 *)(puVar1 + 8),*(undefined4 *)(puVar3 + 8));
          iVar8 = FUN_0048b1b0();
          *(int *)(puVar3 + 8) = iVar8 * 0x20 + *(int *)(puVar3 + 4);
        }
      }
      else {
        puVar2 = *(undefined4 **)(puVar1 + 8);
        while (puVar11 != puVar2) {
          puVar10 = puVar11;
          puVar12 = puVar13;
          for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          puVar13 = puVar13 + 8;
          puVar11 = puVar11 + 8;
        }
        if (*(int *)(puVar1 + 4) == 0) {
          *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(puVar3 + 4);
        }
        else {
          *(int *)(puVar3 + 8) =
               (*(int *)(puVar1 + 8) - *(int *)(puVar1 + 4) >> 5) * 0x20 + *(int *)(puVar3 + 4);
        }
      }
    }
    puVar11 = (undefined4 *)(param_2 + 8);
    puVar13 = param_1 + 2;
    for (iVar8 = 0x38; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar13 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar13 = puVar13 + 1;
    }
    param_1[0x3a] = *(undefined4 *)(param_2 + 0xe8);
    *(undefined1 *)(param_1 + 0x3b) = *(undefined1 *)(param_2 + 0xec);
    param_1[0x3c] = *(undefined4 *)(param_2 + 0xf0);
    param_1[0x3d] = *(undefined4 *)(param_2 + 0xf4);
    param_1[0x3e] = *(undefined4 *)(param_2 + 0xf8);
    param_1[0x3f] = *(undefined4 *)(param_2 + 0xfc);
    *(undefined1 *)(param_1 + 0x40) = *(undefined1 *)(param_2 + 0x100);
    *(undefined1 *)((int)param_1 + 0x101) = *(undefined1 *)(param_2 + 0x101);
    *(undefined1 *)((int)param_1 + 0x102) = *(undefined1 *)(param_2 + 0x102);
    param_1[0x41] = *(undefined4 *)(param_2 + 0x104);
    *(undefined1 *)(param_1 + 0x42) = *(undefined1 *)(param_2 + 0x108);
    param_1[0x43] = *(undefined4 *)(param_2 + 0x10c);
    param_1[0x44] = *(undefined4 *)(param_2 + 0x110);
    param_1[0x45] = *(undefined4 *)(param_2 + 0x114);
    param_1[0x46] = *(undefined4 *)(param_2 + 0x118);
    *(undefined1 *)(param_1 + 0x47) = *(undefined1 *)(param_2 + 0x11c);
  }
  ExceptionList = local_c;
  return;
}

