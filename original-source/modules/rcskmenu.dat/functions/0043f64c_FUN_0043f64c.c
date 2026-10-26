/*
 * FUN_0043f64c at 0043f64c
 * undefined __register FUN_0043f64c(int param_1, int * param_2)
 * Address ranges: 0043f64c-0043f67a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f64c(int param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0043f5c0(param_1);
  FUN_00403c38(param_2,(undefined4 *)0x0,uVar1);
  if (uVar1 != 0) {
    FUN_0043f5d0(param_1,*param_2,uVar1 + 1);
  }
  return;
}

