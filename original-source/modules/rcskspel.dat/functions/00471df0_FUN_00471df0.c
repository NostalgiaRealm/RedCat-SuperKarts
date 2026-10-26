/*
 * FUN_00471df0 at 00471df0
 * undefined FUN_00471df0(void)
 * Address ranges: 00471df0-00471e5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471df0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_00544ba8;
  iVar3 = DAT_00544ba4;
  iVar1 = FUN_00481730();
  if (iVar1 == 0) {
    iVar2 = iVar2 / 2;
    iVar3 = iVar3 / 2;
  }
  uVar4 = FUN_00471db0(param_1,0,0,DAT_00544ba8,DAT_00544ba4,DAT_00544bb0,DAT_00544bac,
                       DAT_00544bb0 + iVar2,DAT_00544bac + iVar3,9);
  FUN_004b6ec0(DAT_00544bb8,uVar4);
  return;
}

