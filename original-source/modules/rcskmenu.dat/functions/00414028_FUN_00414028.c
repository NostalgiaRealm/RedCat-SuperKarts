/*
 * FUN_00414028 at 00414028
 * undefined __register FUN_00414028(int param_1, int * param_2, uint param_3)
 * Address ranges: 00414028-00414085
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414028(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint local_c;
  
  local_c = 0;
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  if ((char)uVar1 == '\x06') {
    FUN_0041292c(param_1,&local_c,1);
  }
  else if ((char)uVar1 == '\f') {
    FUN_0041292c(param_1,&local_c,4);
  }
  else {
    FUN_004124c0();
  }
  FUN_00403c38(param_2,(undefined4 *)0x0,local_c);
  FUN_0041292c(param_1,(undefined4 *)*param_2,local_c);
  return;
}

