/*
 * entry at 0047a500
 * undefined __register entry(void)
 * Address ranges: 0047a500-0047a5e3;0047a5ee-0047a60f;0047a617-0047a61e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void entry(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 local_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  puStack_20 = (undefined1 *)0x47a513;
  FUN_004061d4(&LAB_0047a090);
  puStack_24 = &LAB_0047a610;
  local_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_28;
  puStack_30 = &LAB_0047a5e4;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_2c = &stack0xfffffffc;
  puStack_20 = &stack0xfffffffc;
  FUN_0044e7ac(0x479d30,extraout_EDX,extraout_ECX);
  FUN_004322fc();
  FUN_00431f00(*(int *)PTR_DAT_0047c86c,(uint *)"Redcat Super Karts ");
  FUN_00403b50((int *)(*(int *)PTR_DAT_0047c86c + 0x40));
  cVar1 = FUN_00479e1c();
  if (cVar1 != '\x01') {
    FUN_00432448();
    *in_FS_OFFSET = uStack_34;
    puStack_2c = (undefined1 *)0x47a587;
    FUN_004036a4();
                    /* WARNING: Subroutine does not return */
    FUN_004039fc();
  }
  uVar2 = FUN_00432314(*(int *)PTR_DAT_0047c86c,(int)&PTR_FUN_0045bd80,
                       (undefined4 *)PTR_DAT_0047c670);
  FUN_00479fa8(uVar2,extraout_EDX_00);
  FUN_00479dcc();
  DAT_0047e5b4 = (int *)FUN_0047913c((int)&LAB_00479134,'\x01');
  FUN_00432394(*(int *)PTR_DAT_0047c86c);
  FUN_0044f2fc();
  FUN_0044e7d8(0x479d30);
  *in_FS_OFFSET = uStack_34;
  *in_FS_OFFSET = local_28;
  puStack_20 = (undefined1 *)0x47a617;
  puStack_24 = (undefined1 *)0x47a605;
  FUN_00402eac(DAT_0047e5b4);
  puStack_24 = (undefined1 *)0x47a60f;
  FUN_0044e31c(&DAT_0044e038);
  return;
}

