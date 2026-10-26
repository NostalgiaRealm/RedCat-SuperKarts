/*
 * FUN_00453450 at 00453450
 * int * __register FUN_00453450(int param_1, uint param_2)
 * Address ranges: 00453450-0045347d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00453450(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_00453370(param_1,param_2);
  piVar3 = *(int **)(iVar2 + 0x10);
  cVar1 = (**(code **)(*piVar3 + 0x1c))();
  if (cVar1 != '\0') {
    iVar2 = FUN_00453370(param_1,0);
    piVar3 = *(int **)(iVar2 + 0x10);
  }
  return piVar3;
}

