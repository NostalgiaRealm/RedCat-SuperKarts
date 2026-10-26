/*
 * FUN_0044de40 at 0044de40
 * undefined FUN_0044de40(void)
 * Address ranges: 0044de40-0044dfd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044de40(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_2;
  puStack_8 = &LAB_004cda62;
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
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    FUN_00412870(iVar1 + 0x14,0,0xffffffff);
    local_4._0_1_ = 2;
    *(undefined1 *)(param_1 + 9) = *(undefined1 *)(iVar1 + 0x24);
    if (*(int *)(iVar1 + 0x28) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x28)) / 0x60;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x60);
    param_1[10] = pvVar3;
    uVar4 = FUN_0044b7d0(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x2c),pvVar3);
    param_1[0xb] = uVar4;
    param_1[0xc] = uVar4;
    puVar9 = param_1 + 0xd;
    local_4 = CONCAT31(local_4._1_3_,3);
    *(undefined1 *)puVar9 = *(undefined1 *)(iVar1 + 0x34);
    FUN_0043a8f0();
    FUN_0043a8f0();
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    puVar5 = (undefined4 *)FUN_00439c00(iVar1 + 0x48);
    uVar4 = *puVar5;
    uVar6 = puVar5[1];
    uVar7 = puVar5[2];
    uVar8 = puVar5[3];
    puVar5 = (undefined4 *)FUN_00439c00(iVar1 + 0x38);
    FUN_0044bdd0(&param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],uVar4,uVar6,uVar7,uVar8,puVar9);
    uVar4 = *(undefined4 *)(iVar1 + 100);
    *param_1 = &PTR_FUN_004d2720;
    param_1[0x19] = uVar4;
    param_1[0x1a] = *(undefined4 *)(iVar1 + 0x68);
    param_1[0x1b] = *(undefined4 *)(iVar1 + 0x6c);
    *param_1 = &PTR_FUN_004d272c;
  }
  ExceptionList = local_c;
  return;
}

