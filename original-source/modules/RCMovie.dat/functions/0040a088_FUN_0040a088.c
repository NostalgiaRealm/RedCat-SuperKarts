/*
 * FUN_0040a088 at 0040a088
 * undefined __stdcall FUN_0040a088(void)
 * Address ranges: 0040a088-0040a0d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a088(void)

{
  HLOCAL pvVar1;
  
  if (DAT_0043d468 != 0) {
    pvVar1 = LocalFree(DAT_0043d460);
    if (pvVar1 == (HLOCAL)0x0) {
      FUN_0041f368(DAT_0043d458);
      DAT_0043d468 = 0;
    }
    else {
      FUN_0040187a((byte *)s__s__d____failure_to_free_file_li_004313dc);
    }
  }
  return;
}

