/*
 * FUN_0045c720 at 0045c720
 * undefined __register FUN_0045c720(byte param_1)
 * Address ranges: 0045c720-0045c7ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c720(byte param_1)

{
  int iVar1;
  LPCSTR pszSound;
  undefined4 *in_FS_OFFSET;
  UINT fuSound;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_10;
  undefined4 *local_c;
  undefined4 uStack_8;
  
  puStack_18 = &stack0xfffffffc;
  uStack_8 = 0;
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  puStack_1c = &LAB_0045c7ae;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_004576e8(*(int *)(DAT_0047e18c + 0x9c),param_1,(int *)&local_c);
  iVar1 = FUN_00403dd0((int)local_c);
  if (iVar1 < 1) {
    uStack_8 = CONCAT13(1,(undefined3)uStack_8);
  }
  else {
    FUN_00457704(local_c,&local_10);
    FUN_00403be8((int *)&local_c,local_10);
    iVar1 = FUN_00403dd0((int)local_c);
    if (0 < iVar1) {
      fuSound = 3;
      pszSound = FUN_00403f94((undefined *)local_c);
      sndPlaySoundA(pszSound,fuSound);
    }
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0045c7b5;
  puStack_1c = (undefined1 *)0x45c7ad;
  FUN_00403b74(&local_10,2);
  return;
}

