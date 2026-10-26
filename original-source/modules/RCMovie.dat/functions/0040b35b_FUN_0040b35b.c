/*
 * FUN_0040b35b at 0040b35b
 * int __stdcall FUN_0040b35b(void)
 * Address ranges: 0040b35b-0040b3dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040b35b(void)

{
  int local_8;
  
  if (DAT_0043d5b4 == 0) {
    FUN_0040187a((byte *)s__s__d____trying_to_reference_uni_004317a0);
  }
  local_8 = 0;
  while( true ) {
    if (DAT_0043d5b0 <= local_8) {
      return -1;
    }
    if (((*(int *)(DAT_0043d5ac + local_8 * 0xc) == -1) &&
        (*(int *)(DAT_0043d5ac + 4 + local_8 * 0xc) == -1)) &&
       (*(int *)(DAT_0043d5ac + 8 + local_8 * 0xc) == 0)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

