/*
 * FUN_0041827b at 0041827b
 * undefined __stdcall FUN_0041827b(void)
 * Address ranges: 0041827b-004182e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041827b(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00435820 + local_8 * 0x10) != 0) {
      DeleteObject(*(HGDIOBJ *)(&DAT_00435820 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00435820 + local_8 * 0x10) = 0;
    }
  }
  DAT_0043dca8 = 0;
  DAT_00435818 = 0xffffffff;
  return;
}

