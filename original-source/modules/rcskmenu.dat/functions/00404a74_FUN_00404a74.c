/*
 * FUN_00404a74 at 00404a74
 * undefined __register FUN_00404a74(VARIANTARG * param_1, int param_2)
 * Address ranges: 00404a74-00404aa0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404a74(VARIANTARG *param_1,int param_2)

{
  int local_8;
  
  local_8 = 0;
  FUN_004047ac(*(LPCWSTR *)(param_2 + 8),&local_8);
  FUN_0040486c(param_1);
  (param_1->n1).n2.vt = 0x100;
  *(int *)((int)&param_1->n1 + 8) = local_8;
  return;
}

