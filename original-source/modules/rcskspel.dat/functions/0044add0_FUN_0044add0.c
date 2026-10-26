/*
 * FUN_0044add0 at 0044add0
 * undefined FUN_0044add0(void)
 * Address ranges: 0044add0-0044af9e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044add0(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_2;
  puStack_8 = &LAB_004cd903;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 4);
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    FUN_00412870(param_2 + 4,0,0xffffffff);
    local_4._0_1_ = 1;
    *(undefined1 *)(param_1 + 5) = *(undefined1 *)(iVar1 + 0x14);
    FUN_0040b4f0(0);
    FUN_00412870(iVar1 + 0x14,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,2);
    *(undefined1 *)(param_1 + 9) = *(undefined1 *)(iVar1 + 0x24);
    if (*(int *)(iVar1 + 0x28) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x28)) / 0x60;
    }
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    pvVar2 = operator_new(iVar4 * 0x60);
    param_1[10] = pvVar2;
    iVar4 = *(int *)(iVar1 + 0x2c);
    iVar5 = *(int *)(iVar1 + 0x28);
    param_2 = iVar4;
    if (iVar5 != iVar4) {
      do {
        local_4 = CONCAT31(local_4._1_3_,3);
        if (pvVar2 != (void *)0x0) {
          FUN_0044c940(iVar5);
          iVar4 = param_2;
        }
        iVar5 = iVar5 + 0x60;
        pvVar2 = (void *)((int)pvVar2 + 0x60);
      } while (iVar5 != iVar4);
    }
    param_1[0xb] = pvVar2;
    param_1[0xc] = pvVar2;
    puVar10 = param_1 + 0xd;
    local_4 = CONCAT31(local_4._1_3_,4);
    *(undefined1 *)puVar10 = *(undefined1 *)(iVar1 + 0x34);
    FUN_0043a8f0();
    FUN_0043a8f0();
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    puVar3 = (undefined4 *)FUN_00439c00(iVar1 + 0x48);
    uVar6 = *puVar3;
    uVar7 = puVar3[1];
    uVar8 = puVar3[2];
    uVar9 = puVar3[3];
    puVar3 = (undefined4 *)FUN_00439c00(iVar1 + 0x38);
    FUN_0044bdd0(&param_2,*puVar3,puVar3[1],puVar3[2],puVar3[3],uVar6,uVar7,uVar8,uVar9,puVar10);
    uVar6 = *(undefined4 *)(iVar1 + 100);
    *param_1 = &PTR_FUN_004d2720;
    param_1[0x19] = uVar6;
    param_1[0x1a] = *(undefined4 *)(iVar1 + 0x68);
    param_1[0x1b] = *(undefined4 *)(iVar1 + 0x6c);
    param_1[0x1c] = *(undefined4 *)(iVar1 + 0x70);
    param_1[0x1d] = *(undefined4 *)(iVar1 + 0x74);
    *param_1 = &PTR_FUN_004d2710;
  }
  ExceptionList = local_c;
  return;
}

