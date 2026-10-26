/*
 * FUN_00403fd8 at 00403fd8
 * undefined __register FUN_00403fd8(int param_1, int param_2, uint param_3, int * param_4)
 * Address ranges: 00403fd8-00404016
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403fd8(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + -4), iVar1 != 0)) {
    iVar2 = param_2 + -1;
    if (param_2 < 1) {
      iVar2 = 0;
    }
    else if (iVar1 <= iVar2) goto LAB_0040400a;
    if (-1 < (int)param_3) {
      if (iVar1 - iVar2 < (int)param_3) {
        param_3 = iVar1 - iVar2;
      }
      FUN_00403c38(param_4,(undefined4 *)(iVar2 + param_1),param_3);
      return;
    }
  }
LAB_0040400a:
  FUN_00403b50(param_4);
  return;
}

