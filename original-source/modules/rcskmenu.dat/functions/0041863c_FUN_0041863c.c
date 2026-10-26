/*
 * FUN_0041863c at 0041863c
 * undefined __register FUN_0041863c(int * param_1, POINT * param_2, int param_3)
 * Address ranges: 0041863c-0041866f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041863c(int *param_1,POINT *param_2,int param_3)

{
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,0xd);
  Polyline((HDC)param_1[1],param_2,param_3 + 1);
  (**(code **)(*param_1 + 0xc))();
  return;
}

