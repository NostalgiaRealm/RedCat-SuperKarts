/*
 * FUN_00418a14 at 00418a14
 * undefined __register FUN_00418a14(int * param_1, int param_2)
 * Address ranges: 00418a14-00418a67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418a14(int *param_1,int param_2)

{
  tagPOINT local_10;
  
  if (param_2 != param_1[1]) {
    if (param_1[1] != 0) {
      FUN_004189b4((int)param_1);
      FUN_004188dc(param_1,&local_10);
      param_1[6] = local_10.x;
      param_1[7] = local_10.y;
      param_1[1] = 0;
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xfe;
    }
    if (param_2 != 0) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 1;
      param_1[1] = param_2;
      FUN_00418900(param_1,param_1 + 6);
    }
  }
  return;
}

