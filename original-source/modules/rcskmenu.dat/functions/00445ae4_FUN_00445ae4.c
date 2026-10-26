/*
 * FUN_00445ae4 at 00445ae4
 * undefined __register FUN_00445ae4(int param_1, int * param_2)
 * Address ranges: 00445ae4-00445b38
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445ae4(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 extraout_ECX;
  int iVar2;
  undefined4 local_14;
  
  if ((*(int *)(param_1 + 0x16c) != 0) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x16c) + 8), -1 < iVar2 + -1)) {
    local_14 = 0;
    do {
      piVar1 = (int *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x16c),local_14);
      FUN_0040f504(param_2,(int)piVar1);
      FUN_00403088(piVar1,param_2,extraout_ECX);
      local_14 = local_14 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

