/*
 * FUN_0040ee34 at 0040ee34
 * undefined __register FUN_0040ee34(undefined * * param_1)
 * Address ranges: 0040ee34-0040ef04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ee34(undefined **param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_130;
  undefined1 *puStack_12c;
  undefined1 *puStack_128;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined1 *puStack_11c;
  int local_110;
  undefined1 local_10c;
  byte local_108 [256];
  int local_8;
  
  puStack_11c = &stack0xfffffffc;
  local_8 = 0;
  puStack_120 = &LAB_0040ef22;
  uStack_124 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_124;
  puStack_128 = (undefined1 *)0x40ee5e;
  piVar1 = (int *)FUN_0040fa70(DAT_0047d624);
  puStack_12c = &LAB_0040ef05;
  uStack_130 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_130;
  puStack_128 = &stack0xfffffffc;
  while( true ) {
    iVar3 = FUN_0040f70c((int)piVar1,(int)param_1);
    if (iVar3 != -1) break;
    FUN_00402df8((int)param_1,local_108);
    FUN_00403d74(&local_8,local_108);
    iVar3 = FUN_0040ec98(local_8);
    if (iVar3 != 0) {
      local_110 = local_8;
      local_10c = 0xb;
      uVar2 = FUN_0040ad5c((int)&DAT_0040da84,'\x01',(undefined4 *)PTR_PTR_0047c884,0,&local_110);
      FUN_00403604(uVar2);
    }
    FUN_0040f504(piVar1,(int)param_1);
    if (param_1 == &PTR_FUN_0040df7c) break;
    param_1 = (undefined **)FUN_00402e34((int)param_1);
  }
  *in_FS_OFFSET = uStack_130;
  puStack_128 = &LAB_0040ef0c;
  puStack_12c = (undefined1 *)0x40ef04;
  FUN_0040fad4(DAT_0047d624);
  return;
}

