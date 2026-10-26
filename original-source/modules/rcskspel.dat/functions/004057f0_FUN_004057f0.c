/*
 * FUN_004057f0 at 004057f0
 * undefined FUN_004057f0(void)
 * Address ranges: 004057f0-00405b4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004057f0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int local_c;
  
  piVar3 = param_3;
  piVar2 = param_2;
  FUN_004afce0(s_BACKTRACK_SPEED_TRIGGER_004de2b4);
  *param_2 = 0;
  *param_3 = 0;
  iVar5 = param_1 * 0xd0;
  param_1 = *(int *)(iVar5 + 0x1c + DAT_0067ee20);
  FUN_004afce0(s_Chunk____d__004de2d0,param_1);
  iVar4 = *(int *)(iVar5 + 0x38 + DAT_0067ee20);
  FUN_004afce0(s_Side____d__004de2e0,iVar4);
  if (iVar4 == 0) {
    if (DAT_0053ba08 == 0) {
      param_2 = (int *)0x1;
      FUN_004afce0(s_Side_is_left__004de2ec);
      goto LAB_004058b6;
    }
    param_2 = (int *)0xffffffff;
    pcVar6 = s_Side_is_left__004de2fc;
  }
  else if (DAT_0053ba08 == 0) {
    param_2 = (int *)0xffffffff;
    pcVar6 = s_Side_is_right__004de30c;
  }
  else {
    param_2 = (int *)0x1;
    pcVar6 = s_Side_is_right__004de31c;
  }
  FUN_004afce0(pcVar6);
LAB_004058b6:
  FUN_004afce0(s_Starting_loop____004de32c);
  FUN_004afce0(s_Checking_chunk__d__004de340,param_1);
  if (param_1 <= DAT_00680220 + -1) {
    local_c = param_1 * 0x984 + 0xec;
    do {
      if (param_1 < 0) break;
      iVar4 = 0;
      param_3 = (int *)local_c;
      do {
        FUN_004afce0(s_Checking_trigger__d__004de39c,iVar4);
        iVar1 = *(int *)((int)param_3 + DAT_00680b28);
        switch(iVar1) {
        case 4:
        case 5:
        case 6:
        case 8:
          FUN_004afce0(s_Speed_trigger_found___d__004de3b4,iVar1);
          FUN_004afce0(s__p_speed_trigger____d__004de3d0,*piVar2);
          FUN_004afce0(s_NO_TRIGGER____d__004de3e8,0);
          if (*piVar2 == 0) {
            FUN_004afce0(s_Speed_trigger_not_yet_set__004de3fc);
            *piVar2 = iVar1;
            if (*piVar3 != 0) {
              FUN_004afce0(s_All_triggers_found__returning__004de418);
              return;
            }
          }
          break;
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
          if (*(int *)(iVar5 + 0x38 + DAT_0067ee20) == 1) {
            FUN_004afce0(s_Lane_trigger_found___d__004de438,iVar1);
            FUN_004afce0(s__p_lane_trigger____d__004de454,*piVar3);
            FUN_004afce0(s_NO_TRIGGER____d__004de46c,0);
            if (*piVar3 == 0) {
              FUN_004afce0(s_Lane_trigger_not_set_yet__004de480);
              *piVar3 = iVar1;
              if (*piVar2 != 0) {
                FUN_004afce0(s_All_triggers_found__returning__004de49c);
                return;
              }
            }
          }
          break;
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
          if (*(int *)(iVar5 + 0x38 + DAT_0067ee20) == 0) {
            FUN_004afce0(s_Lane_trigger_found___d__004de4bc,iVar1);
            FUN_004afce0(s__p_lane_trigger____d__004de4d8,*piVar3);
            FUN_004afce0(s_NO_TRIGGER____d__004de4f0,0);
            if (*piVar3 == 0) {
              FUN_004afce0(s_Lane_trigger_not_set_yet__004de504);
              *piVar3 = iVar1;
              if (*piVar2 != 0) {
                FUN_004afce0(s_All_triggers_found__returning__004de520);
                return;
              }
            }
          }
        }
        iVar4 = iVar4 + 1;
        param_3 = (int *)((int)param_3 + 4);
      } while (iVar4 < 2);
      param_1 = param_1 + (int)param_2;
      local_c = local_c + (int)param_2 * 0x984;
      FUN_004afce0(s_Checking_chunk__d__004de340,param_1);
    } while (param_1 <= DAT_00680220 + -1);
  }
  FUN_004afce0(s_Illegal_chunk__returning_default_004de354);
  if (*piVar2 == 0) {
    *piVar2 = 8;
  }
  iVar4 = DAT_00505028;
  if (*piVar3 == 0) {
    DAT_00505028 = DAT_00505028 + 1;
    FUN_004afce0(s___04d__No_lane_trigger_found__004de37c,iVar4);
    if (*(int *)(iVar5 + 0x38 + DAT_0067ee20) == 1) {
      *piVar3 = 0x13;
    }
    if (*(int *)(iVar5 + 0x38 + DAT_0067ee20) == 0) {
      *piVar3 = 0x29;
    }
  }
  return;
}

