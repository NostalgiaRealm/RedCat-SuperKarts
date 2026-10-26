/*
 * FUN_00404300 at 00404300
 * undefined __register FUN_00404300(int param_1, int param_2)
 * Address ranges: 00404300-00404329
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404300(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)(param_2 + 10 + (uint)*(byte *)(param_2 + 1));
  iVar3 = *(int *)(param_2 + 6 + (uint)*(byte *)(param_2 + 1));
  do {
    FUN_004043c0((undefined4 *)(puVar2[1] + param_1),*(char **)*puVar2);
    puVar2 = puVar2 + 2;
    iVar4 = iVar3 + -1;
    bVar1 = 0 < iVar3;
    iVar3 = iVar4;
  } while (iVar4 != 0 && bVar1);
  return;
}

