/*
 * FUN_004012a0 at 004012a0
 * undefined4 __cdecl FUN_004012a0(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 004012a0-0040134d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004012a0(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  if (DAT_004383a8 == 1) {
    uVar1 = FUN_004011f0(0x140,0xf0,8);
    if ((char)uVar1 == '\x01') {
      FUN_004015a6((byte *)s__s__d__Using_videomode_MODE_320X_0042c174);
      FUN_00401e18(0,1,0);
      *param_1 = 0x140;
      *param_2 = 0xf0;
      return CONCAT31((int3)((uint)param_1 >> 8),1);
    }
  }
  uVar1 = FUN_004011f0(0x280,0x1e0,8);
  if ((char)uVar1 == '\x01') {
    FUN_004015a6((byte *)s__s__d__Using_videomode_MODE_640X_0042c140);
    FUN_00401e18(0,3,0);
    *param_1 = 0x280;
    *param_2 = 0x1e0;
    return CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}

