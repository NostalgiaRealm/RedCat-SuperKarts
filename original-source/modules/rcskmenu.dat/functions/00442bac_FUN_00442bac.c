/*
 * FUN_00442bac at 00442bac
 * int __register FUN_00442bac(int param_1, int param_2)
 * Address ranges: 00442bac-00442bf2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00442bac(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0040f70c(*(int *)(param_1 + 0x180),param_2);
  iVar1 = iVar1 + 1;
  iVar3 = *(int *)(*(int *)(param_1 + 0x180) + 8) + -1;
  if (iVar1 <= iVar3) {
    iVar3 = (iVar3 - iVar1) + 1;
    do {
      iVar2 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x180),iVar1);
      if (*(int *)(iVar2 + 0x14c) != 0) {
        return *(int *)(iVar2 + 0x14c);
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}

