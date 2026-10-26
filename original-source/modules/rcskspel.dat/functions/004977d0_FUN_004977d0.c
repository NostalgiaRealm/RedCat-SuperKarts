/*
 * FUN_004977d0 at 004977d0
 * undefined FUN_004977d0(void)
 * Address ranges: 004977d0-00497aae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004977d0(int param_1,int param_2,float param_3,undefined4 param_4,float param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((param_2 < 0) || (iVar2 < param_2)) {
    FUN_004afee0(s__s__d____Illegal_start_chunk___d_004fb2e8,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x2bd,param_2);
  }
  piVar3 = *(int **)(param_1 + 4);
  piVar4 = piVar3 + param_2;
  iVar1 = DAT_00680b28 + piVar3[param_2] * 0x984;
  if ((param_3 - *(float *)(iVar1 + 0x24)) * *(float *)(iVar1 + 0x38) -
      (param_5 - *(float *)(iVar1 + 0x2c)) * *(float *)(iVar1 + 0x30) <= 0.0) {
    for (; param_2 < iVar2; param_2 = param_2 + 1) {
      iVar1 = DAT_00680b28 + *piVar4 * 0x984;
      if (0.0 < (param_3 - *(float *)(iVar1 + 0x24)) * *(float *)(iVar1 + 0x38) -
                (param_5 - *(float *)(iVar1 + 0x2c)) * *(float *)(iVar1 + 0x30)) goto LAB_00497a96;
      piVar4 = piVar4 + 1;
    }
  }
  else {
    for (; -1 < param_2; param_2 = param_2 + -1) {
      iVar1 = DAT_00680b28 + *piVar4 * 0x984;
      if ((param_3 - *(float *)(iVar1 + 0x24)) * *(float *)(iVar1 + 0x38) -
          (param_5 - *(float *)(iVar1 + 0x2c)) * *(float *)(iVar1 + 0x30) < 0.0) {
        return param_2;
      }
      piVar4 = piVar4 + -1;
    }
  }
  if (param_2 == 0) {
    param_2 = iVar2 + -1;
    if (-1 < param_2) {
      piVar3 = piVar3 + param_2;
      do {
        iVar2 = DAT_00680b28 + *piVar3 * 0x984;
        if ((param_3 - *(float *)(iVar2 + 0x24)) * *(float *)(iVar2 + 0x38) -
            (param_5 - *(float *)(iVar2 + 0x2c)) * *(float *)(iVar2 + 0x30) < 0.0) {
          return param_2;
        }
        param_2 = param_2 + -1;
        piVar3 = piVar3 + -1;
      } while (-1 < param_2);
    }
  }
  else {
    param_2 = 0;
    if (0 < iVar2) {
      while (iVar1 = DAT_00680b28 + *piVar3 * 0x984,
            (param_3 - *(float *)(iVar1 + 0x24)) * *(float *)(iVar1 + 0x38) -
            (param_5 - *(float *)(iVar1 + 0x2c)) * *(float *)(iVar1 + 0x30) <= 0.0) {
        param_2 = param_2 + 1;
        piVar3 = piVar3 + 1;
        if (iVar2 <= param_2) {
          return param_2;
        }
      }
LAB_00497a96:
      param_2 = param_2 + -1;
      if (param_2 == -1) {
        return iVar2 + -1;
      }
    }
  }
  return param_2;
}

