/*
 * FUN_00409b30 at 00409b30
 * undefined __register FUN_00409b30(int param_1, int * param_2)
 * Address ranges: 00409b30-00409b53
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409b30(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  while( true ) {
    iVar1 = FUN_00403dd0(param_1);
    if ((iVar1 < iVar2) || (*(char *)(param_1 + -1 + iVar2) != ' ')) break;
    iVar2 = iVar2 + 1;
  }
  *param_2 = iVar2;
  return;
}

