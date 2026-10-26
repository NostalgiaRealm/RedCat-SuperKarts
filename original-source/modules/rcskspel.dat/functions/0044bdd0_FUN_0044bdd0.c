/*
 * FUN_0044bdd0 at 0044bdd0
 * undefined FUN_0044bdd0(void)
 * Address ranges: 0044bdd0-0044bfba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044bdd0(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,
                 undefined4 param_9,int param_10)

{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_4 == param_8) {
    *param_1 = param_10;
    return;
  }
  do {
    if (*(int *)(param_10 + 0x2c) == 0) {
LAB_0044be28:
      pvVar2 = operator_new(0x1000);
      if (*(int *)(param_10 + 0x2c) == 0) {
        *(undefined4 *)(param_10 + 0x28) = 2;
        pvVar3 = operator_new(8);
        *(void **)(param_10 + 0x24) = pvVar3;
        *(void **)((int)pvVar3 + 4) = pvVar2;
        FUN_0043ac50((int)pvVar2 + 0x800,*(int *)(param_10 + 0x24) + 4);
        *(undefined4 *)(param_10 + 4) = local_40;
        *(undefined4 *)(param_10 + 8) = local_3c;
        *(undefined4 *)(param_10 + 0xc) = local_38;
        *(undefined4 *)(param_10 + 0x10) = local_34;
        *(undefined4 *)(param_10 + 0x14) = local_40;
        *(undefined4 *)(param_10 + 0x18) = local_3c;
        *(undefined4 *)(param_10 + 0x1c) = local_38;
        *(undefined4 *)(param_10 + 0x20) = local_34;
      }
      else {
        uVar1 = *(uint *)(param_10 + 0x20);
        if (uVar1 < (uint)(*(int *)(param_10 + 0x24) + -4 + *(int *)(param_10 + 0x28) * 4)) {
          *(undefined4 **)(param_10 + 0x20) = (undefined4 *)(uVar1 + 4);
          *(undefined4 *)(uVar1 + 4) = pvVar2;
          FUN_0043ac50(pvVar2,*(undefined4 *)(param_10 + 0x20));
          *(undefined4 *)(param_10 + 0x14) = local_30;
          *(undefined4 *)(param_10 + 0x18) = local_2c;
          *(undefined4 *)(param_10 + 0x1c) = local_28;
          *(undefined4 *)(param_10 + 0x20) = local_24;
        }
        else {
          iVar4 = ((int)(uVar1 - *(int *)(param_10 + 0x10)) >> 2) + 1;
          iVar5 = FUN_0043acf0(iVar4 * 2);
          puVar6 = (undefined4 *)(iVar5 + iVar4 * 4);
          *puVar6 = pvVar2;
          FUN_0043ac50(*(undefined4 *)(param_10 + 0xc),iVar5);
          *(undefined4 *)(param_10 + 4) = local_20;
          *(undefined4 *)(param_10 + 8) = local_1c;
          *(undefined4 *)(param_10 + 0xc) = local_18;
          *(undefined4 *)(param_10 + 0x10) = local_14;
          FUN_0043ac50(pvVar2,puVar6);
          *(undefined4 *)(param_10 + 0x14) = local_10;
          *(undefined4 *)(param_10 + 0x18) = local_c;
          *(undefined4 *)(param_10 + 0x1c) = local_8;
          *(undefined4 *)(param_10 + 0x20) = local_4;
        }
      }
      puVar6 = *(undefined4 **)(param_10 + 0x1c);
      *(undefined4 **)(param_10 + 0x1c) = puVar6 + 1;
      if (puVar6 != (undefined4 *)0x0) {
LAB_0044bf64:
        *puVar6 = *param_4;
      }
    }
    else {
      puVar6 = *(undefined4 **)(param_10 + 0x1c);
      if (puVar6 == *(undefined4 **)(param_10 + 0x18)) goto LAB_0044be28;
      *(undefined4 **)(param_10 + 0x1c) = puVar6 + 1;
      if (puVar6 + 1 != *(undefined4 **)(param_10 + 0x18)) {
        if (puVar6 == (undefined4 *)0x0) goto LAB_0044bf69;
        goto LAB_0044bf64;
      }
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = *param_4;
      }
      FUN_004398f0();
    }
LAB_0044bf69:
    param_4 = param_4 + 1;
    *(int *)(param_10 + 0x2c) = *(int *)(param_10 + 0x2c) + 1;
    if (param_4 == param_3) {
      param_5 = param_5 + 1;
      param_4 = (undefined4 *)*param_5;
      param_3 = param_4 + 0x400;
    }
    if (param_4 == param_8) {
      *param_1 = param_10;
      return;
    }
  } while( true );
}

