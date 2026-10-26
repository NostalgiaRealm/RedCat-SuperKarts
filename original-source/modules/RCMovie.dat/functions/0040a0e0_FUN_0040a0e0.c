/*
 * FUN_0040a0e0 at 0040a0e0
 * undefined4 __cdecl FUN_0040a0e0(int param_1)
 * Address ranges: 0040a0e0-0040a189
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040a0e0(int param_1)

{
  char cVar1;
  
  if (DAT_0043d514 == 0) {
    if (param_1 == 0) {
      cVar1 = _SmackSoundUseDirectSound_4(0);
      if (cVar1 == '\0') {
        FUN_0040187a((byte *)s__s__d____failed_to_set_directsou_0043144c);
      }
    }
    else {
      cVar1 = _SmackSoundUseDirectSound_4(param_1);
      if (cVar1 == '\0') {
        FUN_0040187a((byte *)s__s__d____failed_to_set_directsou_00431410);
      }
    }
    FUN_0040a80c();
    FUN_0040a83c(1,0x1b);
    FUN_0040a83c(1,0xd);
    FUN_0040a83c(1,0x20);
    FUN_0040a83c(1,1);
    DAT_0043d514 = 1;
  }
  return 0;
}

