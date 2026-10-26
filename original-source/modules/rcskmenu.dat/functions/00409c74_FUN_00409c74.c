/*
 * FUN_00409c74 at 00409c74
 * undefined4 __register FUN_00409c74(int param_1, int * param_2, char param_3)
 * Address ranges: 00409c74-00409caa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00409c74(int param_1,int *param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  FUN_00409b30(param_1,param_2);
  iVar1 = FUN_00403dd0(param_1);
  if ((*param_2 <= iVar1) && (*(char *)(param_1 + -1 + *param_2) == param_3)) {
    *param_2 = *param_2 + 1;
    uVar2 = 1;
  }
  return uVar2;
}

