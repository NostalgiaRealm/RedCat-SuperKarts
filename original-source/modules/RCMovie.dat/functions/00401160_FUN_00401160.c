/*
 * FUN_00401160 at 00401160
 * undefined __stdcall FUN_00401160(void)
 * Address ranges: 00401160-004011e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401160(void)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_4;
  
  DAT_00437da0 = 0;
  FUN_004015a6((byte *)s__s__d__Getting_videomodes_0042c0f4);
  ppuVar2 = &local_4;
  iVar1 = DirectDrawCreate();
  if (iVar1 != 0) {
    FUN_0040187a((byte *)s_Error_creating_DirectDraw_0042c0d8);
  }
  iVar1 = (*(code *)*local_4)(ppuVar2,&DAT_004286d0,&stack0xffffffec);
  if (iVar1 != 0) {
    FUN_0040187a((byte *)s_Error_getting_DirectDraw4_0042c0bc);
  }
  (*(code *)(*ppuVar2)[8])(ppuVar2,0,0,0,&LAB_00401120);
  (*(code *)(*ppuVar2)[2])(ppuVar2);
  return;
}

