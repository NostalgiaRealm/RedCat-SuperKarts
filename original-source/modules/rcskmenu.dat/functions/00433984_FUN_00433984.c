/*
 * FUN_00433984 at 00433984
 * undefined __register FUN_00433984(int * param_1, HIMAGELIST param_2)
 * Address ranges: 00433984-004339ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433984(int *param_1,HIMAGELIST param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  FUN_00433a14(param_1);
  if (param_2 != (HIMAGELIST)0x0) {
    FUN_0043394c((int)param_1,param_2);
    param_1[0xc] = (int)param_2;
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  }
  return;
}

