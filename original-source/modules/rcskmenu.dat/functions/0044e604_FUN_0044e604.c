/*
 * FUN_0044e604 at 0044e604
 * undefined __register FUN_0044e604(undefined4 * param_1, int * param_2)
 * Address ranges: 0044e604-0044e6be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e604(undefined4 *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar4;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  int local_14;
  undefined4 *local_10;
  int local_c;
  undefined4 *local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = 0;
  local_10 = (undefined4 *)0x0;
  local_14 = 0;
  puStack_28 = &LAB_0044e6bf;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  FUN_00403ba4(param_2,param_1);
  if ((DAT_0047bbfc != (undefined4 *)0x0) && (iVar2 = DAT_0047bbfc[2], -1 < iVar2 + -1)) {
    iVar3 = 0;
    do {
      pcVar1 = (code *)FUN_0040f6b0(DAT_0047bbfc,iVar3);
      (*pcVar1)(*param_2,&local_8);
      FUN_00403ba4(param_2,local_8);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_0044e4c0("IMAGEBASE",&local_c);
  if (local_c != 0) {
    ppuVar4 = &local_10;
    FUN_0044e4c0("IMAGEBASE",&local_14);
    FUN_0044e4f8((undefined4 *)*param_2,(byte *)"(IMAGEBASE)",local_14,(int *)ppuVar4);
    FUN_00403ba4(param_2,local_10);
  }
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_0044e6c6;
  puStack_28 = (undefined1 *)0x44e6be;
  FUN_00403b74(&local_14,4);
  return;
}

