/*
 * FUN_0043adc0 at 0043adc0
 * undefined FUN_0043adc0(void)
 * Address ranges: 0043adc0-0043afa8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0043adc0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(param_1 + 0x2c) == 0) || (*(int *)(param_1 + 0xc) == *(int *)(param_1 + 4))) {
    pvVar4 = operator_new(0x1000);
    if (*(int *)(param_1 + 0x2c) == 0) {
      *(undefined4 *)(param_1 + 0x28) = 2;
      pvVar5 = operator_new(8);
      *(void **)(param_1 + 0x24) = pvVar5;
      *(void **)((int)pvVar5 + 4) = pvVar4;
      FUN_0043ac50((int)pvVar4 + 0x804,*(int *)(param_1 + 0x24) + 4);
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
      puVar8 = *(undefined4 **)(param_1 + 0x10);
      if (*(undefined4 **)(param_1 + 0x24) < puVar8) {
        *(undefined4 **)(param_1 + 0x10) = puVar8 + -1;
        puVar8[-1] = pvVar4;
        FUN_0043ac50((int)pvVar4 + 0x1000,*(undefined4 *)(param_1 + 0x10));
        *(undefined4 *)(param_1 + 4) = local_10;
        *(undefined4 *)(param_1 + 8) = local_c;
        *(undefined4 *)(param_1 + 0xc) = local_8;
        *(undefined4 *)(param_1 + 0x10) = local_4;
      }
      else {
        puVar2 = *(undefined4 **)(param_1 + 0x20);
        if (puVar2 == puVar8) {
          uVar3 = *puVar8;
          *(undefined4 **)(param_1 + 0x20) = puVar2 + 1;
          *puVar2 = uVar3;
          (*(undefined4 **)(param_1 + 0x10))[1] = **(undefined4 **)(param_1 + 0x10);
          **(undefined4 **)(param_1 + 0x10) = pvVar4;
          FUN_0043ac50((int)pvVar4 + 0x1000,*(undefined4 *)(param_1 + 0x10));
          *(undefined4 *)(param_1 + 4) = local_10;
          *(undefined4 *)(param_1 + 8) = local_c;
          *(undefined4 *)(param_1 + 0xc) = local_8;
          *(undefined4 *)(param_1 + 0x10) = local_4;
        }
        else {
          iVar6 = ((int)puVar2 - (int)puVar8 >> 2) + 1;
          uVar7 = iVar6 * 8;
          if ((int)uVar7 < 0) {
            uVar7 = 0;
          }
          pvVar5 = operator_new(uVar7);
          iVar1 = (int)pvVar5 + (iVar6 * 2 & 0xfffffffcU);
          FUN_0043afb0(*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x20) + 4,iVar1);
          FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
          *(void **)(param_1 + 0x24) = pvVar5;
          *(int *)(param_1 + 0x28) = iVar6 * 2;
          puVar8 = (undefined4 *)(iVar1 + -4);
          *puVar8 = pvVar4;
          *(void **)(param_1 + 4) = pvVar4;
          *(int *)(param_1 + 8) = (int)pvVar4 + 0x1000;
          *(int *)(param_1 + 0xc) = (int)pvVar4 + 0x1000;
          *(undefined4 **)(param_1 + 0x10) = puVar8;
          iVar1 = puVar8[iVar6];
          *(int *)(param_1 + 0x14) = iVar1;
          *(int *)(param_1 + 0x18) = iVar1 + 0x1000;
          *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
          *(undefined4 **)(param_1 + 0x20) = puVar8 + iVar6;
        }
      }
    }
  }
  puVar8 = (undefined4 *)(*(int *)(param_1 + 0xc) + -4);
  *(undefined4 **)(param_1 + 0xc) = puVar8;
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = *param_2;
  }
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  return;
}

