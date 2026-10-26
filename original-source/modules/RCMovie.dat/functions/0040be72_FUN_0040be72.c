/*
 * FUN_0040be72 at 0040be72
 * undefined4 __cdecl FUN_0040be72(int param_1, int param_2)
 * Address ranges: 0040be72-0040bf51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040be72(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_8;
  
  if (param_1 < 1) {
    uVar1 = 2000;
  }
  else {
    DAT_00431b64 = param_1;
    DAT_0043d6e8 = LocalAlloc(0x40,param_1 << 5);
    if (DAT_0043d6e8 == (HLOCAL)0x0) {
      uVar1 = 2000;
    }
    else {
      if ((param_2 != 2) && (param_2 != 4)) {
        FUN_0040187a((byte *)s__s__d____alloc_mem_images___unko_00431e6c);
      }
      for (local_8 = 0; local_8 < DAT_00431b64; local_8 = local_8 + 1) {
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20) = 0;
        *(int *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x18) = param_2;
        *(undefined4 *)((int)DAT_0043d6e8 + local_8 * 0x20 + 0x1c) = 0;
      }
      DAT_0043d6f0 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}

