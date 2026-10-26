/*
 * FUN_00410b60 at 00410b60
 * undefined FUN_00410b60(void)
 * Address ranges: 00410b60-00410c67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00410b60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float10 fVar4;
  
  if (param_3 == 0) {
    iVar2 = FUN_004be6c9();
    if (iVar2 % 0x1e != 0) {
      return 0;
    }
    fVar4 = (float10)FUN_0048f4e0();
    if ((float10)1.0 / fVar4 < (float10)14.5) {
      return 0;
    }
  }
  if (param_1 == -1) {
LAB_00410c19:
    piVar3 = &DAT_0050738c;
    while ((((piVar3[-1] == 0 || (*(int *)(*piVar3 * 0xd0 + 0x44 + DAT_0067ee20) == 0)) ||
            (iVar2 = FUN_00497ca0(param_2,*piVar3), iVar2 == 0)) || (*piVar3 == param_2))) {
      piVar3 = piVar3 + 3;
      if (0x507f43 < (int)piVar3) {
        return 1;
      }
    }
    return 0;
  }
  iVar2 = param_1 * 0x50 + DAT_00680ae0;
  if (((*(int *)(param_1 * 0x50 + 0x24 + DAT_00680ae0) == 0) &&
      (iVar1 = *(int *)(iVar2 + 0x14), *(int *)(iVar1 * 0x50 + 0x24 + DAT_00680ae0) == 0)) &&
     (iVar2 = *(int *)(iVar2 + 0x20), *(int *)(iVar2 * 0x50 + 0x24 + DAT_00680ae0) == 0)) {
    if ((iVar1 != -1) && (*(int *)(iVar1 * 0x50 + 0x24 + DAT_00680ae0) != 0)) {
      return 0;
    }
    if ((iVar2 == -1) || (*(int *)(iVar2 * 0x50 + 0x24 + DAT_00680ae0) == 0)) goto LAB_00410c19;
  }
  return 0;
}

