/*
 * FUN_00406ae8 at 00406ae8
 * int __cdecl FUN_00406ae8(int param_1)
 * Address ranges: 00406ae8-00406b5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00406ae8(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0043d414 <= local_8) {
      return -1;
    }
    if ((*(int *)(DAT_0043d420 + 0x34 + local_8 * 0x44) == param_1) &&
       (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) == 0)) break;
    FUN_004015a6((byte *)s__d_used__d_0042f744);
    local_8 = local_8 + 1;
  }
  return local_8;
}

