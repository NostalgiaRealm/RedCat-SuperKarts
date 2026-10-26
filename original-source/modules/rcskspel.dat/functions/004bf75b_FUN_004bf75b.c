/*
 * FUN_004bf75b at 004bf75b
 * undefined FUN_004bf75b(void)
 * Address ranges: 004bf75b-004bf786
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bf75b(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_1 != param_2) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    }
  }
  return;
}

