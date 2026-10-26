/*
 * FUN_00418674 at 00418674
 * undefined __register FUN_00418674(int * param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 00418674-004186b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418674(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,0xd);
  Rectangle((HDC)param_1[1],param_2,param_3,param_5,param_4);
  (**(code **)(*param_1 + 0xc))();
  return;
}

