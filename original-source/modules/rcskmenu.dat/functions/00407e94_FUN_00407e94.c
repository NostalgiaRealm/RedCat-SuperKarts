/*
 * FUN_00407e94 at 00407e94
 * undefined __register FUN_00407e94(int param_1, int * param_2)
 * Address ranges: 00407e94-00407ec7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407e94(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00403dd0(param_1);
  for (iVar2 = 1; (iVar2 <= iVar1 && (*(byte *)(param_1 + -1 + iVar2) < 0x21)); iVar2 = iVar2 + 1) {
  }
  FUN_00403fd8(param_1,iVar2,0x7fffffff,param_2);
  return;
}

