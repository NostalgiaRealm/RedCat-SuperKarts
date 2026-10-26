/*
 * FUN_0041d7fc at 0041d7fc
 * undefined __register FUN_0041d7fc(int param_1, int * param_2, int param_3)
 * Address ranges: 0041d7fc-0041d868
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d7fc(int param_1,int *param_2,int param_3)

{
  short local_70 [7];
  undefined4 local_62 [21];
  
  FUN_0041cf04(param_1);
  if (param_3 == 0) {
    FUN_00402b54(local_62,0x54,0);
    FUN_0041d1c4(param_1,0,0,(int *)0x0,0,local_62);
  }
  else {
    FUN_004118e8(param_2,local_70,0xe);
    if (local_70[0] != 0x4d42) {
      FUN_00418c6c();
    }
    FUN_0041d2ec(param_1,param_2,param_3 + -0xe);
  }
  return;
}

