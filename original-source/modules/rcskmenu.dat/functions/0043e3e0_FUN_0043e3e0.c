/*
 * FUN_0043e3e0 at 0043e3e0
 * undefined __register FUN_0043e3e0(int * param_1, int param_2)
 * Address ranges: 0043e3e0-0043e3f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e3e0(int *param_1,int param_2)

{
  if (param_2 != param_1[0x16]) {
    FUN_0043e3ac(param_1);
    param_1[0x16] = param_2;
  }
  return;
}

