/*
 * FUN_00410d60 at 00410d60
 * undefined FUN_00410d60(void)
 * Address ranges: 00410d60-00411213
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00410d60(int param_1,int param_2,int param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  float local_54;
  int iStack_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  
  local_40 = -1;
  local_54 = 3.4e+38;
  if (((param_2 != 1) && (param_2 != 0)) && (param_2 != -1)) {
    FUN_004afee0(s__s__d___Illegal_side__d__004dfce4,s_D__work_rcsk_Code_game_ai_wmap_c_004dfcc0,
                 0x89,param_2);
  }
  iVar9 = param_1 * 0x50 + 8 + DAT_00680ae0;
  fVar2 = *(float *)(param_1 * 0x50 + 8 + DAT_00680ae0);
  fVar3 = *(float *)(iVar9 + 4);
  fVar4 = *(float *)(iVar9 + 8);
  FUN_004afce0(s_Chunk____d__Position_____f__f__f_004dfd00,param_3,(double)fVar2,(double)fVar3,
               (double)fVar4);
  if ((param_2 == 1) || (param_2 == -1)) {
    iVar9 = param_3 * 0x984;
    FUN_004afce0(s__d_waypoints_on_the_RIGHT__004dfd24,*(undefined4 *)(iVar9 + 0xe8 + DAT_00680b28))
    ;
    if (-param_4 < param_4) {
      iStack_3c = param_4 * 2;
      do {
        FUN_00493a20();
        iVar10 = 0;
        if (0 < *(int *)(iVar9 + 0xe8 + DAT_00680b28)) {
          iStack_48 = iVar9 + 0x154;
          do {
            FUN_004afce0(s_Checking_index__d__004dfd40,iVar10);
            iVar5 = *(int *)(iStack_48 + DAT_00680b28);
            FUN_004afce0(s_Waypoint__d_found__004dfd54,iVar5);
            pfVar1 = (float *)(iVar5 * 0x50 + 8 + DAT_00680ae0);
            fVar6 = *pfVar1;
            fVar7 = pfVar1[1];
            fVar8 = pfVar1[2];
            FUN_004afce0(s_WP_Position_____f__f__f___004dfd68,(double)fVar6,(double)fVar7,
                         (double)fVar8);
            fVar6 = fVar6 - fVar2;
            fVar7 = fVar7 - fVar3;
            fVar8 = fVar8 - fVar4;
            FUN_004afce0(s_Difference_____f__f__f___004dfd84,(double)fVar6,(double)fVar7,
                         (double)fVar8);
            fVar6 = SQRT(fVar7 * fVar7 + fVar6 * fVar6 + fVar8 * fVar8);
            FUN_004afce0(s_Distance____f__004dfda0,(double)fVar6);
            FUN_004afce0();
            if (fVar6 < local_54) {
              FUN_004afce0(s_Setting_closest_wp_index_to__d__a_004dfdc0,iVar5);
              local_54 = fVar6;
              local_40 = iVar5;
            }
            iStack_48 = iStack_48 + 4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < *(int *)(iVar9 + 0xe8 + DAT_00680b28));
        }
        iStack_3c = iStack_3c + -1;
      } while (iStack_3c != 0);
    }
  }
  if ((param_2 == 0) || (param_2 == -1)) {
    param_3 = param_3 * 0x984;
    FUN_004afce0(s__d_waypoints_on_the_LEFT__004dfdf8,*(undefined4 *)(param_3 + 0xe4 + DAT_00680b28)
                );
    if (-param_4 < param_4) {
      iStack_48 = param_4 * 2;
      do {
        FUN_00493a20();
        iVar9 = 0;
        if (0 < *(int *)(param_3 + 0xe4 + DAT_00680b28)) {
          iStack_44 = param_3 + 0x124;
          do {
            FUN_004afce0(s_Checking_index__d__004dfe14,iVar9);
            iVar10 = *(int *)(iStack_44 + DAT_00680b28);
            FUN_004afce0(s_Waypoint__d_found__004dfe28,iVar10);
            pfVar1 = (float *)(iVar10 * 0x50 + 8 + DAT_00680ae0);
            fVar6 = *pfVar1;
            fVar7 = pfVar1[1];
            fVar8 = pfVar1[2];
            FUN_004afce0(s_WP_Position_____f__f__f___004dfe3c,(double)fVar6,(double)fVar7,
                         (double)fVar8);
            fVar6 = fVar6 - fVar2;
            fVar7 = fVar7 - fVar3;
            fVar8 = fVar8 - fVar4;
            FUN_004afce0(s_Difference_____f__f__f___004dfe58,(double)fVar6,(double)fVar7,
                         (double)fVar8);
            fVar6 = SQRT(fVar6 * fVar6 + fVar7 * fVar7 + fVar8 * fVar8);
            FUN_004afce0(s_Distance____f__004dfe74,(double)fVar6);
            FUN_004afce0();
            if (fVar6 < local_54) {
              FUN_004afce0(s_Setting_closest_wp_index_to__d__a_004dfe94,iVar10);
              local_54 = fVar6;
              local_40 = iVar10;
            }
            iVar9 = iVar9 + 1;
            iStack_44 = iStack_44 + 4;
          } while (iVar9 < *(int *)(param_3 + 0xe4 + DAT_00680b28));
        }
        iStack_48 = iStack_48 + -1;
      } while (iStack_48 != 0);
    }
  }
  FUN_004afce0(s_Return_WP_index__d__004dfecc,local_40);
  return local_40;
}

