/*
 * FUN_004146ec at 004146ec
 * undefined __register FUN_004146ec(int param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 004146ec-00414745
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004146ec(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 extraout_ECX;
  uint local_c;
  
  local_c = param_3;
  local_c = FUN_00403dd0((int)param_2);
  if ((int)local_c < 0x100) {
    FUN_00414748(param_1,6,extraout_ECX);
    FUN_004145f0(param_1,&local_c,1);
  }
  else {
    FUN_00414748(param_1,0xc,extraout_ECX);
    FUN_004145f0(param_1,&local_c,4);
  }
  FUN_004145f0(param_1,param_2,local_c);
  return;
}

