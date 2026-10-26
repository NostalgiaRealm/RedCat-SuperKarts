/*
 * FUN_00493430 at 00493430
 * undefined FUN_00493430(void)
 * Address ranges: 00493430-00493535
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00493430(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_1 < 0) || (DAT_00680b2c < param_1)) {
    FUN_004afee0(s___s___d_Illegal_chunk___d_004fab60,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
                 0x14e,param_1);
  }
  if ((param_3 < 0) || (1 < param_3)) {
    FUN_004afee0(s___s___d_Illegal_side___d_004fab98,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
                 0x154,param_3);
  }
  if (param_2 < 0) {
    FUN_004afee0(s___s___d_Illegal_lane___d_004fab7c,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
                 0x15a,param_2);
  }
  if (param_3 == 0) {
    iVar1 = *(int *)(DAT_0068021c + param_1 * 4);
    if (*(int *)(DAT_00680b28 + 0xe4 + iVar1 * 0x984) <= param_2) {
      return 0;
    }
    return *(int *)(DAT_00680b28 + 0x124 + (param_2 + iVar1 * 0x261) * 4);
  }
  if (param_3 != 1) {
    return param_1;
  }
  iVar1 = *(int *)(DAT_0068021c + param_1 * 4);
  if (*(int *)(DAT_00680b28 + 0xe8 + iVar1 * 0x984) <= param_2) {
    return 0;
  }
  return *(int *)(DAT_00680b28 + 0x154 + (param_2 + iVar1 * 0x261) * 4);
}

