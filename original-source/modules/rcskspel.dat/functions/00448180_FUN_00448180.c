/*
 * FUN_00448180 at 00448180
 * undefined FUN_00448180(void)
 * Address ranges: 00448180-00448242
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448180(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_004a6200(s_a_VLIEGT_004efd1c);
  iVar2 = FUN_0048fb60(0,0,0,0,0,0,uVar1,0,0,0,0,0);
  *(undefined4 *)(iVar2 * 0xd0 + 0x44 + DAT_0067ee20) = 0;
  FUN_0043b760(iVar2,s_PLANE_004efd28);
  (&DAT_0053f99c)[param_1 * 0xd0] = iVar2;
  return;
}

