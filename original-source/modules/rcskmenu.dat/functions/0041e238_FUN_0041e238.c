/*
 * FUN_0041e238 at 0041e238
 * undefined __register FUN_0041e238(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0041e238-0041e2c4;0041e2dc-0041e2e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e238(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  HICON pHVar3;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 local_e;
  int *local_8;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 0xc) == 0) {
    if (*(int *)(iVar1 + 8) == 0) {
      puStack_20 = (undefined1 *)0x41e25b;
      FUN_00418c78();
      param_3 = extraout_ECX;
    }
    puStack_20 = (undefined1 *)0x41e267;
    local_8 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',param_3);
    puStack_24 = &LAB_0041e2c5;
    uStack_28 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_28;
    puStack_20 = &stack0xfffffffc;
    iVar2 = FUN_0041e184(param_1);
    if (iVar2 == DAT_0047d694) {
      FUN_00402b54(&local_e,6,0);
      FUN_00411920(local_8,&local_e,6);
    }
    else {
      pHVar3 = (HICON)FUN_0041e184(param_1);
      FUN_00419d10(local_8,pHVar3,'\0');
    }
    *in_FS_OFFSET = uStack_28;
    *(int **)(iVar1 + 0xc) = local_8;
  }
  return;
}

