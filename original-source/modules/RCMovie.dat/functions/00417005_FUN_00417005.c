/*
 * FUN_00417005 at 00417005
 * int __cdecl FUN_00417005(char * param_1, size_t param_2)
 * Address ranges: 00417005-0041708b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00417005(char *param_1,size_t param_2)

{
  size_t local_10;
  int local_c;
  int local_8;
  
  local_10 = _strlen(param_1);
  local_8 = 0;
  if ((int)param_2 < (int)local_10) {
    local_10 = param_2;
  }
  for (local_c = 0; local_c < (int)local_10; local_c = local_c + 1) {
    local_8 = local_8 + *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) +
                                         (uint)(byte)param_1[local_c] * 0xc) + 4);
  }
  return local_8 + local_10 * *(int *)(DAT_0043db88 + 0x88);
}

