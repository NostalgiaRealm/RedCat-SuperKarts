/*
 * FUN_0043ec20 at 0043ec20
 * undefined __register FUN_0043ec20(int * param_1, int param_2, char param_3)
 * Address ranges: 0043ec20-0043ec60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ec20(int *param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  FUN_00414aa4((int)param_1,param_2,param_3);
  if (param_3 == '\x01') {
    if (param_2 == param_1[0x1b]) {
      FUN_0043f604(param_1,(int *)0x0);
    }
    else {
      iVar1 = FUN_0043ea94((int)param_1);
      if (param_2 == iVar1) {
        FUN_0043eac4(param_1,0,extraout_ECX);
      }
    }
  }
  return;
}

