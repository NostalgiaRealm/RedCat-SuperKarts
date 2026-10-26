/*
 * FUN_00414668 at 00414668
 * undefined __register FUN_00414668(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 00414668-004146d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414668(int param_1,int param_2,undefined4 param_3)

{
  int local_8;
  
  local_8 = param_2;
  if ((-0x81 < param_2) && (param_2 < 0x80)) {
    FUN_00414748(param_1,2,param_3);
    FUN_004145f0(param_1,&local_8,1);
    return;
  }
  if ((param_2 < -0x8000) || (0x7fff < param_2)) {
    FUN_00414748(param_1,4,param_3);
    FUN_004145f0(param_1,&local_8,4);
  }
  else {
    FUN_00414748(param_1,3,param_3);
    FUN_004145f0(param_1,&local_8,2);
  }
  return;
}

