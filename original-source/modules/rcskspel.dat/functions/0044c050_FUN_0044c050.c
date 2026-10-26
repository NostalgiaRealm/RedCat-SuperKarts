/*
 * FUN_0044c050 at 0044c050
 * undefined FUN_0044c050(void)
 * Address ranges: 0044c050-0044c512
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044c050(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,
                 undefined4 param_9,int param_10,undefined4 *param_11,undefined4 *param_12,
                 undefined4 *param_13,int param_14)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *local_130;
  undefined4 *local_12c;
  undefined4 *local_128;
  int local_124;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 *local_90;
  undefined4 *local_8c;
  undefined4 *local_88;
  int local_84;
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  iVar7 = param_10;
  if (param_4 != param_8) {
    piVar1 = (int *)(param_10 + 4);
    local_88 = param_13;
    local_90 = param_11;
    local_8c = param_12;
    do {
      local_84 = param_14;
      if (local_88 == *(undefined4 **)(iVar7 + 0xc)) {
        if ((*(int *)(iVar7 + 0x2c) == 0) || (*(int *)(iVar7 + 0xc) == *piVar1)) {
          FUN_0043afe0();
        }
        iVar2 = *(int *)(iVar7 + 0xc) + -4;
        *(int *)(iVar7 + 0xc) = iVar2;
        FUN_0043a120(iVar2,param_4);
        local_130 = (undefined4 *)*piVar1;
        *(int *)(iVar7 + 0x2c) = *(int *)(iVar7 + 0x2c) + 1;
        local_12c = *(undefined4 **)(iVar7 + 8);
        local_128 = *(undefined4 **)(iVar7 + 0xc);
        local_124 = *(int *)(iVar7 + 0x10);
      }
      else if (local_88 == *(undefined4 **)(iVar7 + 0x1c)) {
        FUN_0043a950(param_4);
        local_130 = *(undefined4 **)(iVar7 + 0x14);
        local_12c = *(undefined4 **)(iVar7 + 0x18);
        local_128 = *(undefined4 **)(iVar7 + 0x1c);
        local_124 = *(int *)(iVar7 + 0x20);
        FUN_0043a020(0xffffffff);
      }
      else {
        FUN_0043a8f0();
        local_b0 = *piVar1;
        local_ac = *(undefined4 *)(iVar7 + 8);
        local_a8 = *(undefined4 *)(iVar7 + 0xc);
        local_a4 = *(undefined4 *)(iVar7 + 0x10);
        uVar3 = FUN_00439c20(&local_b0);
        if (uVar3 < *(uint *)(iVar7 + 0x2c) >> 1) {
          FUN_0043adc0(*(undefined4 *)(iVar7 + 0xc));
          local_130 = (undefined4 *)*piVar1;
          local_12c = *(undefined4 **)(iVar7 + 8);
          local_128 = *(undefined4 **)(iVar7 + 0xc);
          local_124 = *(int *)(iVar7 + 0x10);
          FUN_0043a020(uVar3);
          local_a0 = *piVar1;
          local_9c = *(undefined4 *)(iVar7 + 8);
          local_98 = *(undefined4 *)(iVar7 + 0xc);
          local_94 = *(undefined4 *)(iVar7 + 0x10);
          puVar4 = (undefined4 *)FUN_0043ad60(local_80,1);
          uVar5 = *puVar4;
          uVar12 = puVar4[1];
          uVar13 = puVar4[2];
          uVar14 = puVar4[3];
          puVar4 = (undefined4 *)FUN_0043ad60(local_60,1);
          uVar8 = *puVar4;
          uVar9 = puVar4[1];
          uVar10 = puVar4[2];
          uVar11 = puVar4[3];
          puVar4 = (undefined4 *)FUN_0043ad60(local_20,2);
          FUN_0044bfc0(local_40,*puVar4,puVar4[1],puVar4[2],puVar4[3],uVar8,uVar9,uVar10,uVar11,
                       uVar5,uVar12,uVar13,uVar14);
        }
        else {
          uVar5 = FUN_0043a900();
          FUN_0043a950(uVar5);
          piVar6 = (int *)FUN_0043ad60(local_70,uVar3);
          local_130 = (undefined4 *)*piVar6;
          local_12c = (undefined4 *)piVar6[1];
          local_128 = (undefined4 *)piVar6[2];
          local_124 = piVar6[3];
          puVar4 = (undefined4 *)FUN_0043ac80(local_50,1);
          uVar5 = *puVar4;
          uVar12 = puVar4[1];
          uVar13 = puVar4[2];
          uVar14 = puVar4[3];
          puVar4 = (undefined4 *)FUN_0043ac80(local_30,2);
          FUN_0043a090(local_10,local_130,local_12c,local_128,local_124,*puVar4,puVar4[1],puVar4[2],
                       puVar4[3],uVar5,uVar12,uVar13,uVar14);
        }
        *local_128 = *param_4;
      }
      local_88 = local_128 + 1;
      param_14 = local_124;
      local_90 = local_130;
      if (local_88 == local_12c) {
        local_88 = *(undefined4 **)(local_124 + 4);
        param_14 = local_124 + 4;
        local_12c = local_88 + 0x400;
        local_90 = local_88;
      }
      param_4 = param_4 + 1;
      if (param_4 == param_3) {
        param_5 = param_5 + 1;
        param_4 = (undefined4 *)*param_5;
        param_3 = param_4 + 0x400;
      }
      local_8c = local_12c;
      param_13 = local_128;
    } while (param_4 != param_8);
    param_13 = local_88;
    param_12 = local_12c;
    param_11 = local_90;
  }
  puVar4 = &param_10;
  for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

