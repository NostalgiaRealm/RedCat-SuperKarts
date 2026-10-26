/*
 * FUN_0042fa84 at 0042fa84
 * undefined __register FUN_0042fa84(int * param_1)
 * Address ranges: 0042fa84-0042fab1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042fa84(int *param_1)

{
  FUN_0040bf7c(*(int *)PTR_DAT_0047c9b0);
  FUN_00414a28((int)param_1);
  FUN_00412378((int)param_1,(char *)0x0);
  if ((char)param_1[0x12] == '\0') {
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

