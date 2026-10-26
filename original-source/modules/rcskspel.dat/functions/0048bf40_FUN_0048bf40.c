/*
 * FUN_0048bf40 at 0048bf40
 * undefined FUN_0048bf40(void)
 * Address ranges: 0048bf40-0048bf71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_0048bf40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    puVar3 = param_1 + 8;
    puVar1 = param_3 + 8;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_3 = *param_1;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
    }
    param_3 = puVar1;
    param_1 = puVar3;
  } while (puVar3 != param_2);
  return puVar1;
}

