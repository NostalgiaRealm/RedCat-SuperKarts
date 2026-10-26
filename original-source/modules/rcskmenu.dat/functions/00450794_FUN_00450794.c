/*
 * FUN_00450794 at 00450794
 * undefined __register FUN_00450794(int param_1, int * param_2)
 * Address ranges: 00450794-004507d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450794(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((*param_2 != 0) && (iVar1 = FUN_00410210(*(int *)(param_1 + 4)), -1 < iVar1 + -1)) {
    iVar3 = 0;
    do {
      piVar2 = (int *)FUN_00410218(*(int *)(param_1 + 4),iVar3);
      if (*param_2 == piVar2[4]) {
        *param_2 = 0;
        FUN_004505ec(piVar2);
        return;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

