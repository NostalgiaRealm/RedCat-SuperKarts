/*
 * FUN_004575a0 at 004575a0
 * undefined FUN_004575a0(void)
 * Address ranges: 004575a0-004575e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004575a0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(*param_1 + 8);
  if (puVar1 == DAT_00544a84) {
    iVar3 = *(int *)(*param_1 + 4);
    if (*param_1 == *(int *)(iVar3 + 8)) {
      do {
        *param_1 = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
      } while (*param_1 == *(int *)(iVar3 + 8));
    }
    if (*(int *)(*param_1 + 8) != iVar3) {
      *param_1 = iVar3;
    }
    return;
  }
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != DAT_00544a84; puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  *param_1 = (int)puVar1;
  return;
}

