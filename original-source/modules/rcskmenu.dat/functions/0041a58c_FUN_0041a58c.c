/*
 * FUN_0041a58c at 0041a58c
 * undefined __register FUN_0041a58c(int * param_1, int param_2)
 * Address ranges: 0041a58c-0041a5d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a58c(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2] + -1;
  if (-1 < iVar3) {
    do {
      piVar1 = (int *)FUN_0040f6b0(param_1,iVar3);
      uVar2 = thunk_FUN_004030bc(*piVar1,param_2);
      if ((char)uVar2 != '\0') {
        FUN_00404710((int)piVar1,&DAT_0041a250);
        FUN_0040f550(param_1,iVar3);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  return;
}

