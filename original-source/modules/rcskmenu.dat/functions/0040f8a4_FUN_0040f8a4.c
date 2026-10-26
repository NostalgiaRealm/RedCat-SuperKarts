/*
 * FUN_0040f8a4 at 0040f8a4
 * undefined __register FUN_0040f8a4(int * param_1, int param_2)
 * Address ranges: 0040f8a4-0040f913
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f8a4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 < 0) || (0x7ffffff < param_2)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c790,param_2);
  }
  if (param_1[3] < param_2) {
    FUN_0040f868(param_1,param_2);
  }
  iVar1 = param_1[2];
  if (iVar1 < param_2) {
    FUN_00402b54((undefined4 *)(param_1[1] + iVar1 * 4),(param_2 - iVar1) * 4,0);
  }
  else {
    iVar1 = iVar1 + -1;
    if (param_2 - iVar1 == 0 || param_2 < iVar1) {
      iVar2 = (param_2 - iVar1) + -1;
      do {
        FUN_0040f550(param_1,iVar1);
        iVar1 = iVar1 + -1;
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0);
    }
  }
  param_1[2] = param_2;
  return;
}

