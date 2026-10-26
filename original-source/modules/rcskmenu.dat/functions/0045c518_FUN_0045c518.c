/*
 * FUN_0045c518 at 0045c518
 * undefined __register FUN_0045c518(byte param_1, byte param_2, undefined1 param_3)
 * Address ranges: 0045c518-0045c5bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c518(byte param_1,byte param_2,undefined1 param_3)

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
  uStack_8 = (uint)CONCAT11(param_2,param_3) << 0x10;
  puStack_1c = &LAB_0045c5be;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_004576c0(*(int *)(DAT_0047e18c + 0x9c),param_1,param_2,(int *)&local_c);
  if (local_c != (undefined4 *)0x0) {
    FUN_00457704(local_c,&local_10);
    FUN_00403be8((int *)&local_c,local_10);
    iVar1 = FUN_00403dd0((int)local_c);
    if (0 < iVar1) {
      if (uStack_8._2_1_ == '\0') {
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
  puStack_18 = &LAB_0045c5c5;
  puStack_1c = (undefined1 *)0x45c5bd;
  FUN_00403b74(&local_10,2);
  return;
}

