/*
 * FUN_00404f00 at 00404f00
 * undefined FUN_00404f00(void)
 * Address ranges: 00404f00-0040537d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00404f00(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int iStack_c;
  int local_8;
  int local_4;
  
  FUN_004afce0();
  FUN_004afce0(s_Object_index____d__004ddfa8,param_1);
  iVar7 = param_1 * 0xd0;
  iVar6 = *(int *)(iVar7 + 0x1c + DAT_0067ee20);
  local_8 = *(int *)(iVar7 + 0x10 + DAT_0067ee20);
  iVar8 = local_8 * 0x6c;
  local_4 = *(int *)(iVar8 + 0x24 + DAT_00504f98);
  FUN_004afce0(s_AI___index____d__004ddfbc,local_8);
  iVar4 = *(int *)(iVar8 + 100 + DAT_00504f98);
  if (iVar6 != iVar4) {
    iVar2 = FUN_00404eb0(iVar6,iVar4);
    iVar4 = DAT_00504f98;
    if (iVar2 == 1) {
      iVar3 = iVar8 + DAT_00504f98;
      iVar2 = FUN_00493a40(iVar6,*(undefined4 *)(iVar8 + 100 + DAT_00504f98));
      iVar2 = *(int *)(iVar3 + 0x60) + iVar2;
    }
    else {
      iVar3 = DAT_00504f98 + iVar8;
      iVar2 = FUN_00493a40(iVar6,*(undefined4 *)(iVar3 + 100));
      iVar2 = *(int *)(iVar3 + 0x60) - iVar2;
    }
    *(int *)(iVar8 + iVar4 + 0x60) = iVar2;
  }
  *(int *)(iVar8 + 100 + DAT_00504f98) = iVar6;
  iVar4 = DAT_00680b28 + iVar6 * 0x984;
  if ((*(int *)(iVar4 + 0xec) != 0x2c) && (*(int *)(iVar4 + 0xf0) != 0x2c)) {
    if (*(int *)(iVar7 + 0x44 + DAT_0067ee20) == 0) {
      FUN_004afee0(s_SANITY_CHECK_ENTERING_handle_bas_004de008,param_1);
    }
    iVar6 = local_4;
    if ((*(int *)(iVar7 + 0x3c + DAT_0067ee20) == 0) && ((local_4 < 7 || (0x10 < local_4)))) {
      FUN_004afee0(s_SANITY_CHECK_ENTERING_handle_bas_004de04c,param_1,local_8,local_4,0,
                   *(undefined4 *)(iVar7 + 0x44 + DAT_0067ee20));
    }
    uVar5 = *(undefined4 *)(iVar8 + DAT_00504f98);
    FUN_004afce0(s_Current_waypoint__ai_____d__004de0c8,uVar5);
    local_4 = FUN_00404be0(uVar5,0);
    FUN_004afce0(s_Next_waypoint____d__004de0e8,local_4);
    iStack_c = 0;
    iVar6 = iVar6 * 0x2c;
    iVar4 = FUN_00404c50(uVar5,*(undefined4 *)(iVar6 + DAT_00504fe0),&iStack_c);
    FUN_004afce0(s_____ai_chosen_lane_l_ai_index____004de100,
                 *(undefined4 *)(iVar8 + 0x14 + DAT_00504f98),iStack_c);
    *(int *)(iVar8 + 0x14 + DAT_00504f98) = *(int *)(iVar8 + 0x14 + DAT_00504f98) + iStack_c;
    FUN_004afce0(s_Target_waypoint____d__004de140,iVar4);
    if ((local_4 == -1) || (iVar4 == -1)) {
      FUN_004afce0();
      FUN_004afce0(s_Braking__deceleration____f__004de170,
                   (double)*(float *)(iVar6 + 0x18 + DAT_00504fe0));
      *(undefined4 *)(iVar7 + 0x9c + DAT_0067ee20) = 0;
      *(undefined4 *)(iVar7 + 0xa0 + DAT_0067ee20) = 0;
      *(float *)(iVar7 + 0xa4 + DAT_0067ee20) =
           *(float *)(iVar7 + 0xa4 + DAT_0067ee20) - *(float *)(iVar6 + 0x18 + DAT_00504fe0);
      if (*(float *)(iVar7 + 0xa4 + DAT_0067ee20) < 0.0) {
        FUN_004afce0();
        *(undefined4 *)(iVar7 + 0xa4 + DAT_0067ee20) = 0;
      }
    }
    else {
      if (*(float *)(iVar6 + 0x14 + DAT_00504fe0) * 4.0 < *(float *)(iVar7 + 0xa4 + DAT_0067ee20)) {
        *(undefined4 *)(iVar7 + 0xa4 + DAT_0067ee20) = *(undefined4 *)(iVar6 + 0x14 + DAT_00504fe0);
      }
      *(undefined4 *)(iVar7 + 0x9c + DAT_0067ee20) = 0;
      *(undefined4 *)(iVar7 + 0xa0 + DAT_0067ee20) = 0;
      fVar9 = (float10)FUN_00404790(iVar4,local_8,param_1);
      *(float *)(iVar7 + 0xa4 + DAT_0067ee20) =
           (float)(fVar9 + (float10)*(float *)(iVar7 + 0xa4 + DAT_0067ee20));
      if (*(float *)(iVar6 + 0x14 + DAT_00504fe0) * 4.0 < *(float *)(iVar7 + 0xa4 + DAT_0067ee20)) {
        *(undefined4 *)(iVar7 + 0xa4 + DAT_0067ee20) = *(undefined4 *)(iVar6 + 0x14 + DAT_00504fe0);
      }
      iVar2 = DAT_0067ee20 + iVar7;
      fVar9 = (float10)FUN_00404510(param_1,local_4,local_8);
      iVar4 = local_4;
      *(float *)(iVar2 + 0xac) = (float)fVar9;
      if ((*(float *)(iVar7 + 0xa4 + DAT_0067ee20) < 1.5) ||
         ((param_1 == DAT_0053be28 && (DAT_0053b9c0 == 7)))) {
        *(undefined4 *)(iVar7 + 0xac + DAT_0067ee20) = 0;
      }
      fVar9 = (float10)FUN_00404e20(*(undefined4 *)(iVar8 + DAT_00504f98),local_4);
      iVar6 = FUN_00404360(*(undefined4 *)(iVar6 + 4 + DAT_00504fe0),iVar4,
                           DAT_006a5c38 + *(int *)(iVar7 + 0xc + DAT_0067ee20) * 0xa9 + 0x50,
                           (float)fVar9);
      if (iVar6 == 1) {
        *(int *)(iVar8 + DAT_00504f98) = iVar4;
        puVar1 = (undefined4 *)(iVar8 + 4 + DAT_00504f98);
        uVar5 = FUN_00404be0(*(undefined4 *)(iVar8 + 4 + DAT_00504f98),0);
        *puVar1 = uVar5;
        FUN_004afce0();
        return 1;
      }
    }
    FUN_004afce0();
    return 1;
  }
  FUN_004afce0(s_Chunk__d__EINDE_WEG_trigger__tur_004ddfd0,iVar6,param_1);
  *(undefined4 *)(iVar7 + 0x44 + DAT_0067ee20) = 0;
  return 1;
}

