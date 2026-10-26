/*
 * FUN_0044dfe0 at 0044dfe0
 * undefined FUN_0044dfe0(void)
 * Address ranges: 0044dfe0-0044e43c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0044dfe0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int local_84 [4];
  uint local_5c;
  int local_38 [4];
  undefined4 local_28;
  undefined1 local_24 [20];
  undefined1 local_10 [16];
  
  local_84[3] = 0;
  local_84[2] = param_2 + 4;
  local_84[1] = 0x44e001;
  FUN_00412870();
  local_84[2] = param_2 + 0x14;
  local_84[3] = 0;
  local_84[1] = 0x44e011;
  FUN_00412870();
  if (param_1 + 0x24 != param_2 + 0x24) {
    if (*(int *)(param_2 + 0x28) == 0) {
      local_5c = 0;
    }
    else {
      local_5c = (*(int *)(param_2 + 0x2c) - *(int *)(param_2 + 0x28)) / 0x60;
    }
    iVar10 = *(int *)(param_1 + 0x28);
    if (iVar10 == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (*(int *)(param_1 + 0x2c) - iVar10) / 0x60;
    }
    if (uVar8 < local_5c) {
      uVar8 = FUN_0044b7a0();
      uVar3 = FUN_0044b770();
      if (uVar3 < uVar8) {
        local_84[3] = *(undefined4 *)(param_1 + 0x28);
        local_84[2] = 0x44e157;
        FUN_0044aa50();
        local_84[3] = 0x44e160;
        FUN_004bc150();
        iVar10 = FUN_0044b7a0();
        if (iVar10 < 0) {
          iVar10 = 0;
        }
        local_84[3] = 0x44e17c;
        pvVar4 = operator_new(iVar10 * 0x60);
        *(void **)(param_1 + 0x28) = pvVar4;
        local_84[3] = *(undefined4 *)(param_2 + 0x2c);
        local_84[2] = *(int *)(param_2 + 0x28);
        local_84[1] = 0x44e192;
        uVar5 = FUN_0044b7d0();
        *(undefined4 *)(param_1 + 0x2c) = uVar5;
        *(undefined4 *)(param_1 + 0x30) = uVar5;
      }
      else {
        iVar10 = *(int *)(param_2 + 0x28);
        iVar7 = FUN_0044b7a0();
        local_84[2] = *(undefined4 *)(param_2 + 0x28);
        iVar10 = iVar7 * 0x60 + iVar10;
        local_84[1] = 0x44e11e;
        local_84[3] = iVar10;
        FUN_0044bb50();
        local_84[3] = *(undefined4 *)(param_2 + 0x2c);
        local_84[1] = 0x44e131;
        local_84[2] = iVar10;
        FUN_0044b7d0();
        iVar10 = FUN_0044b7a0();
        *(int *)(param_1 + 0x2c) = iVar10 * 0x60 + *(int *)(param_1 + 0x28);
      }
    }
    else {
      iVar7 = *(int *)(param_2 + 0x2c);
      for (iVar9 = *(int *)(param_2 + 0x28); iVar9 != iVar7; iVar9 = iVar9 + 0x60) {
        local_84[3] = 0x44e085;
        FUN_0044c670();
        iVar10 = iVar10 + 0x60;
      }
      iVar7 = *(int *)(param_1 + 0x2c);
      for (; iVar10 != iVar7; iVar10 = iVar10 + 0x60) {
        local_84[3] = 0x44e0a3;
        FUN_0044b410();
      }
      if (*(int *)(param_2 + 0x28) == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = (*(int *)(param_2 + 0x2c) - *(int *)(param_2 + 0x28)) / 0x60;
      }
      *(int *)(param_1 + 0x2c) = iVar10 * 0x60 + *(int *)(param_1 + 0x28);
    }
  }
  if (param_1 + 0x34 != param_2 + 0x34) {
    FUN_0043a8f0();
    if (*(uint *)(param_1 + 0x60) < *(uint *)(param_2 + 0x60)) {
      local_84[3] = 0x44e2d6;
      puVar6 = (undefined4 *)FUN_00439c00();
      uVar5 = *puVar6;
      uVar1 = puVar6[1];
      uVar2 = puVar6[2];
      iVar10 = puVar6[3];
      local_84[3] = 0x44e2fb;
      FUN_0043a020();
      local_84[1] = *(undefined4 *)(param_1 + 0x38);
      local_84[2] = *(undefined4 *)(param_1 + 0x3c);
      local_84[3] = *(undefined4 *)(param_1 + 0x40);
      local_38[3] = *(undefined4 *)(param_1 + 0x44);
      uVar13 = uVar5;
      uVar14 = uVar1;
      uVar15 = uVar2;
      local_84[0] = iVar10;
      puVar6 = (undefined4 *)FUN_00439c00(param_2 + 0x38);
      puVar6 = (undefined4 *)
               FUN_0044bfc0(local_24,*puVar6,puVar6[1],puVar6[2],puVar6[3],uVar13,uVar14,uVar15);
      local_38[0] = param_1 + 0x34;
      local_38[1] = *puVar6;
      local_38[2] = puVar6[1];
      local_38[3] = puVar6[2];
      local_28 = puVar6[3];
      piVar11 = local_38;
      piVar12 = local_84;
      for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar12 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar12 = piVar12 + 1;
      }
      puVar6 = (undefined4 *)FUN_00439c00(param_2 + 0x48);
      FUN_0044c050(local_24,uVar5,uVar1,uVar2,iVar10,*puVar6,puVar6[1],puVar6[2],puVar6[3]);
    }
    else {
      uVar5 = *(undefined4 *)(param_1 + 0x38);
      uVar1 = *(undefined4 *)(param_1 + 0x3c);
      uVar2 = *(undefined4 *)(param_1 + 0x40);
      local_84[3] = 0x44e1e5;
      puVar6 = (undefined4 *)FUN_00439c00();
      uVar13 = *puVar6;
      uVar14 = puVar6[1];
      uVar15 = puVar6[2];
      local_84[0] = puVar6[3];
      local_84[1] = uVar5;
      local_84[2] = uVar1;
      local_84[3] = uVar2;
      local_38[1] = uVar14;
      local_38[3] = local_84[0];
      puVar6 = (undefined4 *)FUN_00439c00(param_2 + 0x38);
      puVar6 = (undefined4 *)
               FUN_0044bfc0(local_10,*puVar6,puVar6[1],puVar6[2],puVar6[3],uVar13,uVar14,uVar15);
      local_84[1] = *(undefined4 *)(param_1 + 0x48);
      local_84[2] = *(undefined4 *)(param_1 + 0x4c);
      local_84[3] = *(undefined4 *)(param_1 + 0x50);
      local_84[0] = puVar6[3];
      FUN_0044b810(local_10,*puVar6,puVar6[1],puVar6[2]);
    }
  }
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
  return param_1;
}

