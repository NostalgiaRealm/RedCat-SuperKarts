/*
 * FUN_00494000 at 00494000
 * undefined FUN_00494000(void)
 * Address ranges: 00494000-0049445d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00494000(int param_1,int param_2)

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
  int iVar11;
  float local_4c;
  int iStack_44;
  int local_3c;
  
  local_3c = -1;
  local_4c = 3.4e+38;
  FUN_004afce0();
  if (((param_2 != 1) && (param_2 != 0)) && (param_2 != -1)) {
    FUN_004afee0(s__s__d___Illegal_side__d__004fae60,s_D__work_rcsk_Code_Engine_Prog_rd_004fad08,
                 0x81,param_2);
  }
  iVar11 = *(int *)(param_1 * 0xd0 + 0x1c + DAT_0067ee20);
  iVar9 = DAT_006a5c38 + *(int *)(param_1 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9;
  fVar2 = *(float *)(iVar9 + 0x50);
  fVar3 = *(float *)(iVar9 + 0x54);
  fVar4 = *(float *)(iVar9 + 0x58);
  FUN_004afce0(s_Chunk____d__Position_____f__f__f_004fae3c,iVar11,(double)fVar2,(double)fVar3,
               (double)fVar4);
  if ((param_2 == 1) || (param_2 == -1)) {
    iVar10 = iVar11 * 0x984;
    FUN_004afce0(s__d_waypoints_on_the_RIGHT__004fae20,*(undefined4 *)(iVar10 + 0xe8 + DAT_00680b28)
                );
    iVar9 = 0;
    if (0 < *(int *)(iVar10 + 0xe8 + DAT_00680b28)) {
      iStack_44 = iVar10 + 0x154;
      do {
        FUN_004afce0(s_Checking_index__d__004fae0c,iVar9);
        iVar5 = *(int *)(iStack_44 + DAT_00680b28);
        FUN_004afce0(s_Waypoint__d_found__004fadf8,iVar5);
        pfVar1 = (float *)(iVar5 * 0x50 + 8 + DAT_00680ae0);
        fVar6 = *pfVar1;
        fVar7 = pfVar1[1];
        fVar8 = pfVar1[2];
        FUN_004afce0(s_WP_Position_____f__f__f___004faddc,(double)fVar6,(double)fVar7,(double)fVar8)
        ;
        fVar6 = fVar6 - fVar2;
        fVar7 = fVar7 - fVar3;
        fVar8 = fVar8 - fVar4;
        FUN_004afce0(s_Difference_____f__f__f___004fadc0,(double)fVar6,(double)fVar7,(double)fVar8);
        fVar6 = SQRT(fVar7 * fVar7 + fVar6 * fVar6 + fVar8 * fVar8);
        FUN_004afce0(s_Distance____f__004fadb0,(double)fVar6);
        FUN_004afce0();
        if (fVar6 < local_4c) {
          FUN_004afce0(s_Setting_closest_wp_index_to__d__a_004fad68,iVar5);
          local_4c = fVar6;
          local_3c = iVar5;
        }
        iVar9 = iVar9 + 1;
        iStack_44 = iStack_44 + 4;
      } while (iVar9 < *(int *)(iVar10 + 0xe8 + DAT_00680b28));
    }
  }
  if ((param_2 == 0) || (param_2 == -1)) {
    iVar11 = iVar11 * 0x984;
    FUN_004afce0(s__d_waypoints_on_the_LEFT__004fad4c,*(undefined4 *)(iVar11 + 0xe4 + DAT_00680b28))
    ;
    iVar9 = 0;
    if (0 < *(int *)(iVar11 + 0xe4 + DAT_00680b28)) {
      iStack_44 = iVar11 + 0x124;
      do {
        FUN_004afce0(s_Checking_index__d__004fae0c,iVar9);
        iVar10 = *(int *)(iStack_44 + DAT_00680b28);
        FUN_004afce0(s_Waypoint__d_found__004fadf8,iVar10);
        pfVar1 = (float *)(iVar10 * 0x50 + 8 + DAT_00680ae0);
        fVar6 = *pfVar1;
        fVar7 = pfVar1[1];
        fVar8 = pfVar1[2];
        FUN_004afce0(s_WP_Position_____f__f__f___004faddc,(double)fVar6,(double)fVar7,(double)fVar8)
        ;
        fVar6 = fVar6 - fVar2;
        fVar7 = fVar7 - fVar3;
        fVar8 = fVar8 - fVar4;
        FUN_004afce0(s_Difference_____f__f__f___004fadc0,(double)fVar6,(double)fVar7,(double)fVar8);
        fVar6 = SQRT(fVar6 * fVar6 + fVar7 * fVar7 + fVar8 * fVar8);
        FUN_004afce0(s_Distance____f__004fadb0,(double)fVar6);
        FUN_004afce0();
        if (fVar6 < local_4c) {
          FUN_004afce0(s_Setting_closest_wp_index_to__d__a_004fad68,iVar10);
          local_4c = fVar6;
          local_3c = iVar10;
        }
        iStack_44 = iStack_44 + 4;
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(int *)(iVar11 + 0xe4 + DAT_00680b28));
    }
  }
  FUN_004afce0(s_Return_WP_index__d__004fad34,local_3c);
  return local_3c;
}

