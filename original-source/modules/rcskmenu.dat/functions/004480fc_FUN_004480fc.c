/*
 * FUN_004480fc at 004480fc
 * undefined __register FUN_004480fc(int * param_1, undefined4 param_2, uint param_3, int param_4)
 * Address ranges: 004480fc-00448142
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004480fc(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint local_8;
  
  local_8 = param_3;
  FUN_00403b50(param_1);
  (**(code **)(**(int **)(param_4 + -4) + 4))(*(int **)(param_4 + -4),&local_8,4);
  if (0 < (int)local_8) {
    FUN_00404104(param_1,local_8);
    (**(code **)(**(int **)(param_4 + -4) + 4))(*(int **)(param_4 + -4),*param_1,local_8);
  }
  return;
}

