/*
 * FUN_0043a440 at 0043a440
 * undefined FUN_0043a440(void)
 * Address ranges: 0043a440-0043a8e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __thiscall FUN_0043a440(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int local_148;
  int local_144;
  undefined4 *local_140;
  int local_13c;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [16];
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  piVar1 = param_1 + 1;
  iVar2 = *param_1;
  piVar4 = (int *)(iVar2 + 4);
  if (param_1[3] == *(int *)(iVar2 + 0xc)) {
    if ((*(int *)(iVar2 + 0x2c) == 0) || (*(int *)(iVar2 + 0xc) == *piVar4)) {
      FUN_0043afe0();
    }
    iVar3 = *(int *)(iVar2 + 0xc) + -4;
    *(int *)(iVar2 + 0xc) = iVar3;
    FUN_0043a120(iVar3,param_2);
    local_144 = *(int *)(iVar2 + 8);
    local_140 = *(undefined4 **)(iVar2 + 0xc);
    *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
    local_148 = *piVar4;
    local_13c = *(int *)(iVar2 + 0x10);
    goto LAB_0043a89a;
  }
  if (param_1[3] != *(int *)(iVar2 + 0x1c)) {
    FUN_0043a8f0();
    local_b0 = *piVar4;
    local_ac = *(undefined4 *)(iVar2 + 8);
    local_a8 = *(undefined4 *)(iVar2 + 0xc);
    local_a4 = *(undefined4 *)(iVar2 + 0x10);
    uVar5 = FUN_00439c20(&local_b0);
    if (uVar5 < *(uint *)(iVar2 + 0x2c) >> 1) {
      FUN_0043adc0(*(undefined4 *)(iVar2 + 0xc));
      piVar4 = (int *)FUN_0043ad60(local_a0,uVar5);
      local_148 = *piVar4;
      local_144 = piVar4[1];
      local_140 = (undefined4 *)piVar4[2];
      local_13c = piVar4[3];
      puVar6 = (undefined4 *)FUN_0043ad60(local_40,1);
      uVar7 = *puVar6;
      uVar12 = puVar6[1];
      uVar13 = puVar6[2];
      uVar14 = puVar6[3];
      puVar6 = (undefined4 *)FUN_0043ad60(local_60,1);
      uVar8 = *puVar6;
      uVar9 = puVar6[1];
      uVar10 = puVar6[2];
      uVar11 = puVar6[3];
      puVar6 = (undefined4 *)FUN_0043ad60(local_20,2);
      FUN_0044bfc0(local_90,*puVar6,puVar6[1],puVar6[2],puVar6[3],uVar8,uVar9,uVar10,uVar11,uVar7,
                   uVar12,uVar13,uVar14);
    }
    else {
      uVar7 = FUN_0043a900();
      FUN_0043a950(uVar7);
      piVar4 = (int *)FUN_0043ad60(local_70,uVar5);
      local_148 = *piVar4;
      local_144 = piVar4[1];
      local_140 = (undefined4 *)piVar4[2];
      local_13c = piVar4[3];
      puVar6 = (undefined4 *)FUN_0043ac80(local_50,1);
      uVar7 = *puVar6;
      uVar12 = puVar6[1];
      uVar13 = puVar6[2];
      uVar14 = puVar6[3];
      puVar6 = (undefined4 *)FUN_0043ac80(local_30,2);
      FUN_0043a090(local_10,local_148,local_144,local_140,local_13c,*puVar6,puVar6[1],puVar6[2],
                   puVar6[3],uVar7,uVar12,uVar13,uVar14);
    }
    *local_140 = *param_2;
    goto LAB_0043a89a;
  }
  if (*(int *)(iVar2 + 0x2c) == 0) {
LAB_0043a531:
    FUN_004398f0();
    iVar3 = *(int *)(iVar2 + 0x1c);
    *(int *)(iVar2 + 0x1c) = iVar3 + 4;
LAB_0043a541:
    FUN_0043a120(iVar3,param_2);
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x1c);
    if (iVar3 == *(int *)(iVar2 + 0x18)) goto LAB_0043a531;
    *(int *)(iVar2 + 0x1c) = iVar3 + 4;
    if (iVar3 + 4 != *(int *)(iVar2 + 0x18)) goto LAB_0043a541;
    FUN_0043a120(iVar3,param_2);
    FUN_004398f0();
  }
  *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
  piVar4 = (int *)FUN_0043ac80(local_80,1);
  local_148 = *piVar4;
  local_144 = piVar4[1];
  local_140 = (undefined4 *)piVar4[2];
  local_13c = piVar4[3];
LAB_0043a89a:
  *piVar1 = local_148;
  param_1[2] = local_144;
  param_1[3] = (int)local_140;
  param_1[4] = local_13c;
  iVar2 = param_1[3];
  param_1[3] = iVar2 + 4;
  if (iVar2 + 4 == param_1[2]) {
    iVar2 = param_1[4];
    param_1[4] = iVar2 + 4;
    iVar2 = *(int *)(iVar2 + 4);
    *piVar1 = iVar2;
    param_1[3] = *piVar1;
    param_1[2] = iVar2 + 0x1000;
  }
  return param_1;
}

