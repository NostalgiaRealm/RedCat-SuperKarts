/*
 * FUN_00439490 at 00439490
 * undefined FUN_00439490(void)
 * Address ranges: 00439490-00439872
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00439490(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  int local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 *local_28 [5];
  int local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  if (param_1 != param_2) {
    uVar5 = *(uint *)(param_1 + 0x2c);
    if (uVar5 < *(uint *)(param_2 + 0x2c)) {
      piVar7 = (int *)FUN_00439c00((int *)(param_2 + 4));
      local_48 = *piVar7;
      local_44 = (undefined4 *)piVar7[1];
      local_40 = (undefined4 *)piVar7[2];
      local_3c = piVar7[3];
      FUN_0043a020(uVar5);
      local_4c = *(undefined4 *)(param_2 + 0x10);
      local_54 = *(undefined4 **)(param_2 + 8);
      local_38 = *(int *)(param_2 + 4);
      local_30 = *(undefined4 **)(param_2 + 0xc);
      local_10 = *(undefined4 **)(param_1 + 4);
      local_c = *(undefined4 **)(param_1 + 8);
      local_8 = *(undefined4 **)(param_1 + 0xc);
      local_28[3] = *(undefined4 **)(param_1 + 0x10);
      local_34 = local_54;
      local_2c = local_4c;
      if (local_30 != local_40) {
        do {
          *local_8 = *local_30;
          local_8 = local_8 + 1;
          if (local_8 == local_c) {
            local_28[3] = local_28[3] + 1;
            local_8 = (undefined4 *)*local_28[3];
            local_c = local_8 + 0x400;
            local_10 = local_8;
          }
          FUN_0043a400();
        } while (local_30 != local_40);
      }
      puVar2 = *(undefined4 **)(param_2 + 0x1c);
      local_4 = local_28[3];
      local_14 = param_1;
      piVar7 = &local_14;
      ppuVar9 = local_28;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppuVar9 = (undefined4 *)*piVar7;
        piVar7 = piVar7 + 1;
        ppuVar9 = ppuVar9 + 1;
      }
      local_14 = local_48;
      puVar8 = local_44;
      puVar3 = local_40;
      iVar4 = local_3c;
      if (local_40 != puVar2) {
        do {
          FUN_0043a440(puVar3);
          puVar3 = puVar3 + 1;
          if (puVar3 == puVar8) {
            puVar3 = *(undefined4 **)(iVar4 + 4);
            iVar4 = iVar4 + 4;
            puVar8 = puVar3 + 0x400;
          }
        } while (puVar3 != puVar2);
        return param_1;
      }
    }
    else {
      piVar7 = (int *)(param_1 + 4);
      local_38 = *piVar7;
      local_34 = *(undefined4 *)(param_1 + 8);
      local_50 = *(undefined4 **)(param_1 + 0xc);
      puVar2 = *(undefined4 **)(param_2 + 0xc);
      local_4c = *(undefined4 *)(param_1 + 0x10);
      local_48 = *(int *)(param_2 + 4);
      local_44 = *(undefined4 **)(param_2 + 8);
      local_3c = *(undefined4 *)(param_2 + 0x10);
      local_30 = local_50;
      local_2c = local_4c;
      puVar3 = (undefined4 *)FUN_00439c00(param_2 + 0x14);
      local_28[0] = (undefined4 *)*puVar3;
      local_28[1] = (undefined4 *)puVar3[1];
      puVar8 = (undefined4 *)puVar3[2];
      local_28[3] = (undefined4 *)puVar3[3];
      local_50 = puVar2;
      local_54 = local_44;
      local_58 = local_48;
      local_4c = local_3c;
      while (local_50 != puVar8) {
        *local_30 = *local_50;
        FUN_0043a400();
        FUN_0043a400();
      }
      piVar1 = (int *)(param_1 + 0x14);
      local_48 = *piVar1;
      local_44 = *(undefined4 **)(param_1 + 0x18);
      local_40 = *(undefined4 **)(param_1 + 0x1c);
      local_3c = *(undefined4 *)(param_1 + 0x20);
      local_58 = local_38;
      local_54 = (undefined4 *)local_34;
      local_50 = local_30;
      local_4c = local_2c;
      iVar4 = FUN_00439c20(&local_58);
      local_38 = *piVar7;
      local_34 = *(undefined4 *)(param_1 + 8);
      local_30 = *(undefined4 **)(param_1 + 0xc);
      local_2c = *(undefined4 *)(param_1 + 0x10);
      uVar5 = FUN_00439c20(&local_38);
      local_38 = *piVar1;
      local_34 = *(undefined4 *)(param_1 + 0x18);
      local_30 = *(undefined4 **)(param_1 + 0x1c);
      local_2c = *(undefined4 *)(param_1 + 0x20);
      uVar6 = FUN_00439c20(&local_48);
      if (uVar5 < uVar6) {
        FUN_0043a090(&local_14,*piVar7,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                     *(undefined4 *)(param_1 + 0x10),local_58,local_54,local_50,local_4c,local_48,
                     local_44,local_40,local_3c);
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          FUN_00438b80();
        }
      }
      else {
        FUN_0044bfc0(&local_14,local_48,local_44,local_40,local_3c,*piVar1,
                     *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                     *(undefined4 *)(param_1 + 0x20),local_58,local_54,local_50,local_4c);
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          FUN_00439ac0();
        }
      }
      if (uVar5 != 0) {
        local_38 = *piVar7;
        local_34 = *(undefined4 *)(param_1 + 8);
        local_30 = *(undefined4 **)(param_1 + 0xc);
        local_2c = *(undefined4 *)(param_1 + 0x10);
        FUN_0043a020(uVar5);
      }
    }
  }
  return param_1;
}

