/*
 * FUN_004096a0 at 004096a0
 * undefined FUN_004096a0(void)
 * Address ranges: 004096a0-00409b2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004096a0(int param_1,undefined4 param_2,int param_3,int param_4,float *param_5,
                float *param_6)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  int iStack_e8;
  undefined4 uStack_e4;
  int iStack_e0;
  undefined4 uStack_dc;
  undefined1 auStack_d8 [4];
  float fStack_d4;
  float fStack_d0;
  char local_c8 [4];
  int local_c4;
  char acStack_c0 [4];
  int iStack_bc;
  int iStack_b4;
  int iStack_a4;
  
  iVar5 = 0;
  if (0x19 < param_3) {
    return -2;
  }
  if (param_4 < 0) {
    FUN_004afee0(s_Illegal_waypoint__d__Function_Sc_004debdc,param_4,0x12e);
  }
  if (0 < param_3) {
    pcVar1 = local_c8 + 1;
    iVar3 = param_3;
    do {
      pcVar1[-1] = '\0';
      *pcVar1 = '\0';
      pcVar1[1] = '\0';
      pcVar1[3] = -1;
      pcVar1[4] = -1;
      pcVar1[5] = -1;
      pcVar1[6] = -1;
      pcVar1 = pcVar1 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iStack_e0 = param_1 * 0x11c;
  uStack_e4 = *(undefined4 *)
               (DAT_0068021c +
               *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) * 4);
  if (param_3 < 1) {
LAB_00409945:
    if (((iStack_b4 < 0) || (iStack_a4 < 0)) || (iStack_bc < 0)) {
      FUN_004afee0(s_Illegal_waypoint_in_het_laatste_s_004dec54);
    }
    FUN_004113c0(iStack_b4,param_5);
    FUN_004113c0(iStack_a4,param_6);
    return iStack_bc;
  }
LAB_00409763:
  iVar3 = iStack_e0;
  *(int *)(acStack_c0 + iVar5 * 8 + -4) = param_4;
  if (param_1 < 0xf) {
    uStack_dc = *(undefined4 *)
                 (*(int *)((int)&DAT_00503ef0 + iStack_e0) * 0xd0 + 0x1c + DAT_0067ee20);
  }
  iVar2 = *(int *)((int)&DAT_00503ef4 + iStack_e0);
  if (((iVar2 == 0) || (iVar2 == 3)) || (iVar2 != 4)) {
LAB_0040980a:
    uStack_ec = 1;
    uVar4 = 2;
LAB_00409817:
    uStack_f0 = 0;
  }
  else {
    iVar2 = *(int *)(&DAT_00503ef8 + iStack_e0) * 0xd0 + DAT_0067ee20;
    iVar2 = FUN_004114c0(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x24));
    iVar3 = FUN_004114c0(uStack_dc,
                         *(undefined4 *)
                          (*(int *)((int)&DAT_00503ef0 + iVar3) * 0xd0 + 0x24 + DAT_0067ee20));
    if (iVar2 <= iVar3) {
      if (iVar3 <= iVar2) goto LAB_0040980a;
      uStack_ec = 2;
      uVar4 = 1;
      goto LAB_00409817;
    }
    uStack_ec = 0;
    uVar4 = 1;
    uStack_f0 = 2;
  }
  if (local_c8[iVar5 * 8] != '\0') {
LAB_0040986a:
    pcVar1 = local_c8 + iVar5 * 8 + 2;
    do {
      if (pcVar1[-1] == '\0') {
        iVar3 = FUN_00411340(param_2,param_4,uVar4);
        pcVar1[-1] = '\x01';
        if ((-1 < iVar3) && (iVar2 = FUN_00411410(iVar3,&DAT_00505904), iVar2 == 0))
        goto LAB_00409902;
      }
      if (*pcVar1 == '\0') {
        iVar3 = FUN_00411340(param_2,param_4,uStack_f0);
        *pcVar1 = '\x01';
        if ((-1 < iVar3) && (iVar2 = FUN_00411410(iVar3,&DAT_00505904), iVar2 == 0))
        goto LAB_00409902;
      }
      if (iVar5 == 0) {
        iVar5 = FUN_00411340(param_2,local_c4,uStack_ec);
        if (((iVar5 < 0) && (iVar5 = FUN_00411340(param_2,local_c4,uVar4), iVar5 < 0)) &&
           (iVar5 = FUN_00411340(param_2,local_c4,uStack_f0), iVar5 < 0)) {
          if (local_c4 < 1) {
            FUN_004afee0(s_Invalid_waypoint___d_File___s_Li_004dec2c,local_c4,
                         s_D__work_rcsk_Code_game_ai_path_c_004dec08,0x221);
            return -1;
          }
          FUN_004113c0(local_c4,param_5);
          return -1;
        }
        FUN_004113c0(iVar5,&fStack_d4);
        iVar3 = FUN_00411340(param_2,iVar5,uStack_ec);
        bVar6 = iVar3 == 0;
        bVar7 = false;
        if (iVar3 < 0) {
          iVar3 = FUN_00411340(param_2,iVar5,uVar4);
          bVar6 = iVar3 == 0;
          bVar7 = false;
          if (iVar3 < 0) {
            iVar3 = FUN_00411340(param_2,iVar5,uStack_f0);
            bVar7 = iVar3 < 0;
            bVar6 = iVar3 == 0;
          }
        }
        if (bVar6 || bVar7) {
          FUN_004113c0(iVar5,param_5);
          return -1;
        }
        FUN_004113c0(iVar3,param_5);
        FUN_00411480(uStack_e4,auStack_d8,&iStack_e8);
        if (iStack_e8 == 1) {
          fVar8 = ((float10)*param_5 - (float10)fStack_d4) * (float10)0.46511626;
          fVar9 = ((float10)param_5[1] - (float10)fStack_d0) * (float10)0.46511626;
          fVar10 = (float10)fcos((float10)1024.0);
          fVar11 = (float10)fsin((float10)1024.0);
          fVar12 = (fVar8 * fVar10 - fVar9 * fVar11) + (float10)*param_5;
          *param_5 = (float)fVar12;
          param_5[2] = (float)(fVar9 * fVar10 + fVar8 * fVar11 + (float10)param_5[2]);
          *param_6 = (float)fVar12;
          param_6[2] = param_5[2];
        }
        return iVar3;
      }
      param_4 = *(int *)(pcVar1 + -6);
      iVar5 = iVar5 + -1;
      pcVar1 = pcVar1 + -8;
    } while( true );
  }
  iVar3 = FUN_00411340(param_2,param_4,uStack_ec);
  local_c8[iVar5 * 8] = '\x01';
  if ((iVar3 < 0) || (iVar2 = FUN_00411410(iVar3,&DAT_00505904), iVar2 != 0)) goto LAB_0040986a;
  iVar5 = iVar5 + 1;
  local_c8[iVar5 * 8] = '\0';
  local_c8[iVar5 * 8 + 2] = '\0';
  local_c8[iVar5 * 8 + 1] = '\0';
  param_4 = iVar3;
  goto LAB_00409936;
LAB_00409902:
  iVar5 = iVar5 + 1;
  local_c8[iVar5 * 8] = '\0';
  local_c8[iVar5 * 8 + 2] = '\0';
  local_c8[iVar5 * 8 + 1] = '\0';
  *(int *)(acStack_c0 + iVar5 * 8 + -4) = iVar3;
  param_4 = iVar3;
LAB_00409936:
  if (param_3 <= iVar5) goto LAB_00409945;
  goto LAB_00409763;
}

