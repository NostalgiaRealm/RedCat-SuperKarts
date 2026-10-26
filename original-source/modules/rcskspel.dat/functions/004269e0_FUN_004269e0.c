/*
 * FUN_004269e0 at 004269e0
 * undefined FUN_004269e0(void)
 * Address ranges: 004269e0-00426a91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004269e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  iVar1 = FUN_00426540(param_1);
  if (*(int *)(&DAT_0050dfb0 + iVar1 * 0x1910) + 2 < 100) {
    FUN_00426670(param_2,local_40,local_80);
    FUN_00426720(param_3,local_40,local_80);
    FUN_00426780(0,local_40,local_80);
    FUN_00426800(param_1,local_40,local_80);
    iVar1 = FUN_00426540(param_1);
    *(int *)(&DAT_0050dfb0 + iVar1 * 0x1910) = *(int *)(&DAT_0050dfb0 + iVar1 * 0x1910) + 2;
  }
  return;
}

