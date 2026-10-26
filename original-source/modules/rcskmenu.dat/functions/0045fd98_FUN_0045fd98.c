/*
 * FUN_0045fd98 at 0045fd98
 * undefined __register FUN_0045fd98(int * param_1, int param_2)
 * Address ranges: 0045fd98-0045fde1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fd98(int *param_1,int param_2)

{
  if (param_2 != param_1[0x81]) {
    param_1[0x81] = param_2;
    if (param_1[0x80] < param_2) {
      param_1[0x81] = param_1[0x80];
    }
    if (param_1[0x81] < param_1[0x7f]) {
      param_1[0x81] = param_1[0x7f];
    }
    FUN_0045fd00(param_1);
    (**(code **)(*param_1 + 0xb8))();
  }
  return;
}

