/*
 * FUN_0043f604 at 0043f604
 * undefined __register FUN_0043f604(int * param_1, int * param_2)
 * Address ranges: 0043f604-0043f625
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f604(int *param_1,int *param_2)

{
  undefined4 extraout_ECX;
  
  param_1[0x1b] = (int)param_2;
  if (param_2 != (int *)0x0) {
    FUN_00439eb0(param_2,param_1);
    FUN_00414858((int)param_2,(int)param_1,extraout_ECX);
  }
  return;
}

