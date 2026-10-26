/*
 * FUN_0043430c at 0043430c
 * undefined __register FUN_0043430c(int param_1, int param_2)
 * Address ranges: 0043430c-0043434d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043430c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x40) != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 8), -1 < iVar3 + -1)) {
    iVar2 = 0;
    do {
      iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x40),iVar2);
      if (param_2 == iVar1) {
        *(undefined4 *)(param_2 + 4) = 0;
        FUN_0040f550(*(int **)(param_1 + 0x40),iVar2);
        return;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

