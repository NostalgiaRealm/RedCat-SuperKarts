/*
 * FUN_00471d10 at 00471d10
 * undefined FUN_00471d10(void)
 * Address ranges: 00471d10-00471dab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471d10(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  int local_8;
  undefined1 local_4 [4];
  
  FUN_004b9ea0(&local_c,&local_8,local_4);
  iVar2 = DAT_00544ba8;
  iVar3 = DAT_00544ba4;
  iVar1 = FUN_00481730();
  if (iVar1 == 0) {
    iVar2 = iVar2 / 2;
    iVar3 = iVar3 / 2;
  }
  uVar4 = FUN_00471db0(param_1,0,0,DAT_00544ba8,DAT_00544ba4,local_c,local_8,iVar2 + local_c,
                       iVar3 + local_8,9);
  FUN_004b6ec0(DAT_00544bb8,uVar4);
  DAT_00544bb0 = local_c;
  DAT_00544bac = local_8;
  return;
}

