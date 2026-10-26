/*
 * FUN_0043a950 at 0043a950
 * undefined FUN_0043a950(void)
 * Address ranges: 0043a950-0043ac41
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0043a950(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x1c);
    if (puVar2 != *(undefined4 **)(param_1 + 0x18)) {
      *(undefined4 **)(param_1 + 0x1c) = puVar2 + 1;
      if (puVar2 + 1 == *(undefined4 **)(param_1 + 0x18)) {
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = *param_2;
        }
        pvVar4 = operator_new(0x1000);
        if (*(int *)(param_1 + 0x2c) == 0) {
          *(undefined4 *)(param_1 + 0x28) = 2;
          pvVar5 = operator_new(8);
          *(void **)(param_1 + 0x24) = pvVar5;
          *(void **)((int)pvVar5 + 4) = pvVar4;
          FUN_0043ac50((int)pvVar4 + 0x800,*(int *)(param_1 + 0x24) + 4);
          *(undefined4 *)(param_1 + 4) = local_10;
          *(undefined4 *)(param_1 + 8) = local_c;
          *(undefined4 *)(param_1 + 0xc) = local_8;
          *(undefined4 *)(param_1 + 0x10) = local_4;
          *(undefined4 *)(param_1 + 0x14) = local_10;
          *(undefined4 *)(param_1 + 0x18) = local_c;
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
          *(undefined4 *)(param_1 + 0x1c) = local_8;
          *(undefined4 *)(param_1 + 0x20) = local_4;
          return;
        }
        uVar3 = *(uint *)(param_1 + 0x20);
        if (uVar3 < (uint)(*(int *)(param_1 + 0x24) + -4 + *(int *)(param_1 + 0x28) * 4)) {
          *(undefined4 **)(param_1 + 0x20) = (undefined4 *)(uVar3 + 4);
          *(undefined4 *)(uVar3 + 4) = pvVar4;
          FUN_0043ac50(pvVar4,*(undefined4 *)(param_1 + 0x20));
          *(undefined4 *)(param_1 + 0x14) = local_10;
          *(undefined4 *)(param_1 + 0x18) = local_c;
          *(undefined4 *)(param_1 + 0x1c) = local_8;
          *(undefined4 *)(param_1 + 0x20) = local_4;
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
          return;
        }
        iVar6 = ((int)(uVar3 - *(int *)(param_1 + 0x10)) >> 2) + 1;
        iVar7 = FUN_0043acf0(iVar6 * 2);
        puVar2 = (undefined4 *)(iVar7 + iVar6 * 4);
        *puVar2 = pvVar4;
        FUN_0043ac50(*(undefined4 *)(param_1 + 0xc),iVar7);
        *(undefined4 *)(param_1 + 4) = local_10;
        *(undefined4 *)(param_1 + 8) = local_c;
        *(undefined4 *)(param_1 + 0xc) = local_8;
        *(undefined4 *)(param_1 + 0x10) = local_4;
        FUN_0043ac50(pvVar4,puVar2);
        *(undefined4 *)(param_1 + 0x14) = local_10;
        *(undefined4 *)(param_1 + 0x18) = local_c;
        *(undefined4 *)(param_1 + 0x1c) = local_8;
        *(undefined4 *)(param_1 + 0x20) = local_4;
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
        return;
      }
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = *param_2;
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
        return;
      }
      goto LAB_0043ac32;
    }
  }
  pvVar4 = operator_new(0x1000);
  if (*(int *)(param_1 + 0x2c) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    pvVar5 = operator_new(8);
    *(void **)(param_1 + 0x24) = pvVar5;
    *(void **)((int)pvVar5 + 4) = pvVar4;
    FUN_0043ac50((int)pvVar4 + 0x800,*(int *)(param_1 + 0x24) + 4);
    *(undefined4 *)(param_1 + 4) = local_10;
    *(undefined4 *)(param_1 + 8) = local_c;
    *(undefined4 *)(param_1 + 0xc) = local_8;
    *(undefined4 *)(param_1 + 0x10) = local_4;
    *(undefined4 *)(param_1 + 0x14) = local_10;
    *(undefined4 *)(param_1 + 0x18) = local_c;
    *(undefined4 *)(param_1 + 0x1c) = local_8;
    *(undefined4 *)(param_1 + 0x20) = local_4;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x20);
    if (uVar3 < (uint)(*(int *)(param_1 + 0x24) + -4 + *(int *)(param_1 + 0x28) * 4)) {
      *(undefined4 **)(param_1 + 0x20) = (undefined4 *)(uVar3 + 4);
      *(undefined4 *)(uVar3 + 4) = pvVar4;
      FUN_0043ac50(pvVar4,*(undefined4 *)(param_1 + 0x20));
      *(undefined4 *)(param_1 + 0x14) = local_10;
      *(undefined4 *)(param_1 + 0x18) = local_c;
      *(undefined4 *)(param_1 + 0x1c) = local_8;
      *(undefined4 *)(param_1 + 0x20) = local_4;
    }
    else {
      iVar6 = ((int)(uVar3 - *(int *)(param_1 + 0x10)) >> 2) + 1;
      iVar7 = FUN_0043acf0(iVar6 * 2);
      piVar1 = (int *)(iVar7 + iVar6 * 4);
      *piVar1 = (int)pvVar4;
      FUN_0043ac50(*(undefined4 *)(param_1 + 0xc),iVar7);
      *(undefined4 *)(param_1 + 4) = local_10;
      *(undefined4 *)(param_1 + 8) = local_c;
      *(undefined4 *)(param_1 + 0xc) = local_8;
      *(undefined4 *)(param_1 + 0x10) = local_4;
      iVar6 = *piVar1;
      *(int *)(param_1 + 0x14) = iVar6;
      *(int *)(param_1 + 0x18) = iVar6 + 0x1000;
      *(void **)(param_1 + 0x1c) = pvVar4;
      *(int **)(param_1 + 0x20) = piVar1;
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  *(undefined4 **)(param_1 + 0x1c) = puVar2 + 1;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *param_2;
  }
LAB_0043ac32:
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  return;
}

