/*
 * FUN_004043cc at 004043cc
 * int __register FUN_004043cc(int param_1, int param_2)
 * Address ranges: 004043cc-004043f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004043cc(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)(param_2 + 10 + (uint)*(byte *)(param_2 + 1));
  iVar3 = *(int *)(param_2 + 6 + (uint)*(byte *)(param_2 + 1));
  do {
    FUN_004044e0(puVar2[1] + param_1,*(undefined4 *)*puVar2);
    puVar2 = puVar2 + 2;
    iVar4 = iVar3 + -1;
    bVar1 = 0 < iVar3;
    iVar3 = iVar4;
  } while (iVar4 != 0 && bVar1);
  return param_1;
}

