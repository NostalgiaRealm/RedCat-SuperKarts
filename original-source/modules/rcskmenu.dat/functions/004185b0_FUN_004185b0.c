/*
 * FUN_004185b0 at 004185b0
 * undefined __register FUN_004185b0(int * param_1, int param_2, int param_3)
 * Address ranges: 004185b0-004185e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004185b0(int *param_1,int param_2,int param_3)

{
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,0xd);
  LineTo((HDC)param_1[1],param_2,param_3);
  (**(code **)(*param_1 + 0xc))();
  return;
}

