/*
 * FUN_004343d0 at 004343d0
 * undefined FUN_004343d0(void)
 * Address ranges: 004343d0-00434820
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004343d0(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_10 [4];
  
  local_10[0] = 0;
  local_10[1] = 1;
  local_10[2] = 5;
  local_10[3] = 4;
  FUN_004afce0(s_Entering_handle_mesh_damage__d___004eb590,param_1);
  iVar10 = param_1 * 0xd0;
  if (*(int *)(DAT_0067ee20 + 200 + iVar10) == -1) {
    FUN_004afce0();
    return;
  }
  FUN_004afce0();
  if (*(int *)(DAT_0067ee20 + 0xc4 + iVar10) != DAT_0053b9fc) {
    FUN_004afce0();
    *(int *)(DAT_0067ee20 + 0xc4 + iVar10) = DAT_0053b9fc;
    FUN_004afce0(s_Getting_original_mesh__004eb634);
    iVar10 = *(int *)(DAT_0067ee20 + 200 + iVar10);
    FUN_004afce0();
    piVar9 = local_10;
    iVar11 = 4;
    do {
      pfVar1 = (float *)(iVar10 * 0xbc + *piVar9 * 0xc + 0x10 + DAT_006a5ee0);
      fVar2 = *pfVar1;
      fVar3 = pfVar1[2];
      if (0.0 < fVar2) {
        local_2c = fVar2;
        fVar2 = local_28;
      }
      local_28 = fVar2;
      if (0.0 < fVar3) {
        local_24 = fVar3;
        fVar3 = local_20;
      }
      local_20 = fVar3;
      piVar9 = piVar9 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    FUN_004afce0(s_Edges__l_x_max____f__l_x_min_____004eb65c,(double)local_2c,(double)local_28,
                 (double)local_24,(double)local_20);
    FUN_004afce0(s_Other_stuff__004eb69c);
    FUN_004afce0();
    fVar2 = *(float *)(param_2 + 0x10) * 10.0;
    uVar7 = (uint)(local_2c * 0.6 < fVar2);
    if (fVar2 < local_28 * 0.6) {
      uVar7 = 0xffffffff;
    }
    fVar2 = *(float *)(param_2 + 0x18) * 10.0;
    uVar8 = (uint)(local_24 * 0.6 < fVar2);
    if (fVar2 < local_20 * 0.6) {
      uVar8 = 0xffffffff;
    }
    iVar10 = uVar8 + uVar7 * 10;
    FUN_004afce0(s_l_width_zone____d__l_height_zone_004eb6d0,uVar7,uVar8,iVar10);
    FUN_00435030();
    FUN_004afce0();
    FUN_004afce0();
    iVar11 = param_1;
    switch(iVar10) {
    case 0:
      FUN_004afce0(s_l_zone____d__004eb76c,iVar10);
      FUN_004afee0(s__s__d___Impossible_collision___C_004eb77c,0x6ee);
      break;
    case 1:
      FUN_004afce0(s_l_zone____d__004eb7d0,iVar10);
      iVar11 = 0;
      break;
    case 9:
      FUN_004afce0(s_l_zone____d__004eb7e0,iVar10);
      iVar11 = 3;
      break;
    case 10:
      FUN_004afce0(s_l_zone____d__004eb7f0,iVar10);
      iVar11 = 2;
      break;
    case 0xb:
      FUN_004afce0(s_l_zone____d__004eb800,iVar10);
      iVar11 = 1;
      break;
    case -0xb:
      FUN_004afce0(s_l_zone____d__004eb72c,iVar10);
      iVar11 = 5;
      break;
    case -10:
      FUN_004afce0(s_l_zone____d__004eb73c,iVar10);
      iVar11 = 6;
      break;
    case -9:
      FUN_004afce0(s_l_zone____d__004eb74c,iVar10);
      iVar11 = 7;
      break;
    default:
      FUN_004afce0(s_l_zone____d__004eb810,iVar10);
      FUN_004afee0(s__s__d___Something_went_really_wr_004eb844,
                   s_D__work_rcsk_Code_game_plr_car_c_004eb820,0x708,iVar10);
      break;
    case -1:
      FUN_004afce0(s_l_zone____d__004eb75c,iVar10);
      iVar11 = 4;
    }
    FUN_004afce0(s_Applying_regional_damage_to_obje_004eb87c,param_1,iVar11,0);
    if (param_1 == DAT_0053be28) {
      FUN_004906f0();
      uVar5 = __ftol();
      FUN_00490710(iVar11,uVar5);
      *(undefined4 *)(iVar11 * 4 + 0x53be98) = uVar5;
      return;
    }
    iVar10 = 0;
    if (0 < DAT_00508610) {
      piVar9 = &DAT_005081bc;
      do {
        cVar4 = FUN_00417e90();
        iVar6 = DAT_0053be28;
        if (cVar4 == '\0') {
          iVar6 = *piVar9;
        }
        if (iVar6 == param_1) break;
        iVar10 = iVar10 + 1;
        piVar9 = piVar9 + 0x1c;
      } while (iVar10 < DAT_00508610);
    }
    if (iVar10 != DAT_00508610) {
      FUN_004906f0();
      uVar5 = __ftol();
      FUN_00490710(iVar11,uVar5);
      *(undefined4 *)((iVar11 + iVar10 * 0x1c) * 4 + 0x5081e8) = uVar5;
    }
  }
  return;
}

