/*
 * FUN_0040e6fa at 0040e6fa
 * undefined4 __stdcall FUN_0040e6fa(void)
 * Address ranges: 0040e6fa-0040e7df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040e6fa(void)

{
  int iVar1;
  
  if (DAT_0043d764 == 0) {
    DAT_0043d760 = LocalAlloc(0x40,0x400);
    if (DAT_0043d760 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____error_not_enough_memory_004327d0);
    }
    if (DAT_0042c358 < 9) {
      iVar1 = (**(code **)(*DAT_00438414 + 0x14))(DAT_00438414,0x44,DAT_0043d760,&DAT_0043d75c,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_create_a_pale_0043284c);
      }
      DAT_0043d764 = 1;
      FUN_0040e809(0);
      FUN_0040e809(1);
      FUN_0040e809(2);
    }
    else {
      FUN_004015a6((byte *)s__s__d____16_bit_screen_mode__>_i_00432814);
      DAT_0043d768 = 1;
    }
  }
  return 0;
}

