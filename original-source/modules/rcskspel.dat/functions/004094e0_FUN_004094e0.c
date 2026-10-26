/*
 * FUN_004094e0 at 004094e0
 * undefined FUN_004094e0(void)
 * Address ranges: 004094e0-0040952f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004094e0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = 0xffffffff;
  iVar2 = DAT_0053be28;
  if (param_2 < DAT_00508610) {
    iVar2 = (&DAT_00503ef0)[param_2 * 0x47];
  }
  uVar1 = *(undefined4 *)(iVar2 * 0xd0 + 0x1c + DAT_0067ee20);
  param_1[2] = 0xffffffff;
  param_1[1] = uVar1;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}

