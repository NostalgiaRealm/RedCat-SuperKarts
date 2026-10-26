/*
 * FUN_0043f8a0 at 0043f8a0
 * undefined __register FUN_0043f8a0(int * param_1, int param_2)
 * Address ranges: 0043f8a0-0043f91d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f8a0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (param_1[9] != 0) {
    iVar2 = FUN_0040f70c(*(int *)(param_1[9] + 0x134),(int)param_1);
    if (-1 < iVar2) {
      iVar1 = (*(int **)(param_1[9] + 0x134))[2];
      if (param_2 < 0) {
        param_2 = 0;
      }
      if (iVar1 <= param_2) {
        param_2 = iVar1 + -1;
      }
      if (iVar2 != param_2) {
        FUN_0040f550(*(int **)(param_1[9] + 0x134),iVar2);
        FUN_0040f72c(*(int **)(param_1[9] + 0x134),param_2,(int)param_1);
        FUN_0043fa78((int)param_1,*(char *)((int)param_1 + 0x47),'\x01');
        piVar3 = (int *)FUN_004298e4(param_1);
        if ((*(byte *)(piVar3 + 0x11) & 4) != 0) {
          FUN_00403088(piVar3,CONCAT31((int3)((uint)extraout_EDX >> 8),1),extraout_ECX);
        }
      }
    }
  }
  return;
}

