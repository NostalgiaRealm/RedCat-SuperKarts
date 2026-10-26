/*
 * FUN_0042c6e0 at 0042c6e0
 * undefined __register FUN_0042c6e0(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 0042c6e0-0042c706
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c6e0(int *param_1,int param_2,undefined4 param_3)

{
  if (param_2 != param_1[0x90]) {
    param_1[0x90] = param_2;
    if (param_2 != 0) {
      FUN_00414858(param_2,(int)param_1,param_3);
    }
    FUN_0042c640(param_1);
  }
  return;
}

