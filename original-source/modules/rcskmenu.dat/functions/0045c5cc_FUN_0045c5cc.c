/*
 * FUN_0045c5cc at 0045c5cc
 * undefined __register FUN_0045c5cc(byte param_1, byte param_2)
 * Address ranges: 0045c5cc-0045c656
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c5cc(byte param_1,byte param_2)

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
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  iStack_8 = (uint)param_2 << 0x18;
  puStack_1c = &LAB_0045c657;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_004576c0(*(int *)(DAT_0047e18c + 0x9c),param_1,param_2,(int *)&local_c);
  if (local_c != (undefined4 *)0x0) {
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
  puStack_18 = &LAB_0045c65e;
  puStack_1c = (undefined1 *)0x45c656;
  FUN_00403b74(&local_10,2);
  return;
}

