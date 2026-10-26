/*
 * FUN_0045c668 at 0045c668
 * undefined __register FUN_0045c668(byte param_1, byte param_2)
 * Address ranges: 0045c668-0045c710
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c668(byte param_1,byte param_2)

{
  int iVar1;
  LPCSTR pCVar2;
  undefined4 *in_FS_OFFSET;
  UINT UVar3;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_10;
  undefined4 *local_c;
  undefined4 uStack_8;
  
  puStack_18 = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  uStack_8 = (uint)param_2 << 0x18;
  puStack_1c = &LAB_0045c711;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_004576e8(*(int *)(DAT_0047e18c + 0x9c),param_1,(int *)&local_c);
  iVar1 = FUN_00403dd0((int)local_c);
  if (iVar1 < 1) {
    uStack_8._0_3_ = CONCAT12(1,(undefined2)uStack_8);
  }
  else {
    FUN_00457704(local_c,&local_10);
    FUN_00403be8((int *)&local_c,local_10);
    iVar1 = FUN_00403dd0((int)local_c);
    if (0 < iVar1) {
      if (uStack_8._3_1_ == '\0') {
        UVar3 = 3;
        pCVar2 = FUN_00403f94((undefined *)local_c);
        sndPlaySoundA(pCVar2,UVar3);
      }
      else {
        UVar3 = 2;
        pCVar2 = FUN_00403f94((undefined *)local_c);
        sndPlaySoundA(pCVar2,UVar3);
      }
    }
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0045c718;
  puStack_1c = (undefined1 *)0x45c710;
  FUN_00403b74(&local_10,2);
  return;
}

