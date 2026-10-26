/*
 * FUN_00493a70 at 00493a70
 * undefined FUN_00493a70(void)
 * Address ranges: 00493a70-00493b04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00493a70(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 < 0) || (1 < param_2)) {
    FUN_004afee0(s___s___d_Illegal_side___d_004fab98,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
                 0x2ba,param_2);
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_2 == 0) {
    iVar1 = *(int *)(DAT_00680b28 + 0xe4 + *(int *)(DAT_0068021c + param_1 * 4) * 0x984);
    if (iVar1 <= param_3) {
      param_3 = iVar1 + -1;
    }
  }
  else if ((param_2 == 1) &&
          (iVar1 = *(int *)(DAT_00680b28 + 0xe8 + *(int *)(DAT_0068021c + param_1 * 4) * 0x984),
          iVar1 <= param_3)) {
    return iVar1 + -1;
  }
  return param_3;
}

