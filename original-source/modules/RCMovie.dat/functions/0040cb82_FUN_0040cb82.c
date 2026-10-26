/*
 * FUN_0040cb82 at 0040cb82
 * undefined4 __stdcall FUN_0040cb82(void)
 * Address ranges: 0040cb82-0040cc46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040cb82(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int local_c;
  
  if (DAT_0043d6f4 != 0) {
    FUN_004015a6((byte *)s_starting_to_show_images_2_004321f0);
    for (local_c = 0; local_c < DAT_00431b64; local_c = local_c + 1) {
      if (*(int *)(DAT_0043d6e8 + local_c * 0x20) != 0) {
        uVar3 = 1;
        uVar1 = FUN_0041f8f2();
        iVar2 = (int)uVar1 % DAT_0042c354;
        uVar1 = FUN_0041f8f2();
        FUN_004105ee(0,local_c,(int)uVar1 % DAT_0042c350,iVar2,uVar3);
        iVar2 = FUN_004133f0(0xd);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_004133f0(0x20);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_004133f0(0x1b);
        if (iVar2 != 0) {
          return 0;
        }
      }
    }
    FUN_004015a6((byte *)s_done_show_images_0043220c);
  }
  return 0;
}

