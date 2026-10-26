/*
 * FUN_0045fa58 at 0045fa58
 * int __register FUN_0045fa58(int * param_1, int param_2)
 * Address ranges: 0045fa58-0045fabf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0045fa58(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = FUN_0043f0b0(param_1);
  iVar1 = param_1[0x86];
  if (iVar2 - *(int *)(param_1[0x84] + 0x38) != iVar1 * 2) {
    iVar2 = FUN_0043f0b0(param_1);
    iVar3 = ((param_2 - iVar1) * (param_1[0x80] - param_1[0x7f])) /
            ((iVar2 - *(int *)(param_1[0x84] + 0x38)) + param_1[0x86] * -2) + param_1[0x7f];
  }
  return iVar3;
}

