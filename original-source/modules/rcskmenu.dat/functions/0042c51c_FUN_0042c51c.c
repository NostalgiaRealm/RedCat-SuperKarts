/*
 * FUN_0042c51c at 0042c51c
 * undefined4 __register FUN_0042c51c(int * param_1)
 * Address ranges: 0042c51c-0042c578
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042c51c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_00445724(param_1);
  iVar1 = (**(code **)PTR_DAT_0047c7b0)();
  iVar2 = FUN_004301a8(DAT_0047d774);
  if (-1 < iVar2 + -1) {
    iVar5 = 0;
    do {
      iVar3 = FUN_00430194(DAT_0047d774,iVar5);
      if (iVar1 == *(int *)(iVar3 + 4)) {
        uVar4 = FUN_00430194(DAT_0047d774,iVar5);
        return uVar4;
      }
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}

