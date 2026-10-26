/*
 * FUN_00404790 at 00404790
 * undefined FUN_00404790(void)
 * Address ranges: 00404790-00404bd9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00404790(int param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  float local_58;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined1 local_20 [28];
  
  pcVar8 = s_START___>_calc_speed___004ddc94;
  FUN_004afce0();
  uVar10 = CONCAT44(pcVar8,param_2);
  uVar9 = CONCAT44(param_1,param_3);
  pcVar8 = s_p_object____d__p_target_wp____d__004ddcb0;
  FUN_004afce0();
  fVar2 = *(float *)(param_3 * 0xd0 + 0xa4 + DAT_0067ee20);
  FUN_004afce0(s_l_current_speed____f__004ddce4,(double)fVar2,pcVar8,uVar9,uVar10);
  iVar4 = *(int *)(param_3 * 0xd0 + 0xc + DAT_0067ee20);
  FUN_004afce0(s_object3d_index____d__004ddcfc,iVar4);
  param_2 = param_2 * 0x6c;
  iVar6 = *(int *)(param_2 + 0x24 + DAT_00504f98);
  FUN_004afce0(s_behavior_index____d__004ddd14,iVar6);
  iVar1 = param_1 * 0x50 + 8 + DAT_00680ae0;
  local_38 = *(float *)(param_1 * 0x50 + 8 + DAT_00680ae0);
  local_34 = *(float *)(iVar1 + 4);
  local_30 = *(float *)(iVar1 + 8);
  iVar4 = iVar4 * 0xa9;
  local_44 = local_38 - *(float *)(iVar4 + 0x50 + DAT_006a5c38);
  local_40 = local_34 - *(float *)(iVar4 + 0x54 + DAT_006a5c38);
  local_3c = local_30 - *(float *)(iVar4 + 0x58 + DAT_006a5c38);
  local_2c = local_44;
  local_28 = local_40;
  local_24 = local_3c;
  FUN_00405f40(&local_44);
  pfVar5 = (float *)FUN_00405f20();
  local_2c = *pfVar5;
  local_28 = pfVar5[1];
  local_24 = pfVar5[2];
  FUN_004a23d0(local_20,iVar4 + 0x10 + DAT_006a5c38);
  FUN_00405f40();
  pfVar5 = (float *)FUN_00405f20();
  local_38 = *pfVar5;
  local_34 = pfVar5[1];
  local_30 = pfVar5[2];
  local_58 = local_24 * local_38 - local_2c * local_30;
  FUN_004afce0();
  if (local_58 < 0.0) {
    local_58 = local_58 * -1.0;
  }
  FUN_004afce0();
  iVar6 = iVar6 * 0x2c;
  FUN_004afce0(s_Calculating_desired_speed__ai_ch_004ddd64,
               (double)*(float *)(param_2 + 0x1c + DAT_00504f98),
               (double)*(float *)(iVar6 + 8 + DAT_00504fe0),
               (double)*(float *)(iVar6 + 0x14 + DAT_00504fe0));
  fVar3 = *(float *)(param_2 + 0x1c + DAT_00504f98);
  local_58 = fVar3 - (*(float *)(iVar6 + 8 + DAT_00504fe0) * fVar3 * local_58) /
                     *(float *)(iVar6 + 0x14 + DAT_00504fe0);
  FUN_004afce0();
  if (*(float *)(param_2 + 0x18 + DAT_00504f98) < local_58) {
    local_58 = *(float *)(param_2 + 0x18 + DAT_00504f98);
  }
  FUN_004afce0();
  if (local_58 != fVar2) {
    FUN_004afce0();
    if (fVar2 < local_58) {
      FUN_004afce0();
      fVar7 = (float10)FUN_0048f4e0();
      fVar3 = *(float *)(iVar6 + 0x10 + DAT_00504fe0);
      FUN_004afce0();
      FUN_004afce0();
      fVar7 = (float10)(float)(fVar7 * (float10)fVar3 + (float10)fVar2);
      if ((float10)*(float *)(iVar6 + 0x14 + DAT_00504fe0) *
          (float10)*(float *)(param_2 + 0x5c + DAT_00504f98) < fVar7) {
        FUN_004afce0();
        fVar7 = (float10)*(float *)(iVar6 + 0x14 + DAT_00504fe0) *
                (float10)*(float *)(param_2 + 0x5c + DAT_00504f98);
      }
      goto LAB_00404b98;
    }
    if (0.0 < fVar2) {
      FUN_004afce0();
      fVar7 = (float10)FUN_0048f4e0();
      fVar7 = (float10)fVar2 - fVar7 * (float10)*(float *)(iVar6 + 0x18 + DAT_00504fe0);
      if (fVar7 < (float10)0.0) {
        FUN_004afce0();
        fVar7 = (float10)0.0;
      }
      goto LAB_00404b98;
    }
  }
  fVar7 = (float10)local_58;
LAB_00404b98:
  FUN_004afce0(s_l_new_speed____f__l_current_spee_004ddef8,(double)fVar7,(double)fVar2,
               (double)(fVar7 - (float10)fVar2));
  FUN_004afce0(s_FINISH__>_calc_speed___004ddf34);
  return (float10)(float)(fVar7 - (float10)fVar2);
}

