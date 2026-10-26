/*
 * FUN_004c4f67 at 004c4f67
 * undefined FUN_004c4f67(void)
 * Address ranges: 004c4f67-004c5096
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c4f67(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  if ((double)CONCAT44(param_2,param_1) < 0.0) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_00503640;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) {
LAB_004c4ff2:
      if (param_2 == 0x7ff00000) {
        if (param_1 != 0) {
          return 0;
        }
        if (0.0 < param_3) goto LAB_004c508d;
        if (param_3 < 0.0) goto LAB_004c5024;
      }
      else {
        if (param_2 != -0x100000) {
          return 0;
        }
        if (param_1 != 0) {
          return 0;
        }
        iVar3 = FUN_004c5097(param_3);
        if (0.0 < param_3) {
          dVar2 = _DAT_00503640;
          if (iVar3 == 1) {
            dVar2 = -_DAT_00503640;
          }
          goto LAB_004c508d;
        }
        if (param_3 < 0.0) {
          dVar2 = _DAT_00503660;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
          goto LAB_004c508d;
        }
      }
      dVar2 = 1.0;
      goto LAB_004c508d;
    }
    if (1.0 < dVar1) goto LAB_004c508d;
    if (1.0 <= dVar1) {
LAB_004c4fb7:
      *param_4 = _DAT_00503648;
      return 1;
    }
  }
  else {
    if ((param_3._4_4_ != -0x100000) || (param_3._0_4_ != 0)) goto LAB_004c4ff2;
    if (dVar1 <= 1.0) {
      if (1.0 <= dVar1) goto LAB_004c4fb7;
      goto LAB_004c508d;
    }
  }
LAB_004c5024:
  dVar2 = 0.0;
LAB_004c508d:
  *param_4 = dVar2;
  return 0;
}

