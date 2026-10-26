/*
 * FUN_00416f83 at 00416f83
 * int __cdecl FUN_00416f83(char * param_1)
 * Address ranges: 00416f83-00417004
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00416f83(char *param_1)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  sVar1 = _strlen(param_1);
  local_8 = 0;
  for (local_c = 0; local_c < (int)sVar1; local_c = local_c + 1) {
    local_8 = local_8 + *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) +
                                         (uint)(byte)param_1[local_c] * 0xc) + 4);
  }
  if (0 < (int)sVar1) {
    local_8 = local_8 + (sVar1 - 1) * *(int *)(DAT_0043db88 + 0x88);
  }
  return local_8;
}

