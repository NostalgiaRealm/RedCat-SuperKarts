/*
 * FUN_0047bb90 at 0047bb90
 * undefined FUN_0047bb90(void)
 * Address ranges: 0047bb90-0047bea7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047bb90(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 local_b1;
  undefined1 *local_b0;
  undefined4 local_ac;
  undefined1 local_a8;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_40;
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0e9a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)FUN_0047f750();
  local_ac = *puVar1;
  local_a8 = *(undefined1 *)(puVar1 + 1);
  FUN_0040b4f0(0);
  FUN_00412870(puVar1 + 1,0,0xffffffff);
  local_4 = 0;
  FUN_0042eab0(puVar1 + 5);
  local_4._0_1_ = 1;
  FUN_0042eab0(puVar1 + 9);
  local_4._0_1_ = 2;
  FUN_0042eab0(puVar1 + 0xd);
  local_68 = puVar1[0x11];
  local_64 = puVar1[0x12];
  local_4._0_1_ = 3;
  FUN_0047c4e0(puVar1 + 0x13);
  local_4._0_1_ = 4;
  FUN_0042eab0(puVar1 + 0x17);
  local_40 = puVar1[0x1b];
  local_4 = CONCAT31(local_4._1_3_,5);
  FUN_0047c6c0(puVar1 + 0x1c);
  local_1c = puVar1[0x24];
  local_18 = puVar1[0x25];
  local_14 = puVar1[0x26];
  local_10 = puVar1[0x27];
  local_4 = 6;
  puVar1 = &DAT_00544f54;
  do {
    puVar2 = (undefined1 *)*puVar1;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____effects_item___s__004f85d8,s_D__work_rcsk_Code_game_ReqSound__004f85b4,
                 0x10f,puVar2);
    iVar4 = local_38;
    while( true ) {
      if (iVar4 == local_34) {
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&local_b1,&DAT_004d9d80);
      }
      puVar2 = (undefined1 *)*puVar1;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      iVar3 = FUN_00460440(0,*(undefined4 *)(iVar4 + 8),puVar2,puVar1[1]);
      if (iVar3 == 0) break;
      iVar4 = iVar4 + 0x14;
    }
    puVar1 = puVar1 + 4;
    *(undefined1 **)(*(int *)(iVar4 + 0x10) + 0x4c) = &LAB_0047beb0;
  } while ((int)puVar1 < 0x544fa4);
  puVar1 = &DAT_00544f04;
  do {
    puVar2 = (undefined1 *)*puVar1;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____music_item___s__004f8618,s_D__work_rcsk_Code_game_ReqSound__004f85f4,
                 0x115,puVar2);
    iVar4 = local_38;
    while( true ) {
      if (iVar4 == local_34) {
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&local_b1,&DAT_004d9d80);
      }
      puVar2 = (undefined1 *)*puVar1;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      iVar3 = FUN_00460440(0,*(undefined4 *)(iVar4 + 8),puVar2,puVar1[1]);
      if (iVar3 == 0) break;
      iVar4 = iVar4 + 0x14;
    }
    puVar1 = puVar1 + 4;
    *(code **)(*(int *)(iVar4 + 0x10) + 0x4c) = FUN_0047c030;
  } while ((int)puVar1 < 0x544f54);
  local_b0 = local_3c;
  local_4._0_1_ = 0xd;
  local_4._1_3_ = 0;
  FUN_00418ec0();
  local_4._0_1_ = 0xc;
  FUN_0047c800();
  local_4._0_1_ = 0xb;
  FUN_0040b4f0(1);
  local_4._0_1_ = 10;
  FUN_0047c660();
  local_4._0_1_ = 9;
  FUN_0040b4f0(1);
  local_4._0_1_ = 8;
  FUN_0040b4f0(1);
  local_4 = CONCAT31(local_4._1_3_,7);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  ExceptionList = local_c;
  return;
}

