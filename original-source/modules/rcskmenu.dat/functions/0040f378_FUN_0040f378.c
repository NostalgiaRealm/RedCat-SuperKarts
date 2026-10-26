/*
 * FUN_0040f378 at 0040f378
 * undefined __register FUN_0040f378(undefined * * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0040f378-0040f40d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f378(undefined **param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined **ppuVar1;
  int iVar2;
  HMODULE pHVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined *puVar4;
  undefined4 uStack_11c;
  undefined1 *puStack_118;
  undefined1 *puStack_114;
  byte local_108 [256];
  undefined *local_8;
  
  puStack_114 = &stack0xfffffffc;
  local_8 = (undefined *)0x0;
  puStack_118 = &LAB_0040f40e;
  uStack_11c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_11c;
  if ((param_1 != &PTR_FUN_0040e948) && (param_1 != *(undefined ***)(param_4 + -8))) {
    iVar2 = param_4;
    ppuVar1 = (undefined **)FUN_00402e34((int)param_1);
    FUN_0040f378(ppuVar1,extraout_EDX,extraout_ECX,iVar2);
    FUN_00402df8((int)param_1,local_108);
    FUN_00403d74((int *)&local_8,local_108);
    puVar4 = local_8;
    iVar2 = FUN_00404ee8(param_1);
    pHVar3 = (HMODULE)FUN_00404ef0(iVar2);
    FUN_0040f1f0(puVar4,pHVar3,(undefined4 *)(param_4 + -4));
  }
  *in_FS_OFFSET = uStack_11c;
  puStack_114 = &LAB_0040f415;
  puStack_118 = (undefined1 *)0x40f40d;
  FUN_00403b50((int *)&local_8);
  return;
}

