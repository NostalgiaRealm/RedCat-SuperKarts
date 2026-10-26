/*
 * FUN_004487b0 at 004487b0
 * undefined FUN_004487b0(void)
 * Address ranges: 004487b0-00448861
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004487b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_004a6200(s_e00_rond_004efd38);
  iVar2 = FUN_0048fb60(0,0,0,0,0,0,uVar1,0,0,0,0,0);
  *(undefined4 *)(iVar2 * 0xd0 + 0x44 + DAT_0067ee20) = 0;
  (&DAT_0053f99c)[param_1 * 0xd0] = iVar2;
  return;
}

