/*
 * FUN_0040a18a at 0040a18a
 * undefined __cdecl FUN_0040a18a(int param_1)
 * Address ranges: 0040a18a-0040a24d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040a18a(int param_1)

{
  int local_8;
  
  if (param_1 == 0) {
    for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
      *(char *)((int)DAT_0043d760 + local_8 * 4) = *(char *)(DAT_0043d510 + 0x6c + local_8 * 3) << 2
      ;
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 1) =
           *(char *)(DAT_0043d510 + 0x6d + local_8 * 3) << 2;
      *(char *)((int)DAT_0043d760 + local_8 * 4 + 2) =
           *(char *)(DAT_0043d510 + 0x6e + local_8 * 3) << 2;
    }
    FUN_0040e96f(DAT_0043d760,DAT_0043d760,0,0x100);
  }
  else {
    _SmackColorRemap_16(DAT_0043d510,DAT_0043d760,0x100,3);
  }
  return;
}

