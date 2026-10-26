/*
 * FUN_004bd68f at 004bd68f
 * undefined FUN_004bd68f(void)
 * Address ranges: 004bd68f-004bd6c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bd68f(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_1c [6];
  
  local_1c[0] = 0xffffffff;
  local_1c[2] = 0;
  local_1c[3] = 0;
  local_1c[4] = DAT_006b6a54;
  puVar2 = local_1c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

