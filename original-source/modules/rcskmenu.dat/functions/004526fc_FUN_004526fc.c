/*
 * FUN_004526fc at 004526fc
 * undefined __register FUN_004526fc(int * param_1, int param_2)
 * Address ranges: 004526fc-00452711
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004526fc(int *param_1,int param_2)

{
  if (param_2 != param_1[0x21]) {
    param_1[0x21] = param_2;
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  return;
}

