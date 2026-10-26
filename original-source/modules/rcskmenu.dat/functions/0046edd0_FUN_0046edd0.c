/*
 * FUN_0046edd0 at 0046edd0
 * undefined __register FUN_0046edd0(void)
 * Address ranges: 0046edd0-0046eea8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046edd0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  int local_14;
  undefined *local_10;
  undefined4 *local_c;
  int *local_8;
  
  puStack_24 = &stack0xfffffffc;
  puStack_30 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined *)0x0;
  local_14 = 0;
  puStack_28 = &LAB_0046eecb;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_34 = &LAB_0046eea9;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_10);
  FUN_004081c4(local_10,(int *)&local_c);
  FUN_00403dd8((int *)&local_c,(undefined4 *)"race.ini");
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  if (local_8 != (int *)0x0) {
    iVar1 = (**(code **)(*local_8 + 8))(local_8,"CHARDATA","count",0);
    if (0 < iVar1) {
      if (-1 < iVar1 + -1) {
        iVar2 = 0;
        do {
          FUN_00407f60(iVar2,&local_14);
          (**(code **)(*local_8 + 0x48))(local_8,"CHARDATA",local_14);
          iVar2 = iVar2 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      (**(code **)(*local_8 + 0xc))(local_8,"CHARDATA","count",0);
    }
  }
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0046eeb0;
  if (local_8 != (int *)0x0) {
    puStack_34 = (undefined1 *)0x46eea8;
    FUN_00402eac(local_8);
  }
  return;
}

