/*
 * FUN_00406a85 at 00406a85
 * int __stdcall FUN_00406a85(void)
 * Address ranges: 00406a85-00406ae7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00406a85(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0043d414 <= local_8) {
      return -1;
    }
    if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) == 0) break;
    FUN_004015a6((byte *)s__d_used__d_0042f738);
    local_8 = local_8 + 1;
  }
  return local_8;
}

