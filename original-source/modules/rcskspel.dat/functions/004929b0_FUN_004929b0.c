/*
 * FUN_004929b0 at 004929b0
 * undefined FUN_004929b0(void)
 * Address ranges: 004929b0-00492fa7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004929b0(int param_1,int param_2,float param_3,float param_4,int param_5,int param_6,
            float *param_7)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  float10 extraout_ST0;
  float10 fVar11;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float local_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 local_c4;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  float fStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_8;
  
  iVar10 = param_2 * 0xd0;
  if (*(int *)(iVar10 + 0x60 + DAT_0067ee20) == 0) {
    FUN_004afee0(s__s___d_Object_has_not_RK4_callba_004fa998,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x71e);
  }
  iVar7 = *(int *)(param_1 + 0xc);
  pfVar1 = (float *)(param_1 + 0x9c);
  local_c4 = *(undefined4 *)(DAT_006a5c38 + iVar7 + 0x78 + iVar7 * 0xa8);
  iVar7 = DAT_006a5c38 + iVar7 + iVar7 * 0xa8;
  local_e4 = *pfVar1;
  local_e0 = *(undefined4 *)(param_1 + 0xa0);
  pfVar9 = (float *)(iVar7 + 0x50);
  uStack_dc = *(undefined4 *)(param_1 + 0xa4);
  fStack_d8 = *pfVar9;
  uStack_d4 = *(undefined4 *)(iVar7 + 0x54);
  uStack_d0 = *(undefined4 *)(iVar7 + 0x58);
  if (param_6 == 0) {
    uVar6 = __ftol();
    iVar8 = (uVar6 & DAT_004fc8f8) * 4;
    fVar3 = *(float *)(iVar8 + DAT_006a5c88);
    fVar4 = *pfVar1;
    fVar5 = *(float *)(iVar8 + DAT_006a5cd0);
    fVar2 = *(float *)(param_1 + 0xa4);
    *pfVar9 = (*(float *)(iVar8 + DAT_006a5cd0) * *pfVar1 -
              *(float *)(iVar8 + DAT_006a5c88) * *(float *)(param_1 + 0xa4)) * 10.0 * param_4 *
              param_3 + *pfVar9;
    *(float *)(iVar7 + 0x54) = param_3 * 0.0 + *(float *)(iVar7 + 0x54);
    fVar11 = (float10)((fVar5 * fVar2 + fVar3 * fVar4) * 10.0 * param_4 * param_3);
  }
  else {
    *param_7 = *pfVar1;
    uVar6 = __ftol();
    iVar7 = (uVar6 & DAT_004fc8f8) * 4;
    iVar8 = DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9;
    pfVar9 = (float *)(iVar8 + 0x50);
    fVar11 = ((float10)*(float *)(iVar7 + DAT_006a5cd0) * (float10)param_7[2] +
             extraout_ST0 * (float10)*(float *)(iVar7 + DAT_006a5c88)) * (float10)10.0 *
             (float10)param_3;
    *pfVar9 = (float)((float10)*(float *)(iVar7 + DAT_006a5cd0) * extraout_ST0 -
                     (float10)*(float *)(iVar7 + DAT_006a5c88) * (float10)param_7[2]) * 10.0 *
              param_3 + *pfVar9;
    *(float *)(iVar8 + 0x54) = *(float *)(iVar8 + 0x54) + 0.0;
  }
  pfVar9[2] = (float)(fVar11 + (float10)pfVar9[2]);
  if (param_5 != 1) {
    iVar7 = *(int *)(param_1 + 0xc);
    *(float *)(DAT_006a5c38 + iVar7 + 0x78 + iVar7 * 0xa8) =
         (param_3 * *(float *)(param_1 + 0xac) * _DAT_004fc8f4) / 6.2831855 +
         *(float *)(DAT_006a5c38 + iVar7 + 0x78 + iVar7 * 0xa8);
  }
  (**(code **)(iVar10 + 0x60 + DAT_0067ee20))(&uStack_f0,param_2);
  uStack_b4 = uStack_ec;
  uStack_90 = *(undefined4 *)(param_1 + 0xac);
  uStack_b8 = uStack_f0;
  uStack_94 = *(undefined4 *)(param_1 + 0xc0);
  iVar7 = *(int *)(param_1 + 0xc);
  uStack_b0 = uStack_e8;
  uStack_8c = *(undefined4 *)(DAT_006a5c38 + iVar7 + 0x78 + iVar7 * 0xa8);
  iVar7 = DAT_006a5c38 + iVar7 + iVar7 * 0xa8;
  uStack_84 = *(undefined4 *)(param_1 + 0x94);
  fStack_ac = *pfVar1;
  uStack_a8 = *(undefined4 *)(param_1 + 0xa0);
  uStack_a4 = *(undefined4 *)(param_1 + 0xa4);
  uStack_a0 = *(undefined4 *)(iVar7 + 0x50);
  uStack_9c = *(undefined4 *)(iVar7 + 0x54);
  uStack_98 = *(undefined4 *)(iVar7 + 0x58);
  uStack_88 = *(undefined4 *)(param_1 + 0x90);
  FUN_00492810(&uStack_b8,&fStack_40,param_3 * 0.5);
  (**(code **)(iVar10 + 0x60 + DAT_0067ee20))(&uStack_f0,param_2);
  uStack_b8 = uStack_f0;
  uStack_b4 = uStack_ec;
  uStack_b0 = uStack_e8;
  FUN_00492810(&uStack_b8,&fStack_60,param_3 * 0.5);
  (**(code **)(iVar10 + 0x60 + DAT_0067ee20))(&uStack_f0,param_2);
  uStack_b8 = uStack_f0;
  uStack_b4 = uStack_ec;
  uStack_b0 = uStack_e8;
  FUN_00492810(&uStack_b8,&fStack_80,param_3);
  (**(code **)(iVar10 + 0x60 + DAT_0067ee20))(&uStack_f0,param_2);
  uStack_b8 = uStack_f0;
  uStack_b4 = uStack_ec;
  uStack_b0 = uStack_e8;
  FUN_00492810(&uStack_b8,&fStack_20,param_3);
  iVar7 = __ftol();
  iVar7 = (-iVar7 & DAT_004fc8f8) * 4;
  fVar3 = *(float *)(iVar7 + DAT_006a5c88);
  fVar4 = *pfVar1;
  fVar5 = *(float *)(iVar7 + DAT_006a5cd0);
  *pfVar1 = *(float *)(iVar7 + DAT_006a5cd0) * *pfVar1 -
            *(float *)(iVar7 + DAT_006a5c88) * *(float *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(float *)(param_1 + 0xa4) = fVar5 * *(float *)(param_1 + 0xa4) + fVar3 * fVar4;
  *pfVar1 = (fStack_80 + fStack_60 + fStack_80 + fStack_60 + fStack_40 + fStack_20) * 0.16666667 +
            *pfVar1;
  *(float *)(param_1 + 0xa0) =
       (fStack_1c + fStack_3c + fStack_7c + fStack_5c + fStack_7c + fStack_5c) * 0.16666667 +
       *(float *)(param_1 + 0xa0);
  *(float *)(param_1 + 0xa4) =
       (fStack_18 + fStack_38 + fStack_78 + fStack_58 + fStack_78 + fStack_58) * 0.16666667 +
       *(float *)(param_1 + 0xa4);
  fVar3 = (fStack_68 + fStack_48 + fStack_68 + fStack_48 + fStack_8 + fStack_28) * 0.16666667;
  *(float *)(param_1 + 0xa8) = fVar3 + *(float *)(param_1 + 0xa8);
  *(float *)(param_1 + 0xac) = fVar3 + *(float *)(param_1 + 0xac);
  *(float *)(param_1 + 0xb0) = fVar3 + *(float *)(param_1 + 0xb0);
  iVar10 = DAT_0067ee20 + iVar10;
  *(undefined4 *)(iVar10 + 0xb4) = 0;
  *(undefined4 *)(iVar10 + 0xb8) = 0;
  *(undefined4 *)(iVar10 + 0xbc) = 0;
  *(undefined4 *)(iVar10 + 0xc0) = 0;
  return;
}

