/*
 * FUN_00414088 at 00414088
 * undefined __register FUN_00414088(int param_1, int * param_2, uint param_3)
 * Address ranges: 00414088-004140cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414088(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  UINT local_c;
  
  local_c = 0;
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  if ((char)uVar1 != '\x12') {
    FUN_004124c0();
  }
  FUN_0041292c(param_1,&local_c,4);
  FUN_004042bc(param_2,local_c);
  FUN_0041292c(param_1,(undefined4 *)*param_2,local_c * 2);
  return;
}

