/*
 * FUN_004380dc at 004380dc
 * undefined __register FUN_004380dc(int * param_1, int param_2)
 * Address ranges: 004380dc-004380eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004380dc(int *param_1,int param_2)

{
  if (param_2 != param_1[0xd]) {
    param_1[0xd] = param_2;
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return;
}

