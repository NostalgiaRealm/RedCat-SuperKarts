/*
 * FUN_0042d36c at 0042d36c
 * undefined __register FUN_0042d36c(int * param_1, int param_2, char param_3)
 * Address ranges: 0042d36c-0042d3b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d36c(int *param_1,int param_2,char param_3)

{
  bool bVar1;
  undefined4 extraout_ECX;
  
  if (param_3 != '\0') {
    bVar1 = thunk_FUN_0044243d(param_2,param_1[0x83]);
    if (bVar1) {
      param_1[0x83] = *(int *)(param_2 + 0x24);
    }
  }
  bVar1 = thunk_FUN_0044243d(param_2,param_1[0x82]);
  if (bVar1) {
    FUN_0042d2b4(param_1,(int *)0x0,extraout_ECX);
  }
  return;
}

