/*
 * FUN_00499c30 at 00499c30
 * undefined FUN_00499c30(void)
 * Address ranges: 00499c30-0049a112
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00499c30(int param_1,uint *param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  float10 fVar8;
  float local_b8;
  int local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  uint local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  undefined4 local_90;
  float local_8c;
  float local_88;
  undefined4 local_84;
  float local_80;
  float local_78;
  float local_74;
  float local_6c;
  float local_68;
  float local_5c;
  undefined1 local_58 [48];
  float local_28;
  float local_24;
  float local_20;
  uint local_14;
  float local_4;
  
  local_b8 = 1.0;
  local_a4 = 0;
  FUN_0049c6d0();
  _DAT_00680b78 = 0;
  iVar6 = param_1 * 0xd0;
  if (((*(float *)(iVar6 + 0x9c + DAT_0067ee20) == 0.0) &&
      (*(float *)(iVar6 + 0xa4 + DAT_0067ee20) == 0.0)) &&
     (*(float *)(iVar6 + 0xac + DAT_0067ee20) == 0.0)) {
    *param_2 = 1;
    return (float10)0.0;
  }
  if (*(int *)(iVar6 + 0x44 + DAT_0067ee20) != 0) {
    DAT_006847c8 = 0;
    FUN_00499b20();
    FUN_004999c0(param_1,local_58);
    local_b4 = 0;
    uVar5 = 0;
    if (0 < DAT_006847c8) {
      local_90 = 0;
      puVar7 = &DAT_00680c68;
      do {
        iVar3 = (DAT_004fc8f8 & local_14 - *(int *)(puVar7 + 0x44)) * 4;
        pfVar1 = (float *)(iVar6 + 0xa4 + DAT_0067ee20);
        local_84 = local_90;
        local_4 = *(float *)(iVar3 + DAT_006a5cd0) * *pfVar1 +
                  *(float *)(iVar3 + DAT_006a5c88) * *(float *)(iVar6 + 0x9c + DAT_0067ee20);
        _DAT_006847cc = 0;
        _DAT_00680b78 = 0;
        local_5c = local_4 * param_3;
        local_94 = (*(float *)(iVar3 + DAT_006a5cd0) * *(float *)(iVar6 + 0x9c + DAT_0067ee20) -
                   *(float *)(iVar3 + DAT_006a5c88) * *pfVar1) * param_3 * 10.0;
        local_8c = local_5c * 10.0;
        local_88 = local_94;
        local_80 = local_8c;
        fVar8 = (float10)FUN_0049a120(puVar7,local_58,&local_88);
        if (fVar8 < (float10)local_b8) {
          if (((*(byte *)(iVar6 + 4 + DAT_0067ee20) & 4) == 0) || (*(int *)(puVar7 + 0x40) != -1)) {
            local_b8 = (float)fVar8;
          }
          FUN_0049c540(puVar7,local_58);
        }
        _DAT_00680b78 = 0;
        local_78 = param_3 * *(float *)(iVar6 + 0xa0 + DAT_0067ee20);
        local_74 = param_3 * *(float *)(iVar6 + 0xa4 + DAT_0067ee20);
        local_6c = local_78 * 10.0;
        local_68 = local_74 * 10.0;
        local_b0 = -(param_3 * *(float *)(iVar6 + 0x9c + DAT_0067ee20) * 10.0);
        local_ac = -local_6c;
        local_a8 = -local_68;
        local_a0 = local_b0;
        local_9c = local_ac;
        local_98 = local_a8;
        fVar8 = (float10)FUN_0049a120(local_58,puVar7,&local_b0);
        if (fVar8 < (float10)local_b8) {
          if (((*(byte *)(iVar6 + 4 + DAT_0067ee20) & 4) == 0) || (*(int *)(puVar7 + 0x40) != -1)) {
            local_b8 = (float)fVar8;
          }
          FUN_0049c540(local_58);
        }
        local_b4 = local_b4 + 1;
        puVar7 = puVar7 + 0x4c;
        uVar5 = local_a4;
      } while (local_b4 < DAT_006847c8);
    }
    iVar4 = 0;
    iVar3 = (DAT_004fc8f8 & local_14) * 4;
    local_ac = 0.0;
    pfVar1 = (float *)(iVar6 + 0xac + DAT_0067ee20);
    local_5c = *(float *)(iVar3 + DAT_006a5c88) * *(float *)(iVar6 + 0x9c + DAT_0067ee20) +
               *(float *)(iVar3 + DAT_006a5cd0) * *(float *)(iVar6 + 0xa4 + DAT_0067ee20);
    fVar2 = local_b8 * param_3 * 10.0;
    local_a8 = local_5c * fVar2;
    local_28 = (*(float *)(iVar3 + DAT_006a5cd0) * *(float *)(iVar6 + 0x9c + DAT_0067ee20) -
               *(float *)(iVar3 + DAT_006a5c88) * *(float *)(iVar6 + 0xa4 + DAT_0067ee20)) * fVar2 +
               local_28;
    local_24 = local_24 + 0.0;
    local_20 = local_20 + local_a8;
    fVar2 = (*pfVar1 * _DAT_004fc8f4 * param_3) / 6.2831855;
    if (*pfVar1 <= 0.0) {
      FUN_004c062b((double)fVar2);
    }
    else {
      FUN_004c06fa((double)fVar2);
    }
    iVar3 = __ftol();
    local_14 = local_14 + iVar3;
    if (*(float *)(iVar6 + 0xac + DAT_0067ee20) == 0.0) {
      uVar5 = 0;
    }
    else if (0 < DAT_006847c8) {
      puVar7 = &DAT_00680c68;
      do {
        _DAT_00680b78 = 0;
        iVar3 = FUN_0049a480(puVar7,local_58);
        if (iVar3 != 0) {
          iVar3 = FUN_0049c6e0();
          if (iVar3 == 0) {
            FUN_004aa0b0(puVar7,local_58);
          }
          uVar5 = 1;
        }
        _DAT_00680b78 = 0;
        iVar3 = FUN_0049a480(local_58,puVar7);
        if (iVar3 != 0) {
          iVar3 = FUN_0049c6e0();
          if (iVar3 == 0) {
            FUN_004aa0b0(local_58);
          }
          uVar5 = 1;
        }
        iVar4 = iVar4 + 1;
        puVar7 = puVar7 + 0x4c;
      } while (iVar4 < DAT_006847c8);
    }
    *param_2 = ~-(uint)((*(uint *)(iVar6 + 4 + DAT_0067ee20) & 4) != 0) & uVar5;
    return (float10)local_b8;
  }
  *param_2 = 0;
  return (float10)1.0;
}

