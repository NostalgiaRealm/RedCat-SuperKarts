/*
 * FUN_00444c5c at 00444c5c
 * undefined __register FUN_00444c5c(int * param_1)
 * Address ranges: 00444c5c-00444c88
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444c5c(int *param_1)

{
  if ((*(char *)((int)param_1 + 0x47) == '\0') && (param_1[9] != 0)) {
    FUN_0044244c(param_1,'\0');
  }
  if (((*(byte *)(param_1 + 8) & 0x10) == 0) || ((*(byte *)((int)param_1 + 0x41) & 4) != 0)) {
    FUN_00442e24(param_1);
  }
  return;
}

