/*
 * FUN_0043394c at 0043394c
 * undefined __register FUN_0043394c(int param_1, HIMAGELIST param_2)
 * Address ranges: 0043394c-00433982
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043394c(int param_1,HIMAGELIST param_2)

{
  int local_c;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x28);
  local_c = *(int *)(param_1 + 0x24);
  ImageList_GetIconSize(param_2,&local_8,&local_c);
  *(int *)(param_1 + 0x28) = local_8;
  *(int *)(param_1 + 0x24) = local_c;
  FUN_00433888(param_1);
  return;
}

