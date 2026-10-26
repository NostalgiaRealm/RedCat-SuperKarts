/*
 * FUN_0040ed40 at 0040ed40
 * undefined FUN_0040ed40(void)
 * Address ranges: 0040ed40-0040f0ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040ed40(int param_1,undefined4 param_2,int param_3,int param_4,float *param_5,
                float *param_6)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  int iStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  float fStack_dc;
  undefined1 auStack_d4 [4];
  char local_d0 [4];
  int iStack_cc;
  char acStack_c8 [4];
  int iStack_c4;
  int iStack_bc;
  int iStack_ac;
  
  iVar3 = 0;
  if (0x19 < param_3) {
    return -2;
  }
  if (param_4 < 0) {
    FUN_004afee0(s__s__d____Illegal_waypoint__d_004df1f8,s_D__work_rcsk_Code_game_ai_rcr_sc_004df1cc
                 ,0x13f,param_4);
  }
  FUN_0040f2f0(local_d0,param_3);
  uStack_e4 = *(undefined4 *)
               (DAT_0068021c +
               *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) * 4);
  if (param_3 < 1) {
LAB_0040eedb:
    if (((iStack_bc < 0) || (iStack_ac < 0)) || (iStack_c4 < 0)) {
      FUN_004afee0(s_Illegal_waypoint_in_het_laatste_s_004df26c);
    }
    FUN_004113c0(iStack_bc,param_5);
    FUN_004113c0(iStack_ac,param_6);
    return iStack_c4;
  }
LAB_0040edd1:
  *(int *)(acStack_c8 + iVar3 * 8 + -4) = param_4;
  FUN_0040f0b0(param_1,param_4,&uStack_e8,&uStack_f4,&uStack_f0);
  if (local_d0[iVar3 * 8] != '\0') {
LAB_0040ee29:
    pcVar2 = local_d0 + iVar3 * 8 + 2;
    do {
      if (pcVar2[-1] == '\0') {
        iVar1 = FUN_00411340(param_2,param_4,uStack_f4);
        pcVar2[-1] = '\x01';
        if ((-1 < iVar1) && (*(int *)(iVar1 * 0x50 + 0x24 + DAT_00680ae0) == 0)) goto LAB_0040eea8;
      }
      if (*pcVar2 == '\0') {
        iVar1 = FUN_00411340(param_2,param_4,uStack_f0);
        *pcVar2 = '\x01';
        if ((-1 < iVar1) && (*(int *)(iVar1 * 0x50 + 0x24 + DAT_00680ae0) == 0)) goto LAB_0040eea8;
      }
      iVar1 = iStack_cc;
      if (iVar3 == 0) {
        iVar3 = FUN_00411340(param_2,iStack_cc,uStack_e8);
        if (((iVar3 < 0) && (iVar3 = FUN_00411340(param_2,iVar1,uStack_f4), iVar3 < 0)) &&
           (iVar3 = FUN_00411340(param_2,iVar1,uStack_f0), iVar3 < 0)) {
          if (iStack_cc < 1) {
            FUN_004afee0(s_Invalid_waypoint___d_File___s_Li_004df244,iStack_cc,
                         s_D__work_rcsk_Code_game_ai_rcr_sc_004df218,0x23a);
            return -1;
          }
          FUN_004113c0(iStack_cc,param_5);
          return -1;
        }
        FUN_004113c0(iVar3,&fStack_e0);
        iVar1 = FUN_00411340(param_2,iVar3,uStack_e8);
        bVar4 = iVar1 == 0;
        bVar5 = false;
        if (iVar1 < 0) {
          iVar1 = FUN_00411340(param_2,iVar3,uStack_f4);
          bVar4 = iVar1 == 0;
          bVar5 = false;
          if (iVar1 < 0) {
            iVar1 = FUN_00411340(param_2,iVar3,uStack_f0);
            bVar5 = iVar1 < 0;
            bVar4 = iVar1 == 0;
          }
        }
        if (bVar4 || bVar5) {
          FUN_004113c0(iVar3,param_5);
          return -1;
        }
        FUN_004113c0(iVar1,param_5);
        FUN_00411480(uStack_e4,auStack_d4,&iStack_ec);
        if (iStack_ec == 1) {
          fVar6 = ((float10)*param_5 - (float10)fStack_e0) * (float10)0.46511626;
          fVar7 = ((float10)param_5[1] - (float10)fStack_dc) * (float10)0.46511626;
          fVar8 = (float10)fcos((float10)1024.0);
          fVar9 = (float10)fsin((float10)1024.0);
          fVar10 = (fVar6 * fVar8 - fVar7 * fVar9) + (float10)*param_5;
          *param_5 = (float)fVar10;
          param_5[2] = (float)(fVar7 * fVar8 + fVar6 * fVar9 + (float10)param_5[2]);
          *param_6 = (float)fVar10;
          param_6[2] = param_5[2];
        }
        return iVar1;
      }
      param_4 = *(int *)(pcVar2 + -6);
      iVar3 = iVar3 + -1;
      pcVar2 = pcVar2 + -8;
    } while( true );
  }
  iVar1 = FUN_00411340(param_2,param_4,uStack_e8);
  local_d0[iVar3 * 8] = '\x01';
  if ((iVar1 < 0) || (*(int *)(iVar1 * 0x50 + 0x24 + DAT_00680ae0) != 0)) goto LAB_0040ee29;
  iVar3 = iVar3 + 1;
  local_d0[iVar3 * 8] = '\0';
  local_d0[iVar3 * 8 + 2] = '\0';
  local_d0[iVar3 * 8 + 1] = '\0';
  goto LAB_0040eed2;
LAB_0040eea8:
  iVar3 = iVar3 + 1;
  local_d0[iVar3 * 8] = '\0';
  local_d0[iVar3 * 8 + 2] = '\0';
  local_d0[iVar3 * 8 + 1] = '\0';
  *(int *)(acStack_c8 + iVar3 * 8 + -4) = iVar1;
LAB_0040eed2:
  param_4 = iVar1;
  if (param_3 <= iVar3) goto LAB_0040eedb;
  goto LAB_0040edd1;
}

