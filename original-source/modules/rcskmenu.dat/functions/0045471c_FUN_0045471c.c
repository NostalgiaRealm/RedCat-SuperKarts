/*
 * FUN_0045471c at 0045471c
 * undefined __register FUN_0045471c(int param_1, int param_2, int * param_3)
 * Address ranges: 0045471c-0045474d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045471c(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if ((-1 < param_2) && (iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x14))(), param_2 <= iVar1))
  {
    (**(code **)(**(int **)(param_1 + 4) + 0xc))(*(int **)(param_1 + 4),param_2,param_3);
    return;
  }
  FUN_00403b50(param_3);
  return;
}

