/*
 * FUN_0041a200 at 0041a200
 * undefined FUN_0041a200(void)
 * Address ranges: 0041a200-0041a51b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a200(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined **ppuVar6;
  int local_4;
  
  iVar2 = 0x28;
  local_4 = 0;
  FUN_00419260();
  FUN_0041a0d0();
  FUN_004b1850(0,0,0x28,&DAT_004e20c8);
  iVar1 = FUN_004b3830(0x1b);
  do {
    if (iVar1 != 0) {
      FUN_00419230(0x1b);
      return;
    }
    iVar1 = FUN_004b3830(0x26);
    if (iVar1 != 0) {
      FUN_004b1850(0,0,iVar2,&DAT_004e20cc);
      iVar2 = iVar2 + -0x14;
      local_4 = local_4 + -1;
      if (iVar2 < 0x28) {
        iVar2 = 100;
        local_4 = 3;
      }
      FUN_004b1850(0,0,iVar2,&DAT_004e20d0);
      FUN_00419230(0x26);
    }
    iVar1 = FUN_004b3830(0x28);
    if (iVar1 != 0) {
      FUN_004b1850(0,0,iVar2,&DAT_004e20d4);
      iVar2 = iVar2 + 0x14;
      local_4 = local_4 + 1;
      if (100 < iVar2) {
        iVar2 = 0x28;
        local_4 = 0;
      }
      FUN_004b1850(0,0,iVar2,&DAT_004e20d8);
      FUN_00419230(0x28);
    }
    iVar1 = FUN_004b3830(0x20);
    if (iVar1 != 0) {
      if (local_4 == 0) {
        if (DAT_0053bef0 == 0) {
          ppuVar6 = (undefined **)&DAT_004e20e0;
        }
        else {
          ppuVar6 = &PTR_DAT_004e20dc;
        }
        DAT_0053bef0 = (uint)(DAT_0053bef0 == 0);
        uVar5 = 0x28;
LAB_0041a379:
        FUN_004b1850(0,200,uVar5,ppuVar6);
      }
      else {
        if (local_4 == 1) {
          if (DAT_0053bf00 == 0) {
            ppuVar6 = (undefined **)&DAT_004e20ec;
            DAT_0053bf00 = 1;
            uVar5 = 0x3c;
          }
          else {
            ppuVar6 = &PTR_DAT_004e20e8;
            DAT_0053bf00 = 0;
            uVar5 = 0x3c;
          }
          goto LAB_0041a379;
        }
        if (local_4 == 2) {
          if (DAT_0053bef4 == 0) {
            ppuVar6 = (undefined **)&DAT_004e20f8;
            DAT_0053bef4 = 1;
            uVar5 = 0x50;
          }
          else {
            ppuVar6 = &PTR_DAT_004e20f4;
            DAT_0053bef4 = 0;
            uVar5 = 0x50;
          }
          goto LAB_0041a379;
        }
      }
      FUN_00419230(0x20);
    }
    iVar1 = FUN_004b3830(0x25);
    if (iVar1 != 0) {
      DAT_0053be2c = DAT_0053be2c + -1;
      if (DAT_0053be2c < 0) {
        DAT_0053be2c = 0;
      }
      FUN_00419230(0x25);
      FUN_004b1850(0,200,100,&DAT_004e2100,DAT_0053be2c);
    }
    iVar1 = FUN_004b3830(0x27);
    if (iVar1 != 0) {
      DAT_0053be2c = DAT_0053be2c + 1;
      if (10 < DAT_0053be2c) {
        DAT_0053be2c = 10;
      }
      FUN_00419230(0x27);
      FUN_004b1850(0,200,100,&DAT_004e2104,DAT_0053be2c);
    }
    iVar1 = FUN_004b3830(0x22);
    if (iVar1 != 0) {
      DAT_004e17d0 = DAT_004e17d0 + -1;
      if (DAT_004e17d0 < 0) {
        DAT_004e17d0 = 0;
      }
      FUN_00419230(0x22);
      FUN_004b1850(0,200,0x78,&DAT_004e2108,DAT_004e17d0);
    }
    iVar1 = FUN_004b3830(0x21);
    if (iVar1 != 0) {
      DAT_004e17d0 = DAT_004e17d0 + 1;
      if (10 < DAT_004e17d0) {
        DAT_004e17d0 = 10;
      }
      FUN_00419230(0x21);
      FUN_004b1850(0,200,0x78,&DAT_004e210c,DAT_004e17d0);
    }
    iVar1 = FUN_004b3830(0x7b);
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)(&DAT_00505b60 + DAT_0053be2c * 0xac);
      puVar4 = (undefined4 *)(&DAT_00505b60 + DAT_004e17d0 * 0xac);
      for (iVar1 = 0x2b; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    iVar1 = FUN_004b3830(0x1b);
  } while( true );
}

